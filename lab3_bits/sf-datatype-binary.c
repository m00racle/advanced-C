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
	printf("c char = 255, displayed value c = %d\n", c = 255);
	printf("c char = 255, hex value c = 0x%x\n", c);
	printf("i int = 255, hex value of i int = 0x%x\n", i = 255);
	printf("c char = 511, display value c = %d\n", c = 511);
	printf("c char = 511, hex value c = 0x%x\n", c);
	printf("i int = 511, hex value of i int = 0x%x\n", i = 511);
	printf("c char = -1 , hex value c = 0x%x\n", c = -1);
	printf("i int = -1, hex value i int = 0x%x\n", i = -1);
	printf("-----------------------------------------------\n");
	printf("c char = 128, displayed value c = %d\n", c = 128);
	printf("c char = 128, hex value c = 0x%x\n", c);
	printf("i int = 128, hex value i int = 0x%x\n", i = 128);
	printf("c char = 384, displayed value c = %d\n", c = 384);
	printf("c char = 384, hex value c = 0x%x\n", c);
	printf("i int = 384, hex value i int = 0x%x\n", i = 384);
	printf("c char = -128, hex value c = 0x%x\n", c = -128);
	printf("i int = -128, hex value i int = 0x%x\n", i = -128);
	printf("-----------------------------------------------\n");
	printf("c char = 256, displayed value c = %d\n", c = 256);
	printf("c char = 256, hex value c = 0x%x\n", c);
	printf("i int = 256, hex value i int = 0x%x\n", i = 256);
	printf("c char = 512, display value c = %d\n", c = 512);
	printf("c char = 512, hex value c = 0x%x\n", c);
	printf("i int = 512, hex value i int = 0x%x\n", i = 512);
	printf("c char = 0, hex value c = 0x%x\n", c = 0);
	printf("i int = 0, hex value i int = 0x%x\n", i = 0);
	printf("-----------------------------------------------\n");
	printf("Focus on this proof to explain:\n-------------------------------\n");
	printf("c char = 341, display value c = %d\n", c = 341);
	printf("c char = 341, hex value c = 0x%x\n", c);
	printf("i int = 341, hex value i int = x%x\n", i = 341);
	printf("c char = 170, display value c = %d\n", c = 170);
	printf("c char = 170, hex value c = 0x%x\n", c);
	printf("i int = 170, hex value i int = x%x\n", i = 170);
	printf("c char = 682, display value c = %d\n", c = 682);
	printf("c char = 682, hex value c = 0x%x\n", c);
	printf("i int = 682, hex value i int = x%x\n", i = 682);
	printf("c char = -255, display value c = %d\n", c = -255);
	printf("c char = -255, hex value c = 0x%x\n", c);
	printf("i int = -255, hex value i int = x%x\n", i = -255);

	return 0;
}
