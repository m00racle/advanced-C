/* 
 *This is the lab 2 exercise 

 * */
#include <stdio.h>
int main()
{
/* 
 * The main purpose is to print the size of various data types
 * for 64 bit and 32 bit platform
 * Unofortunately I don't have access to 32 bit platform at this moment
 * */

	char c, *cp;
	short s, *sp;
	int i, *ip;
	long l, *lp;
	long long ll, *llp;
	float f;
	double df;

	//void v, *vp;
	//void *vp
	// un-comment these lines if wish to run the code
	
	printf("size of c = %d, %d\n", sizeof(char), sizeof(c));
	printf("size of cp = %d, %d\n", sizeof(*cp), sizeof(cp));
}
