/* Verify that name lookup of basic types including old-style bitfield types
   yields the non-bitfield.  */

#include <ctf-api.h>
#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

int bitfieldery (int count, int up, int pos)
{
  unsigned char *ctf_written;
  size_t size;
  ctf_dict_t *dict;
  const char *err = "opening";
  int open_err;
  ctf_encoding_t en;
  ctf_encoding_t basic;
  ctf_id_t type;
  size_t i;

  /* This is rendered annoying by two factors: old-style bitfields are not
     generated by current compilers, so we need to build a suitable dict by
     hand; and this is an open-time bug, so we need to serialize it and then
     load it back in again.  */

  if ((dict = ctf_create (&open_err)) == NULL)
    goto open_err;

  /* Populate with a pile of bitfields of increasing/decreasing size, with a
     single basic type dropped in at position POS.  Oscillate the offset
     between 0 and 1.  */

  basic.cte_bits = count;
  basic.cte_offset = 0;
  basic.cte_format = CTF_INT_SIGNED;

  en.cte_bits = up ? 0 : count - 1;
  en.cte_offset = 0;
  en.cte_format = CTF_INT_SIGNED;

  for (i = 0; i < count; i++)
    {
      if (i == pos)
	{
	  err = "populating with basic type";
	  if (ctf_add_integer (dict, CTF_ADD_ROOT, "int", &basic) < 0)
	    goto err;
	}

      err = "populating";
      if (ctf_add_integer (dict, CTF_ADD_ROOT, "int", &en) < 0)
	goto err;

      en.cte_bits += up ? 1 : -1;
      if (en.cte_offset == 0)
	en.cte_offset = 1;
      else
	en.cte_offset = 0;
    }

  /* Possibly populate with at-end basic type.  */
  if (i == pos)
    {
      err = "populating with basic type";
      if (ctf_add_integer (dict, CTF_ADD_ROOT, "int", &basic) < 0)
	goto err;
    }

  err = "writing";
  if ((ctf_written = ctf_write_mem (dict, &size, 4096)) == NULL)
    goto err;
  ctf_dict_close (dict);

  err = "opening";
  if ((dict = ctf_simple_open ((char *) ctf_written, size, NULL, 0,
			       0, NULL, 0, &open_err)) == NULL)
    goto open_err;

  err = "looking up";
  if ((type = ctf_lookup_by_name (dict, "int")) == CTF_ERR)
    goto err;

  err = "encoding check";
  if (ctf_type_encoding (dict, type, &en) < 0)
    goto err;

  if (en.cte_bits < count || en.cte_offset != 0)
    {
      fprintf (stderr, "Name lookup with count %i, pos %i, counting %s "
	       "gave bitfield ID %lx with bits %i, offset %i\n", count, pos,
	       up ? "up" : "down", type, en.cte_bits, en.cte_offset);
      return 1;
    }
  ctf_dict_close (dict);
  free (ctf_written);

  return 0;

 open_err:
  fprintf (stdout, "Error %s: %s\n", err, ctf_errmsg (open_err));
  return 1;

 err:
  fprintf (stdout, "Error %s: %s\n", err, ctf_errmsg (ctf_errno (dict)));
  return 1;
}

/* Do a bunch of tests with a type of a given size: up and down, basic type
   at and near the start and end, and in the middle.  */

void mass_bitfieldery (long size)
{
  size *= 8;
  bitfieldery (size, 1, 0);
  bitfieldery (size, 0, 0);
  bitfieldery (size, 1, 1);
  bitfieldery (size, 0, 1);
  bitfieldery (size, 1, size / 2);
  bitfieldery (size, 0, size / 2);
  bitfieldery (size, 1, size - 1);
  bitfieldery (size, 0, size - 1);
  bitfieldery (size, 1, size);
  bitfieldery (size, 0, size);
}

int main (void)
{
  mass_bitfieldery (sizeof (char));
  mass_bitfieldery (sizeof (short));
  mass_bitfieldery (sizeof (int));
  mass_bitfieldery (sizeof (long));
  mass_bitfieldery (sizeof (uint64_t));

  printf ("All done.\n");

  return 0;
}
