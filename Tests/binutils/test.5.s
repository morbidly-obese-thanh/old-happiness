.text

my_func:
	r1 = r2;

	r2 = port32[r3];
	port32[r3] = r11;

	r11 = r12 + r13;

	jump(r20);
	jrel(r20);

	jump(my_func);
	jrel(my_func);
