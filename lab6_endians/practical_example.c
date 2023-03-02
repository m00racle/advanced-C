#include <stdio.h>

int main() {
	union un {
		int val;
		char ch[4];
		// allocate memory for 4 char (8 bit each)
	};

	union un u;
	int i;

	u.val = 0xA1B2C3D4;
	
	printf("Address (start) of union un u = %p\n", &u);
	printf("Address (start) of int u.val  = %p\n", &u.val);
	printf("Address (start) of char u.ch  = %p\n", &u.ch);
	
	printf("\nNow we are going to find out how the u.val is stored in memory\n");
	printf("Value at (start) address %p of u.val = 0x%x\n", &u.val, u.val);
	printf("\nNow let see from address to address how the u.val is stored\n");
	
	for (i = 0 ; i < 4; i++)
		printf("Value at address %p = 0x%x\n", &u.ch[i], (unsigned char)(u.ch[i]));
}

/*RESULT:
[m00racle@archAdvC lab6_endians]$ ./a.out
Address (start) of union un u = 0x7ffcbf37e864
Address (start) of int u.val  = 0x7ffcbf37e864
Address (start) of char u.ch  = 0x7ffcbf37e864

Now we are going to find out how the u.val is stored in memory
Value at (start) address 0x7ffcbf37e864 of u.val = 0xa1b2c3d4

Now let see from address to address how the u.val is stored
Value at address 0x7ffcbf37e864 = 0xd4
Value at address 0x7ffcbf37e865 = 0xc3
Value at address 0x7ffcbf37e866 = 0xb2
Value at address 0x7ffcbf37e867 = 0xa1
*/
