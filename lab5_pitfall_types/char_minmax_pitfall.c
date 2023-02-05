#include <stdio.h>

int main() {
	char c1 = 'a', c2 = 'b', c;
	// I declare 3 char type objects and only define two of them
	c = c1 + c2;
	if (c > 'c') 
		printf("True\n");
	else
		printf("False\n");

	return 0;	
}

/*
 *This should return False 
 * */
