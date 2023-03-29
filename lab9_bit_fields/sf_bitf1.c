#include<stdio.h>

// make the struct here first

struct stchar {
	unsigned char f1:1, res1:1, f2:2, res2:1, f3:3;

};

// make proof of bit field characteristics

int main() {
	struct stchar sch;
	sch.f1 = 1;
	sch.f2 = 2;
	sch.f3 = 6;

	// let's test
	printf("testing stchar sch:\n");
	printf("address of struct sch : %p\n", &sch);
	printf("=========================\n");
	printf("pointer value f1  : %p\n", sch.f1);
	printf("pointer value res1: %p\n", sch.res1);
	printf("pointer value f2  : %p\n", sch.f2);
	printf("pointer value res2: %p\n", sch.res2);
	printf("pointer value f3  : %p\n", sch.f3);
	printf("=========================\n");
	printf("hex value f1  : %x\n", sch.f1);
	printf("hex value res1: %x\n", sch.res1);
	printf("hex value f2  : %x\n", sch.f2);
	printf("hex value res2: %x\n", sch.res2);
	printf("hex value f3  : %x\n", sch.f3);
	printf("=========================\n");
	printf("num value f1  : %d\n", sch.f1);
	printf("num value res1: %d\n", sch.res1);
	printf("num value f2  : %d\n", sch.f2);
	printf("num value res2: %d\n", sch.res2);
	printf("num value f3  : %d\n", sch.f3);
}
