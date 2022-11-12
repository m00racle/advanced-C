#include <stdio.h>
#include <stdbool.h>
#include <string.h>

/* This file is to demonstrate the use of flags */
// declare all functions other than main:
void flag_o();
void flag_f();

int main(int argc, char *argv[]) {
    // declare boolean flag = false
    bool flag_status = false;
    int i = 0;

    // test argc :
    printf("number of arguments: %d", argc);

    if (argc > 1) {

        for (i = 1 ; i < argc ; i++) {
            printf("\nargument: %s", argv[i]);
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
    printf("\nactivate flag o");
}

void flag_f() {
    printf("\nactivate flag f");
}