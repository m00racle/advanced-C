#include<stdio.h>
// I want to make bitfield inside a union
union unif {
	unsigned char c1:3;
    unsigned short s1:2;
};

int main() {
    union unif uno;
    uno.s1 = 3;
    printf("address of the  uno: %p\n", &uno);
    printf("address of the s1: %p\n", uno.s1);
    printf("hex value of the s1: %x\n", uno.s1);
    printf("hex value of the uno: %x\n", uno);
    printf("decimal value of the s1: %d\n", uno.s1);
    printf("decimal value of the uno: %d\n", uno);

    // add the uno.c1 (unsigned char)
    uno.c1 = 6;

    printf("address of the  uno: %p\n", &uno);
    printf("address of the s1: %p\n", uno.s1);
    printf("address of the c1: %p\n", uno.c1);
    printf("hex value of the s1: %x\n", uno.s1);
    printf("hex value of the c1: %x\n", uno.c1);
    printf("hex value of the uno: %x\n", uno);
    printf("decimal value of the s1: %d\n", uno.s1);
    printf("decimal value of the c1: %d\n", uno.c1);
    printf("decimal value of the uno: %d\n", uno);
}
