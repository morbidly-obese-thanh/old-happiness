# Check 64bit APX_F CCMP and CTEST instructions

 .text
_start:
	ccmpbq   {dfv=cf} $0x7b,0x123(%r8,%rax,4)
	ccmpb    {dfv=cf} %r15w,%ax
	ccmpb    {dfv=cf} 0x123(%r8,%rax,4),%r15d
	ccmpb    {dfv=of, cf} $0x7b,%r15w
	ccmpbb   {dfv=of, cf} $0x7b,0x123(%r8,%rax,4)
	ccmpbw   {dfv=of, sf, cf} $0x7b,0x123(%r8,%rax,4)
	ccmpb    {dfv=of, sf, cf} %r15,0x123(%r8,%rax,4)
	ccmpbw   {dfv=of, sf, zf, cf} $0x7b,0x123(%r8,%rax,4)
	ccmpbq   {dfv=of, sf, zf, cf} $0x7b,0x123(%r8,%rax,4)
	ccmpbl   {dfv=of, sf, zf} $0x7b,0x123(%r8,%rax,4)
	ccmpb    {dfv=of, sf, zf} %r15,0x123(%r8,%rax,4)
	ccmpbq   {dfv=of, sf} $0x7b,0x123(%r8,%rax,4)
	ccmpb    {dfv=of, sf} 0x123(%r8,%rax,4),%r8b
	ccmpbl   {dfv=of, zf, cf} $0x7b,0x123(%r8,%rax,4)
	ccmpb    {dfv=of, zf, cf} %r8b,0x123(%r8,%rax,4)
	ccmpbw   {dfv=of, zf} $0x7b,0x123(%r8,%rax,4)
	ccmpb    {dfv=of, zf} %r8b,%dl
	ccmpb    {dfv=of} %r15d,%edx
	ccmpb    {dfv=of} 0x123(%r8,%rax,4),%r15w
	ccmpb    {dfv=sf, cf} $0x7b,%r8b
	ccmpb    {dfv=sf, cf} %r15d,0x123(%r8,%rax,4)
	ccmpb    {dfv=sf, cf} 0x123(%r8,%rax,4),%r15
	ccmpb    {dfv=sf, zf, cf} $0x7b,%r15d
	ccmpb    {dfv=sf, zf, cf} 0x123(%r8,%rax,4),%r15w
	ccmpb    {dfv=sf, zf} $0x7b,%r15d
	ccmpb    {dfv=sf, zf} %r15d,0x123(%r8,%rax,4)
	ccmpbq   {dfv=sf} $0x7b,0x123(%r8,%rax,4)
	ccmpb    {dfv=sf} %r15,%r15
	ccmpb    {dfv=sf} 0x123(%r8,%rax,4),%r15
	ccmpb    {dfv=zf, cf} $0x7b,%r15
	ccmpbl   {dfv=zf, cf} $0x7b,0x123(%r8,%rax,4)
	ccmpb    {dfv=zf, cf} %r15w,0x123(%r8,%rax,4)
	ccmpb    {dfv=zf} $0x7b,%r15
	ccmpbw   {dfv=zf} $0x7b,0x123(%r8,%rax,4)
	ccmpb    {dfv=zf} %r15w,0x123(%r8,%rax,4)
	ccmpb    {dfv=} $0x7b,%r15w
	ccmpbl   {dfv=} $0x7b,0x123(%r8,%rax,4)
	ccmpb    {dfv=} 0x123(%r8,%rax,4),%r15d
	ccmpo    {dfv=of} $0x7b,%r16
	ccmpno   {dfv=of} $0x7b,%r17
	ccmpb    {dfv=of} $0x7b,%r18
	ccmpae   {dfv=of} $0x7b,%r19
	ccmpe    {dfv=of} $0x7b,%r20
	ccmpne   {dfv=of} $0x7b,%r21
	ccmpbe   {dfv=of} $0x7b,%r22
	ccmpa    {dfv=of} $0x7b,%r23
	ccmps    {dfv=of} $0x7b,%r24
	ccmpns   {dfv=of} $0x7b,%r25
	ccmpt    {dfv=of} $0x7b,%r26
	ccmpf    {dfv=of} $0x7b,%r27
	ccmpl    {dfv=of} $0x7b,%r28
	ccmpge   {dfv=of} $0x7b,%r29
	ccmple   {dfv=of} $0x7b,%r30
	ccmpg    {dfv=of} $0x7b,%r31
	ctestb   {dfv=cf} $0x7b,%r15
	ctestbw  {dfv=cf} $0x7b,0x123(%r8,%rax,4)
	ctestbb  {dfv=of, cf} $0x7b,0x123(%r8,%rax,4)
	ctestb   {dfv=of, cf} %r15,0x123(%r8,%rax,4)
	ctestbq  {dfv=of, sf, cf} $0x7b,0x123(%r8,%rax,4)
	ctestbl  {dfv=of, sf, zf, cf} $0x7b,0x123(%r8,%rax,4)
	ctestbw  {dfv=of, sf, zf} $0x7b,0x123(%r8,%rax,4)
	ctestbl  {dfv=of, sf} $0x7b,0x123(%r8,%rax,4)
	ctestb   {dfv=of, sf} %r15w,0x123(%r8,%rax,4)
	ctestbw  {dfv=of, zf, cf} $0x7b,0x123(%r8,%rax,4)
	ctestb   {dfv=of, zf, cf} 0x123(%r8,%rax,4),%r15w
	ctestbb  {dfv=of, zf} $0x7b,0x123(%r8,%rax,4)
	ctestb   {dfv=of, zf} %r15,0x123(%r8,%rax,4)
	ctestb   {dfv=of} %r15d,0x123(%r8,%rax,4)
	ctestb   {dfv=of} %r8b,0x123(%r8,%rax,4)
	ctestb   {dfv=of} 0x123(%r8,%rax,4),%r8b
	ctestbl  {dfv=sf, cf} $0x7b,0x123(%r8,%rax,4)
	ctestb   {dfv=sf, cf} %r15d,%edx
	ctestb   {dfv=sf, zf, cf} %r15d,0x123(%r8,%rax,4)
	ctestb   {dfv=sf, zf, cf} %r8b,%dl
	ctestb   {dfv=sf, zf} $0x7b,%r15w
	ctestbq  {dfv=sf, zf} $0x7b,0x123(%r8,%rax,4)
	ctestb   {dfv=sf} $0x7b,%r15d
	ctestbw  {dfv=sf} $0x7b,0x123(%r8,%rax,4)
	ctestb   {dfv=zf, cf} $0x7b,%r8b
	ctestbq  {dfv=zf, cf} $0x7b,0x123(%r8,%rax,4)
	ctestbl  {dfv=zf} $0x7b,0x123(%r8,%rax,4)
	ctestb   {dfv=zf} %r15,%r15
	ctestbq  {dfv=} $0x7b,0x123(%r8,%rax,4)
	ctestb   {dfv=} %r15w,%ax
	ctesto   {dfv=of} $0x7b,%r16
	ctestno  {dfv=of} $0x7b,%r17
	ctestb   {dfv=of} $0x7b,%r18
	ctestnb  {dfv=of} $0x7b,%r19
	ctestz   {dfv=of} $0x7b,%r20
	ctestnz  {dfv=of} $0x7b,%r21
	ctestbe  {dfv=of} $0x7b,%r22
	ctestnbe {dfv=of} $0x7b,%r23
	ctests   {dfv=of} $0x7b,%r24
	ctestns  {dfv=of} $0x7b,%r25
	ctestt   {dfv=of} $0x7b,%r26
	ctestf   {dfv=of} $0x7b,%r27
	ctestl   {dfv=of} $0x7b,%r28
	ctestnl  {dfv=of} $0x7b,%r29
	ctestle  {dfv=of} $0x7b,%r30
	ctestnle {dfv=of} $0x7b,%r31
	CTESTNLE {DFV=OF} $0x7b,%r31
	{evex} cmp %r15d,%edx
	{evex} cmp $0x7b,%r18
	{evex} cmp $0x7b,%r18b
	{evex} test %r15d,%edx
	{evex} test (%r15),%edx
	{evex} test %r15d,(%rdx)
	{evex} test $0x7b,%r18
	{evex} test $0x7b,%r18b

	.intel_syntax noprefix
	ccmpb    {dfv=cf} QWORD PTR [r8+rax*4+0x123],0x7b
	ccmpb    {dfv=cf} ax,r15w
	ccmpb    {dfv=cf} r15d,DWORD PTR [r8+rax*4+0x123]
	ccmpb    {dfv=of, cf} r15w,0x7b
	ccmpb    {dfv=of, cf} BYTE PTR [r8+rax*4+0x123],0x7b
	ccmpb    {dfv=of, sf, cf} WORD PTR [r8+rax*4+0x123],0x7b
	ccmpb    {dfv=of, sf, cf} QWORD PTR [r8+rax*4+0x123],r15
	ccmpb    {dfv=of, sf, zf, cf} WORD PTR [r8+rax*4+0x123],0x7b
	ccmpb    {dfv=of, sf, zf, cf} QWORD PTR [r8+rax*4+0x123],0x7b
	ccmpb    {dfv=of, sf, zf} DWORD PTR [r8+rax*4+0x123],0x7b
	ccmpb    {dfv=of, sf, zf} QWORD PTR [r8+rax*4+0x123],r15
	ccmpb    {dfv=of, sf} QWORD PTR [r8+rax*4+0x123],0x7b
	ccmpb    {dfv=of, sf} r8b,BYTE PTR [r8+rax*4+0x123]
	ccmpb    {dfv=of, zf, cf} DWORD PTR [r8+rax*4+0x123],0x7b
	ccmpb    {dfv=of, zf, cf} BYTE PTR [r8+rax*4+0x123],r8b
	ccmpb    {dfv=of, zf} WORD PTR [r8+rax*4+0x123],0x7b
	ccmpb    {dfv=of, zf} dl,r8b
	ccmpb    {dfv=of} edx,r15d
	ccmpb    {dfv=of} r15w,WORD PTR [r8+rax*4+0x123]
	ccmpb    {dfv=sf, cf} r8b,0x7b
	ccmpb    {dfv=sf, cf} DWORD PTR [r8+rax*4+0x123],r15d
	ccmpb    {dfv=sf, cf} r15,QWORD PTR [r8+rax*4+0x123]
	ccmpb    {dfv=sf, zf, cf} r15d,0x7b
	ccmpb    {dfv=sf, zf, cf} r15w,WORD PTR [r8+rax*4+0x123]
	ccmpb    {dfv=sf, zf} r15d,0x7b
	ccmpb    {dfv=sf, zf} DWORD PTR [r8+rax*4+0x123],r15d
	ccmpb    {dfv=sf} QWORD PTR [r8+rax*4+0x123],0x7b
	ccmpb    {dfv=sf} r15,r15
	ccmpb    {dfv=sf} r15,QWORD PTR [r8+rax*4+0x123]
	ccmpb    {dfv=zf, cf} r15,0x7b
	ccmpb    {dfv=zf, cf} DWORD PTR [r8+rax*4+0x123],0x7b
	ccmpb    {dfv=zf, cf} WORD PTR [r8+rax*4+0x123],r15w
	ccmpb    {dfv=zf} r15,0x7b
	ccmpb    {dfv=zf} WORD PTR [r8+rax*4+0x123],0x7b
	ccmpb    {dfv=zf} WORD PTR [r8+rax*4+0x123],r15w
	ccmpb    {dfv=} r15w,0x7b
	ccmpb    {dfv=} DWORD PTR [r8+rax*4+0x123],0x7b
	ccmpb    {dfv=} r15d,DWORD PTR [r8+rax*4+0x123]
	ccmpo    {dfv=of} r16,0x7b
	ccmpno   {dfv=of} r17,0x7b
	ccmpb    {dfv=of} r18,0x7b
	ccmpae   {dfv=of} r19,0x7b
	ccmpe    {dfv=of} r20,0x7b
	ccmpne   {dfv=of} r21,0x7b
	ccmpbe   {dfv=of} r22,0x7b
	ccmpa    {dfv=of} r23,0x7b
	ccmps    {dfv=of} r24,0x7b
	ccmpns   {dfv=of} r25,0x7b
	ccmpt    {dfv=of} r26,0x7b
	ccmpf    {dfv=of} r27,0x7b
	ccmpl    {dfv=of} r28,0x7b
	ccmpge   {dfv=of} r29,0x7b
	ccmple   {dfv=of} r30,0x7b
	ccmpg    {dfv=of} r31,0x7b
	ctestb   {dfv=cf} r15,0x7b
	ctestb   {dfv=cf} WORD PTR [r8+rax*4+0x123],0x7b
	ctestb   {dfv=of, cf} BYTE PTR [r8+rax*4+0x123],0x7b
	ctestb   {dfv=of, cf} QWORD PTR [r8+rax*4+0x123],r15
	ctestb   {dfv=of, sf, cf} QWORD PTR [r8+rax*4+0x123],0x7b
	ctestb   {dfv=of, sf, zf, cf} DWORD PTR [r8+rax*4+0x123],0x7b
	ctestb   {dfv=of, sf, zf} WORD PTR [r8+rax*4+0x123],0x7b
	ctestb   {dfv=of, sf} DWORD PTR [r8+rax*4+0x123],0x7b
	ctestb   {dfv=of, sf} WORD PTR [r8+rax*4+0x123],r15w
	ctestb   {dfv=of, zf, cf} WORD PTR [r8+rax*4+0x123],0x7b
	ctestb   {dfv=of, zf, cf} WORD PTR [r8+rax*4+0x123],r15w
	ctestb   {dfv=of, zf} BYTE PTR [r8+rax*4+0x123],0x7b
	ctestb   {dfv=of, zf} QWORD PTR [r8+rax*4+0x123],r15
	ctestb   {dfv=of} DWORD PTR [r8+rax*4+0x123],r15d
	ctestb   {dfv=of} BYTE PTR [r8+rax*4+0x123],r8b
	ctestb   {dfv=sf, cf} DWORD PTR [r8+rax*4+0x123],0x7b
	ctestb   {dfv=sf, cf} edx,r15d
	ctestb   {dfv=sf, zf, cf} DWORD PTR [r8+rax*4+0x123],r15d
	ctestb   {dfv=sf, zf, cf} dl,r8b
	ctestb   {dfv=sf, zf} r15w,0x7b
	ctestb   {dfv=sf, zf} QWORD PTR [r8+rax*4+0x123],0x7b
	ctestb   {dfv=sf} r15d,0x7b
	ctestb   {dfv=sf} WORD PTR [r8+rax*4+0x123],0x7b
	ctestb   {dfv=zf, cf} r8b,0x7b
	ctestb   {dfv=zf, cf} QWORD PTR [r8+rax*4+0x123],0x7b
	ctestb   {dfv=zf} DWORD PTR [r8+rax*4+0x123],0x7b
	ctestb   {dfv=zf} r15,r15
	ctestb   {dfv=} QWORD PTR [r8+rax*4+0x123],0x7b
	ctestb   {dfv=} ax,r15w
	ctesto   {dfv=of} r16,0x7b
	ctestno  {dfv=of} r17,0x7b
	ctestb   {dfv=of} r18,0x7b
	ctestnb  {dfv=of} r19,0x7b
	ctestz   {dfv=of} r20,0x7b
	ctestnz  {dfv=of} r21,0x7b
	ctestbe  {dfv=of} r22,0x7b
	ctestnbe {dfv=of} r23,0x7b
	ctests   {dfv=of} r24,0x7b
	ctestns  {dfv=of} r25,0x7b
	ctestt   {dfv=of} r26,0x7b
	ctestf   {dfv=of} r27,0x7b
	ctestl   {dfv=of} r28,0x7b
	ctestnl  {dfv=of} r29,0x7b
	ctestle  {dfv=of} r30,0x7b
	ctestnle {dfv=of} r31,0x7b
        CTESTNLE {DFV=OF} r31,0x7b
	{evex} cmp  edx, r15d
	{evex} cmp  r18, 0x7b
	{evex} cmp  r18b, 0x7b
	{evex} test  edx, r15d
	{evex} test  r18, 0x7b
	{evex} test  r18b, 0x7b
