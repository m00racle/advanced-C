/*This is lab 3: 
 * Byte and Bits 
 *
 * How Bynary data type stored in memory
 * */

#include <stdio.h>

int main()
{
	char c;
	int i;

	// print c in decimal int placehoder
	printf("----------------------------------------\n");
	printf("case: input positive NOT OVERFLOW output positive\n");
	printf("c char = 82, displayed value c = %d\n", c = 82);
	printf("c char = 82, hex value c = 0x%x\n", c);
	printf("i int = 82, hex value of i int = 0x%x\n", i = 82);
	printf("----------------------------------------\n");
	printf("case: input negative NOT OVERFLOW output negative\n");
	printf("c char = -82, displayed value c = %d\n", c = -82);
	printf("c char = -82, hex value c = 0x%x\n", c);
	printf("i int = -82, hex value of i int = 0x%x\n", i = -82);
	printf("----------------------------------------\n");
	printf("case: input positive OVERFLOW output negative\n");
	printf("c char = 682, displayed value c = %d\n", c = 682);
	printf("c char = 682, hex value c = 0x%x\n", c);
	printf("i int = 682, hex value of i int = 0x%x\n", i = 682);
	printf("----------------------------------------\n");
	printf("case: input negative OVERFLOW output positive\n");
	printf("c char = -682, displayed value c = %d\n", c = -682);
	printf("c char = -682, hex value c = 0x%x\n", c);
	printf("i int = -682, hex value of i int = 0x%x\n", i = -682);
	printf("----------------------------------------\n");
	printf("case: input positive OVERFLOW output positive\n");
	printf("c char = 341, displayed value c = %d\n", c = 341);
	printf("c char = 341, hex value c = 0x%x\n", c);
	printf("i int = 341, hex value of i int = 0x%x\n", i = 341);
	printf("----------------------------------------\n");
	printf("case: input negative OVERFLOW output negative\n");
	printf("c char = -341, displayed value c = %d\n", c = -341);
	printf("c char = -341, hex value c = 0x%x\n", c);
	printf("i int = -341, hex value of i int = 0x%x\n", i = -341);
	printf("----------------------------------------\n");
	printf("case: special case of 1111 1111 = 255\n");
	printf("c char = 255, displayed value c = %d\n", c = 255);
	printf("c char = 255, hex value c = 0x%x\n", c);
	printf("i int = 255, hex value of i int = 0x%x\n", i = 255);
	printf("----------------------------------------\n");
	printf("case: special case of inverse 0000 0001 = -255\n");
	printf("c char = -255, displayed value c = %d\n", c = -255);
	printf("c char = -255, hex value c = 0x%x\n", c);
	printf("i int = -255, hex value of i int = 0x%x\n", i = -255);
	printf("----------------------------------------\n");
	printf("case: special case of 0001 0000 0000 = 256\n");
	printf("c char = 256, displayed value c = %d\n", c = 256);
	printf("c char = 256, hex value c = 0x%x\n", c);
	printf("i int = 256, hex value of i int = 0x%x\n", i = 256);
	printf("----------------------------------------\n");
	printf("case: special case of inverse 0001 0000 0000 = -256\n");
	printf("c char = -256, displayed value c = %d\n", c = -256);
	printf("c char = -256, hex value c = 0x%x\n", c);
	printf("i int = -256, hex value of i int = 0x%x\n", i = -256);
	printf("----------------------------------------\n");
	printf("case: special case of 0000 1000 0000 = 128\n");
	printf("c char = 128, displayed value c = %d\n", c = 128);
	printf("c char = 128, hex value c = 0x%x\n", c);
	printf("i int = 128, hex value of i int = 0x%x\n", i = 128);
	printf("----------------------------------------\n");
	printf("case: special case of inverse 1111 1000 0000 = -128\n");
	printf("c char = -128, displayed value c = %d\n", c = -128);
	printf("c char = -128, hex value c = 0x%x\n", c);
	printf("i int = -128, hex value of i int = 0x%x\n", i = -128);
	printf("----------------------------------------\n");

	return 0;
}
