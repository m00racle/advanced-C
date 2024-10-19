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
	printf("size of each variable declaration (in byte(s):\n");
	
	// NOTE: the (int) in each printf are type casting to ensure no warning when compiled
	// casting requried because although sizeof function should return int but it is not 
	// defined yet thus it needs to be casted as guarantee when using the type placeholder %d
	// which is used to process as string placeholder for type int
	
	printf("char data type = %d, char type variable c = %d\n", (int) sizeof(char), (int) sizeof(c));
	printf("char in address de-referenced *cp = %d, pointer cp = %d\n", (int) sizeof(*cp), (int) sizeof(cp));

	printf("size of s = %d, %d\n", (int) sizeof(short), (int) sizeof(s));
	printf("size of sp = %d, %d\n", (int) sizeof(*sp), (int) sizeof(sp));
	printf("short data type = %d, short type variable s = %d\n", (int) sizeof(short), (int) sizeof(s));

	printf("size of i = %d, %d\n", (int) sizeof(int), (int) sizeof(i));
	printf("size of ip = %d, %d\n", (int) sizeof(*ip), (int) sizeof(ip));

	printf("size of l = %d, %d\n", (int) sizeof(long), (int) sizeof(l));
	printf("size of lp = %d, %d\n", (int) sizeof(*lp), (int) sizeof(lp));

	printf("size of ll = %d, %d\n", (int) sizeof(long long), (int) sizeof(ll));
	printf("size of llp = %d, %d\n", (int) sizeof(*llp), (int) sizeof(llp));
	
	printf("size of f = %d, %d\n", (int) sizeof(float), (int) sizeof(f));
	printf("size of fp = %d, %d\n", (int) sizeof(*fp), (int) sizeof(fp));

	printf("size of df = %d, %d\n", (int) sizeof(double), (int) sizeof(df));
	printf("size of dfp = %d, %d\n", (int) sizeof(*dfp), (int) sizeof(dfp));

	printf("size of 100 = %d\n", (int) sizeof(100));

	printf("size of 0xFFFFFFFF = %d\n", (int) sizeof(0xFFFFFFFF));

	printf("size of 0xFFFFFFFFFF = %d\n", (int) sizeof(0xFFFFFFFFFF));

//	WARNING: These code when un-commented will invoke compiler error:
//	printf("size of v = %d, %d\n", sizeof(void), sizeof(v));
//	printf("size of vp = %d\n", sizeof(vp));

}
