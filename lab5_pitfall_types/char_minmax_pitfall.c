#include <stdio.h>

int main() {
	char c1 = 'a', c2 = 'b', c;
	unsigned char d1 = 'a', d2 = 'b' , d;
	// I declare 3 char type objects and only define two of them
	c = c1 + c2;
	// now we compare with unsigned char
	d = d1 + d2;
	printf("the character of d = %c\n", d);
	printf("the int value of d = %d\n", d);
	printf("the character of c = %c\n", c);
	printf("the int value of c = %d\n", c);
	printf("is c is bigger than character c? ");
	if (c > 'c') 
		printf("True\n");
	else
		printf("False\n");

	return 0;	
}

/*
 * This should return False 
 *
 * This is because a in ASCII is 97 and B in ASCII is 98
 * thus when a + b is added it will result 195
 * meahwhile char max (signed) value is 128 thus 195 is overflow
 * thus most likely it will switch sign bit.
 *
 * To prove I added two more code lines
 * print the c value in char, int,
 *
 * also as comparison I also use unsigned char data type d
 *
 * But both result unknown ASCII char which denoted with ?
 * inside a diamond shaped object.
 *
 * However, the int rep is correct d = 195 and c = -61
 * */
