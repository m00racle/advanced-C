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
	printf("c = 255, displayed value c = %d\n", c = 255);
	printf("c = 255, hex value c = %x\n", c);
	printf("c = 511, display value c = %d\n", c = 511);
	printf("c = 511, hex value c = %x\n", c);
	printf("c = -1 , hex value c = %x\n", c = -1);
	printf("c = 128, displayed value c = %d\n", c = 128);
	printf("c = 128, hex value c = %x\n", c);
	printf("c = 384, displayed value c = %d\n", c = 384);
	printf("c = 384, hex value c = %x\n", c);
	printf("c = -128, hex value c = %x\n", c = -128);
	printf("c = 256, displayed value c = %d\n", c = 256);
	printf("c = 256, hex value c = %x\n", c);
	printf("c = 512, display value c = %d\n", c = 512);
	printf("c = 512, hex value c = %x\n", c);
	printf("c = 0, hex value c = %x\n", c = 0);

	printf("i = -2 , displayed value i = %x\n", i = -2);
	printf("i = 256, displayed value i = %x\n", i = 256);
	printf("i =-256, displayed value i = %x\n", i = -256);

	return 0;
}
