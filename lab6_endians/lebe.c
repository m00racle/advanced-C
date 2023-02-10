#include <stdio.h>
int main(){
	// define a union 
	union un {
		// create 32 bit int (4bytes)
		int val;
		// create array of 4 char (8 bit/ 1 byte each) 
		// thus total memory allocated 4 * 1 byte = 4 bytes
		char ch[4];
	};
	/* 
	 * NOTE:
	 * union use share memory allocated for val and array of char
	 * since both are total having 4 bytes of size thus they both 
	 * will share (using the same) 4 bytes memory allocation
	 *
	 * This principle will play a big role later on in the code.
	 *
	 * */
	
	// create union un type object called u
	union un u;
	int i; // i here will be used as index for iteration later on.
	
	// assign val as 0xAABBCCDD
	u.val = 0xAABBCCDD;

	// let's see how the intel memory system stored the u.val
	// remember: MSB is inside A and LSB is inside D hex
	// as memory store bytes thus MSB in AA (1 byte) and LSB in DD (1 byte)
	
	// verify the address location and shared memory allocation of union un
	printf("Address of union u = %p\n", &u);
	printf("Address of u.val   = %p\n", &u.val);
	printf("Address of u.ch    = %p\n", &u.ch);
	// NOTE: %p is placeholder for pointer address value
	
	// verify the value of u.val in the pointer address
	printf("Value at address %p = 0x%x\n", &u.val, u.val);
	printf("\nNow we want to see how the u.val is stored in memory\n");
	printf("We start from the lower memory address to the highest:\n");
	
	for (i = 0; i < 4; i++)
		printf("Value at address %p = 0x%x\n", &u.ch[i], (unsigned char)(u.ch[i]));
	return 0;
}

/* RESULTS:
[m00racle@arch1VM lab6_endians]$ ./a.out 
Address of union u = 0x7ffe8d610644
Address of u.val   = 0x7ffe8d610644
Address of u.ch    = 0x7ffe8d610644
Value at address 0x7ffe8d610644 = 0xaabbccdd

Now we want to see how the u.val is stored in memory
We start from the lower memory address to the highest:
Value at address 0x7ffe8d610644 = 0xdd
Value at address 0x7ffe8d610645 = 0xcc
Value at address 0x7ffe8d610646 = 0xbb
Value at address 0x7ffe8d610647 = 0xaa 
*/
