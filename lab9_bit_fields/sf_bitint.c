#include <stdio.h>

struct stint {
	unsigned int f1:2, res1:6, f2:2, res2:6;
	unsigned int f3:12, res3:9;
};

int main() {
	struct stint sti;
	sti.f1 = 3;
	sti.f2 = 1;
	sti.f3 = 4095;
	unsigned char z;
	z = 8;

	printf("testing stint sti: \n");
	printf("======================\n");
	printf("address of struct sti: %p \n", &sti);
	printf("address of z char: %p \n", &z);
	printf("hex value of struct sti: %x \n", sti);
	printf("hex value of z: %x \n", z);
}
