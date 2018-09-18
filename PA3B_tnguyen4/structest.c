#include <stdio.h>
#include "mystruct.h"

#define NUM_EMP 10

int main(int atgc, char *argv[]) {
	printf("----------First Employees------------\n");
	// Print out first employees
	struct Employee *e; //first employee
	e = makeEmployee(1952, 1999, "Mike Ciaraldi");
	printEmployee(e);
	printf("\n");
	struct Employee *e1; //second employee
	e1 = makeEmployee(1234, 2143, "David Beckham");
	printEmployee(e1);
	printf("\n");
	struct Employee *e2; //third employee
	e2 = makeEmployee(4536, 2134, "Ronald Reagan");
	printEmployee(e2);


	printf("\n----------Random Employees------------\n");
	struct Employee *e3; //fourth employee
	e3 = makeRandEmployee();
	printEmployee(e3);
	printf("\n");
	struct Employee *e4; //fifth employee
	e4 = makeRandEmployee();
	printEmployee(e4);
	printf("\n");
	struct Employee *e5; //sixth employee
	e5 = makeRandEmployee();
	printEmployee(e5);


	printf("\n----------Create list of random Employees------------\n");
	printf("\n");
	struct Employee **listOfEmployee = getRandListEmployee(NUM_EMP);
	printEmployees(listOfEmployee, NUM_EMP);


	printf("\n----------Test Shallow Copy------------\n");
	printf("\n");
	printf("This is shallow copy of listOfEmployee:\n");
	struct Employee **shallow = shallowCopy(listOfEmployee, NUM_EMP);
	printEmployees(shallow, NUM_EMP);


	printf("\n----------Test Deep Copy------------\n");
	printf("\n");
	printf("This is deep copy of listOfEmployee:\n");
	struct Employee **deep = deepCopyList(listOfEmployee, NUM_EMP);
	printEmployees(deep, NUM_EMP);

	printf("Freeing the original listOfEmployee\n");
	freeArray(listOfEmployee, NUM_EMP);
	printf("ShallowCopy should only print out garbage:\n");
	printEmployees(shallow, NUM_EMP);
	printf("\nDeepCopy should still able to print all original employees:\n");
	printEmployees(deep, NUM_EMP);

	freeArray(deep, NUM_EMP);
	return 0;
}
