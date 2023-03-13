#include<stdio.h>

int main() {
	union sf_un {
		short val;
		char ch[2];
	};

	union sf_un u;
	int i;

	u.val = 258;
		

	printf("the union val: %d\n", u.val);
	printf("the union ch : %d\n", u.ch[0]);

	printf("start of the u.val address: %p\n", &u.val);
	
	
	for (i=0; i<2; i++) {
		printf("address %p value: 0x%x\n", &u.ch[i], (unsigned char)(u.ch[i]));
	}
	
	// test put value to u.ch
	u.ch[0] = 1;
	
	printf("the union val: %d\n", u.val);
	printf("the union ch : %d\n", u.ch[0]);

	printf("start of the u.val address: %p\n", &u.val);
	
	for (i=0; i<2; i++) {
		printf("address %p value: 0x%x\n", &u.ch[i], (unsigned char)(u.ch[i]));
	}
	
}
