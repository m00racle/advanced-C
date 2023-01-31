#include<stdio.h>

// declare all other functions:
void unsigned_short_min_method1(void);
void unsigned_short_min_method2(void);
void unsigned_short_min_method3(void);
void unsigned_short_min_method4(void);

// start with the main

int main()
{
	// just call each method to see how they works finding results
	unsigned_short_min_method1();
	unsigned_short_min_method2();
	unsigned_short_min_method3();
	unsigned_short_min_method4();
}

// define each declared function here:
void unsigned_short_min_method1(void)
{
	unsigned short s;
	unsigned short tmp;

	// initiate s as 0 and tmp always - 1 from s
	// when finally s is overflowing then we know we get the min value
	// when s is overflow all bits are 0000 0000 0000 0000 when it is subtract 1 it will overflow
	// and value s will be very high (some use 1111 1111 1111 1111) to represent
	s = 0; //always best value to start
	tmp = s + 1;

	while (s < tmp){
		s--;
		tmp--;
	}
	printf("Method1: Min value for unsigned short data-type: %d\n", tmp);
}

void unsigned_short_min_method2(void){
	// improvement : we don't need to decrement the s and tmp inside the while loop
	// we can decrement them within the while statement:
	unsigned short s;
	unsigned short tmp;

	s = 0;
	tmp = s + 1;
	while(--s < --tmp);
	// --s means decrement first then compare it with --tmp
	printf("Method2: Min value for unsigned short data-type: %d\n", tmp);
}

void unsigned_short_min_method3(void){
	// improvement: we don't need tmp
	// Because when overflowed s is becoming very big compared to previous value 
	// often it is represented as +max since when it comes to 0000 0000 0000 0000 - 0000 0000 0000 0001 = 1111 1111 1111 1111
	// thus it will make the max value is increment (one time) before s it overflown
	unsigned short s;

	s = 0;

	while (--s < 0);
	++s; // decrement s one time once it overflown will get you the max value of the data type
	printf("Method3: Min value for unsigned short data-type: %d\n", s);
}

void unsigned_short_min_method4(void){
	// improvement: (semi) hardcoded the min number?
	// Well not really. We can just put the representation on what min value is:
	// as 16 bit (unsigned) min value = 0000 0000 0000 0000
	// But C programming don't have bit representation to assign to variable
	// But C programming have HEX representation thus:
	// 16 bit (unsigned) min = 0000 0000 0000 0000 = 0x0000
	short s;

	// assign the HEX Into s variable:
	s = 0x0000;
	// print it in decimal format:
	printf("Method4: Min value for unsigned short data-type: %d\n", s);
	
}
