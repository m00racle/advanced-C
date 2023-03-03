#include <stdio.h>

// making the struct

struct emp {
	int emp_id;
	char emp_name[30];
};
// NOTE: remember struct definition always ends with ; 

int main() {
	// instantiate the struct
	struct emp e;

	// I want to capture the user input as the data source:
	printf("Enter the employee number: ");
	// use scanf to capture the user input:
	scanf("%d", &e.emp_id);
	// NOTE: scanf uses the address of the e.emp_id variable 
	
	printf("Enter the employee name  : ");
	scanf("%s", &e.emp_name);
	// you can use address &e.emp_name or no address like above no different
	// This is because %s is placeholder of string which actually is an array of char
	// array uses the first element address (depending on endianness) as ref to values
	printf("\n the inputs:\n");
	printf("Employee Id   : %d\n", e.emp_id);
	printf("Employee Name : %s\n", e.emp_name);
	printf("\nthe addresses for each data:\n");
	printf("Address of Emp Id   : %p\n", &e.emp_id);
	printf("Address of Emp Name : %p\n", &e.emp_name);
	// again for e.emp_name with or without & is the same thing.
	return 0;
}
