# include <stdio.h>

/*This program is to test the argv and env variables
 * while argv is using single pointer the env in its declaration here 
 * uses pointer to pointer.*/

int main (int argc, char *argv[], char **env_ptr) {
	// we use env ptr since this is not an array but pointer to pointer
	
	int i = 0;

	// I think the devs put i here as declaration must be on top of the function
	
	printf("\ncommand line arg count : %d", argc);

	printf("\nexecutable file: %s", argv[0]);

	// for the rest of argv if exist:
	if (argc > 1) {
		for (i = 1; i < argc ; i++) {
			printf("\narg %d : %s", i, argv[i]);
		}
	}

	// now for the environmet variable
	i = 0;
	while (*env_ptr != NULL) {
		
		printf("\nenv var %d : %s", i, *(env_ptr++));
		i++;
	}

	printf("\n");
	return 0;
}
