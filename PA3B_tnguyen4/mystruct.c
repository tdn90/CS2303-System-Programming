/** mystruct.c
 * @author Mike Ciaraldi
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "mystruct.h"

/** Allocates an Employee struct and fills in its fields
 * @param birth Year the emploee was born.
 * @param start Year the employee started with the company.
 * @param name String containing employee's name
 * @return Pointer to Employee struct, newly allocated from the heap.
 */
struct Employee* makeEmployee(int birth, int start, const char *name) {
	struct Employee* emp = (struct Employee*) malloc(sizeof(struct Employee));

	if (emp == NULL)
		return (struct Employee*) NULL;

	emp->birth_year = birth;
	emp->start_year = start;
	strcpy(emp->name, name);

	return emp; // Replace this with a pointer to the allocated struct
}

/**
 *	Print out information about the given employee
 *	@e given employee
 */
void printEmployee(struct Employee *e) {
	printf("Employee's name: %s\n", e->name);
	printf("Employee's birth year: %d\n", e->birth_year);
	printf("Employee's start year: %d\n", e->start_year);
	printf("Employee's memory address: %p\n", e);
}

/**
 * Create a new employee with random information
 */
struct Employee* makeRandEmployee() {
	int birth = 1800 + randInt(300);
	int start = birth + 10 + randInt(80);
	char *name = randStr();
	return makeEmployee(birth, start, name);
}

/**
 * Generate a random integer that is less than given max
 * @max given maximum value for random number generated
 */
int randInt(int max) {
	return rand() % max;
}

/**
 * Generate a random string
 */
char *randStr() {
	int fullLength = (9 + randInt(7));
	int firstLength = 2 + randInt(4);
	int lastLength = fullLength - firstLength - 1;
	char *name;
	name = (char *) malloc(fullLength * sizeof(char) + 1);

	char *name1 = name;
	*name1++ = randUppercase();
	firstLength--;
	while (firstLength-- > 0) {
		*(name1++) = randLowercase();
	}
	*(name1++) = ' ';
	*(name1++) = randUppercase();
	lastLength--;
	while (lastLength-- > 0) {
		*(name1++) = randLowercase();
	}
	*name1 = '\0';
	return name;
}

char randLowercase() {
	return (char) ('a' + randInt(26));
}

char randUppercase() {
	return (char) ('A' + randInt(26));
}

struct Employee **getRandListEmployee(int size) {
	struct Employee **listOfEmp;

	listOfEmp = (struct Employee **) malloc(size * sizeof(struct Employee *));
	if (!listOfEmp)
		return (struct Employee **) NULL;

	struct Employee **originalListOfEmp = listOfEmp;
	while (size-- > 0) {
		*(listOfEmp++) = makeRandEmployee();
	}
	return originalListOfEmp;
}

void printEmployees(struct Employee **list, int count) {
	int i = 0;
	while (i < count) {
		printf("Employee[%d]:\n", i++);
		printEmployee(*(list++));
		printf("\n");
	}
}

struct Employee **shallowCopy(struct Employee **list, int size) {
	struct Employee **copy;

	copy = (struct Employee **) malloc(size * sizeof(struct Employee *));
	if (!copy)
		return (struct Employee **) NULL;

	struct Employee **originalCopy = copy;
	while (size-- > 0) {
		*(copy++) = *(list++);
	}
	return originalCopy;
}

void freeArray(struct Employee **list, size_t count) {
	for (int i = 0; i < count; i++) {
		free(list[i]);
	}
	free(list);
}

struct Employee *deepCopyEmp(struct Employee *e) {
	return makeEmployee(e->birth_year, e->start_year, strdup(e->name));
}

struct Employee **deepCopyList(struct Employee **list, size_t size) {
	struct Employee **listOfEmp;

	listOfEmp = (struct Employee **) malloc(size * sizeof(struct Employee *));
	if (!listOfEmp)
		return (struct Employee **) NULL;

	struct Employee **originalListOfEmp = listOfEmp;
	while (size-- > 0) {
		*(listOfEmp++) = deepCopyEmp(*(list++));
	}
	return originalListOfEmp;
}

