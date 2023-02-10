#include <stdio.h>

/* 
 * NOTE:
 * This demo some pitfall on using Union
 *
 * Union uses shared memory allocated into Union
 * Thus the objects (data type) in the Union will overwrite 
 * The previously defined data type in Union
 * */

int main() {
	union un {
		short val; //short is 16 bit = 2 byte data type
		char ch; // char is 8 bit = 1 byte data type
	};

	// create union un object called u;
	union un u;

	// now define u.val = 259;
	u.val = 257;
	// verify the u.val is 259
	printf("u.val before ch definition = %d\n", u.val);

	// now we define ch
	u.ch = 1;

	printf("u.val after ch definition = %d\n", u.val);
	printf("u.ch value = %d\n", u.ch);

	return 0;
}

/* RESULT:
WITH u.val = 259
u.val before ch definition = 259
u.val after ch definition = 257
u.ch value = 1

WITH u.val = 257
u.val before ch definition = 257
u.val after ch definition = 257
u.ch value = 1
*/
