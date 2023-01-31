#include<stdio.h>

// declare all other functions:
void unsigned_short_max_method1(void);
void unsigned_short_max_method2(void);
void unsigned_short_max_method3(void);
void unsigned_short_max_method4(void);

// start with the main

int main()
{
	// just call each method to see how they works finding results
	unsigned_short_max_method1();
	unsigned_short_max_method2();
	unsigned_short_max_method3();
	unsigned_short_max_method4();
}

// define each declared function here:
void unsigned_short_max_method1(void)
{
	unsigned short s;
	// short is treated and processed as signed short datatype
	unsigned short tmp;

	// initiate s as 0 and tmp always -1 from s
	// when finally s is overflowing then we know we get the max value
	// when s is overflow all bits are 0111 1111 1111 1111 when it is add 1 it will overflow
	// and value s will be very low (some use 0000 0000 0000 0000) to represent
	s = 0;
	tmp = s - 1;

	while (s > tmp){
		s++;
		tmp++;
	}
	printf("Method1: Max value for unsigned short data-type: %d\n", tmp);
}

void unsigned_short_max_method2(void){
	// improvement : we don't need to increment the s and tmp inside the while loop
	// we can increment them within the while statement:
	unsigned short s;
	unsigned short tmp;

	s = 0;
	tmp = s - 1;
	while(++s > ++tmp);
	// ++s means increment first then compare it with ++tmp
	printf("Method2: Max value for unsigned short data-type: %d\n", tmp);
}

void unsigned_short_max_method3(void){
	// improvement: we don't need tmp
	// Because when overflowed s is becoming very small 
	// often it is represented as -min since when it comes to 0111 1111 1111 1111 + 0000 0000 0000 0001 = 1000 0000 0000 0000
	// thus it will make the max value is decrement (one time) before s it overflown
	unsigned short s;

	s = 0;

	while (++s > 0);
	--s; // decrement s one time once it overflown will get you the max value of the data type
	printf("Method3: Max value for unsigned short data-type: %d\n", s);
}

void unsigned_short_max_method4(void){
	// improvement: (semi) hardcoded the max number?
	// Well not really. We can just put the representation on what max value is:
	// as 16 bit (unsigned) max value = 1111 1111 1111 1111
	// But C programming don't have bit representation to assign to variable
	// But C programming have HEX representation thus:
	// 16 bit (unsigned) max = 1111 1111 1111 1111 = 0xFFFF
	unsigned short s;

	// assign the HEX Into s variable:
	s = 0xFFFF;
	// print it in decimal format:
	printf("Method4: Max value for unsigned short data-type: %d\n", s);
	
}
