#include <stdio.h>
#include <stdbool.h>
#include <string.h>

/* This file is to demonstrate the use of flags 
 * just like when we want to use linux command 
 * many of them are having - flag
 * We want to make simpler but similar thing
 * according to what -flag you put -o will print flag_o 
 * and -p will print flag_p
 * */
// declare all functions other than main:
void flag_o();
void flag_f();

int main(int argc, char *argv[]) {
    // declare boolean flag = false
    bool flag_status = false;
    int i = 0;

    // test argc :
    printf("number of arguments: %d\n", argc);

    if (argc > 1) {

        for (i = 1 ; i < argc ; i++) {
            printf("\nargument: %s\n", argv[i]);
            if (strcmp(argv[i], "-o") == 0) {
                // call function flag_o();
                flag_o();
            }

            if (strcmp(argv[i], "-f") == 0) {
                // call function flag_f()
                flag_f();
            }
        }
    }
    return 0;
}

void flag_o() {
	// the example of single dash of flag calls
    printf("\nactivate flag o\n");
}

void flag_f() {
    printf("\nactivate flag f\n");
}
