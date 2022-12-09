/* 
 *This is the lab 2 exercise 

 * */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
	float f, *fp;
	double df, *dfp;

//	WARNING: uncomment this void declaration will invoke compiler error!
//	void v, *vp;
	
	// un-comment these lines if wish to run the code
	
	printf("size of c = %d, %d\n", sizeof(char), sizeof(c));
	printf("size of cp = %d, %d\n", sizeof(*cp), sizeof(cp));

	printf("size of s = %d, %d\n", sizeof(short), sizeof(s));
	printf("size of sp = %d, %d\n", sizeof(*sp), sizeof(sp));

	printf("size of i = %d, %d\n", sizeof(int), sizeof(i));
	printf("size of ip = %d, %d\n", sizeof(*ip), sizeof(ip));

	printf("size of l = %d, %d\n", sizeof(long), sizeof(l));
	printf("size of lp = %d, %d\n", sizeof(*lp), sizeof(lp));

	printf("size of ll = %d, %d\n", sizeof(long long), sizeof(ll));
	printf("size of llp = %d, %d\n", sizeof(*llp), sizeof(llp));
	
	printf("size of f = %d, %d\n", sizeof(float), sizeof(f));
	printf("size of fp = %d, %d\n", sizeof(*fp), sizeof(fp));

	printf("size of df = %d, %d\n", sizeof(double), sizeof(df));
	printf("size of dfp = %d, %d\n", sizeof(*dfp), sizeof(dfp));

//	WARNING: These code when un-commented will invoke compiler error:
//	printf("size of v = %d, %d\n", sizeof(void), sizeof(v));
//	printf("size of vp = %d\n", sizeof(vp));

}
