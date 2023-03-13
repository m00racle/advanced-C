#include<stdio.h>

int main() {
	union sf_un {
		short val;
		char ch;
	};

	union sf_un u;

	u.val = 258;
	u.ch = 1;
	printf("the union val: %d\n", u.val);
	printf("the union ch : %d\n", u.ch);
}
