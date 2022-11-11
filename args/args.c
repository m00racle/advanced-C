#include <stdio.h>

int main (int argc, char *argv[]) {
	/*This program is to practice argc and argv 
	 * argc is the number of argument passed through command line thus int
	 * argv is the array consist of all arguments passed through command line
	 * the content in argv must be the same type in this case all char 
	 * The index 0 of the argv is already taken by the executable name*/

	int i = 0;
	// let's count how many arguments passed from command line
	printf("\ncommand line args count= %d", argc);
	
	// check the executable name using argv[0]
	printf("\nexecutable filename: %s", argv[0]);

	// iterate thorough all arguments (other than executable file name)
	
	if (argc > 1) {
	for (i = 1; i < argc ; i++) {
		printf("\narg %d : %s", i, argv[i]);
	}
	}

	printf("\n");
	return 0;

}
