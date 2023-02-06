#include <stdio.h>

/*
 * this is the case to show the limitation 
 * of data represented in limited byte size
 * of int (32 bit) data type.
 * */

int main() {
	int x = 4 * 1024;
	unsigned int y = 4 * 1024 * 1024 * 1024 - 1;
	// this x means 4 kbits
	//
	
	x = x * 1024 * 1024;
	// this eleviate x from 4 kb to 4gb
	// b in bits not bytes
	//y = x;
	
	printf("the int of x = %d\n", x);
	printf("the int of y = %d\n", y);
	printf("does x bigger than 0? ");

	if (x > 0)
		printf("True\n");
	else
		printf("False\n");
}

/*
 * The result
 * the int of x = 0
 * does x bigger than 0? False
 *
 * Meaning the 4 giga bits is already causing overflow
 * This is because data type used is int 
 * meaning this is treated as signed int 
 * 
 * number of bits is 32 but since this is signed bit 
 * then the MSB is allocated as sign bit
 * then the largest value can be represented is 2 gb.
 *
 * Now let's add another line code to proof
 * The unsigend y is set as 4 * 1024 * 1024 * 1024 - 1
 *
 * but this also resulting the -1 and overflow warning since this unsigned 
 * has already pass its treshold of 4 gb thus the overflow is happening before - 1
 * */
