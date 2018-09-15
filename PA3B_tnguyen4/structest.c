#include <stdio.h>
#include "mystruct.h"

#define NUM_EMP 10

int main(int atgc, char *argv[]) {
	struct Employee *e;

	e = makeEmployee(1952, 1999, "Mike Ciaraldi");

	printEmployee(e);

	printf("\n");
	struct Employee **listOfEmployee = getRandListEmployee(NUM_EMP);
	printEmployees(listOfEmployee, NUM_EMP);

	printf("This is deep copy:\n");
	struct Employee **deep = deepCopyList(listOfEmployee, NUM_EMP);
	struct Employee **shallow = shallowCopy(listOfEmployee, NUM_EMP);
	freeArray(listOfEmployee, NUM_EMP);
	printEmployees(shallow, NUM_EMP);
	printEmployees(deep, NUM_EMP);
	return 0;
}
