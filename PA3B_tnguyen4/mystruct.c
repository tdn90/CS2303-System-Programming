/** mystruct.c
 * @author Mike Ciaraldi
 * @author Dung (Kevin) Nguyen
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
	// allocate memory for a new Employee struct
	struct Employee* emp = (struct Employee*) malloc(sizeof(struct Employee));

	// Check if memory can be allocated
	if (emp == NULL)
		return (struct Employee*) NULL;

	// Assign each variable to the new employee's fields
	emp->birth_year = birth;
	emp->start_year = start;
	strcpy(emp->name, name);

	return emp;
}

/**
 *	Print out information about the given employee
 *	@param e given employee
 */
void printEmployee(struct Employee *e) {
	printf("Employee's name: %s\n", e->name);
	printf("Employee's birth year: %d\n", e->birth_year);
	printf("Employee's start year: %d\n", e->start_year);
	printf("Employee's memory address: %p\n", e);
}

/**
 * Create a new employee with random information
 * @return Pointer to the new random Employee struct created
 */
struct Employee* makeRandEmployee() {
	int birth = 1800 + randInt(300);
	int start = birth + 10 + randInt(80);
	char *name = randStr();
	return makeEmployee(birth, start, name);
}

/**
 * Helper function for makeRandEmployee
 * Generate a random integer that is less than given max
 * @param max given maximum value for random number generated
 * @return a random integer that is less than given max
 */
int randInt(int max) {
	return rand() % max;
}

/**
 * Helper function for makeRandEmployee
 * Generate a random string
 * @return a pointer to a random string, NULL pointer if cannot allocate memory
 */
char *randStr() {
	int fullLength = (9 + randInt(7)); //fullName's length
	int firstLength = 2 + randInt(4); // firstName's length
	int lastLength = fullLength - firstLength - 1; //lastName's length
	char *name;
	//allocate memory for name
	name = (char *) malloc(fullLength * sizeof(char) + 1); // add space for null terminator

	// check if memory successfully allocated
	if (name == 0) return (char *) NULL;

	char *name1 = name; // preserve original pointer name
	*name1++ = randUppercase(); // capitalize first name
	firstLength--;

	/*
	 * Loop invariant:
	 * firstLength is counter for first name's length
	 * name1 is the pointer, moving from left to right in the string
	 * Decrement this counter per loop
	 * Stop once there is enough character for firstName
	 */
	while (firstLength-- > 0) {
		*(name1++) = randLowercase();
	}

	*(name1++) = ' '; // add space between first and last name
	*(name1++) = randUppercase(); // capitalize last name
	lastLength--;

	/*
	 * Loop invariant:
	 * lastLength is counter for last name's length
	 * name1 is the pointer, moving from left to right in the string
	 * Decrement this counter per loop
	 * Stop once there is enough character for last name
	 */
	while (lastLength-- > 0) {
		*(name1++) = randLowercase();
	}
	*name1 = '\0'; // nunll-terminate the string
	return name;
}

/**
 * Helper function for randStr
 * @return a random lowercase character (from a-z)
 */
char randLowercase() {
	return (char) ('a' + randInt(26));
}

/**
 * Helper function for randStr
 * @return a random uppercase character (from a-z)
 */
char randUppercase() {
	return (char) ('A' + randInt(26));
}

/**
 * Generate a list of random employees
 * @param size specified size of newly created array of employees
 * @return a pointer to an array of employee structs
 */
struct Employee **getRandListEmployee(int size) {
	struct Employee **listOfEmp; // list of random employees

	// ALlocate memory to hold [size] pointers to the employee struct
	listOfEmp = (struct Employee **) malloc(size * sizeof(struct Employee *));
	// check if memory can be allocated
	if (!listOfEmp)
		return (struct Employee **) NULL;


	struct Employee **originalListOfEmp = listOfEmp; //preserve original pointer to array
	/*
	 * Loop invariant:
	 * size is the length of the array, decremented per loop
	 * listOfEmp is the pointer used to go through each element of array
	 * Stop when size reaches 0 (go to the end of array)
	 */
	while (size-- > 0) {
		// allocate memory and create random employee struct for each element
		*(listOfEmp++) = makeRandEmployee();
	}
	return originalListOfEmp;
}

/**
 * Print out each employee in the given list
 * @param list Pointer to list of employee structs
 * @param count size of the given list
 */
void printEmployees(struct Employee **list, int count) {
	int i = 0; // loop counter
	/*
	 * Loop invariant:
	 * i is loop counter, incremented each time
	 * Stop when i reaches count (reach the end of the list)
	 * Print out employee per loop
	 */
	while (i < count) {
		printf("Employee[%d]:\n", i++);
		printEmployee(*(list++));
		printf("\n");
	}
}


/**
 * Make a shallow copy of the list of employers
 * @param list Pointer to a list of Employee structs
 * @param size length of the given list
 */
struct Employee **shallowCopy(struct Employee **list, int size) {
	struct Employee **copy;
	// ALlocate memory to hold [size] pointers to the employee struct
	copy = (struct Employee **) malloc(size * sizeof(struct Employee *));
	//check if memory can be allocated
	if (!copy)
		return (struct Employee **) NULL;

	struct Employee **originalCopy = copy;//preserve original pointer to the "shallow copy"
	/*
	 * Loop invariant:
	 * size is loop counter, decremented each time
	 * Stop size reach 0 (reach the end of the list)
	 * Print out employee per loop
	 */
	while (size-- > 0) {
		*(copy++) = *(list++); // copy pointer to a random struct to the new list
	}
	return originalCopy;
}

/**
 * Free the memory reserved for the given list
 * @param pointer to list of employee structs
 * @param count size of given list of employee structs
 */
void freeArray(struct Employee **list, size_t count) {
	/*
	 * Loop invariant:
	 * i is the index of elements in the array
	 * use i to loop through each element
	 * Free each element
	 */
	for (int i = 0; i < count; i++) {
		free(list[i]);
	}
	// eventually free the whole list
	free(list);
}

/**
 * Helper function for deepCopyList
 * @param e the employee to be duplicated (deep copy)
 * @return the pointer to the newly created employee struct
 * that is duplicated from the given employee
 */
struct Employee *deepCopyEmp(struct Employee *e) {
	return makeEmployee(e->birth_year, e->start_year, strdup(e->name));
}

/**
 * Make a deep copy of the original list
 * @param list given list of structs
 * @param size given size of list
 * @return pointer to newly created deep copy of the given list of employee structs
 */
struct Employee **deepCopyList(struct Employee **list, size_t size) {
	struct Employee **listOfEmp; //newly duplicated list

	// allocate memory
	listOfEmp = (struct Employee **) malloc(size * sizeof(struct Employee *));
	// check if succeed
	if (!listOfEmp)
		return (struct Employee **) NULL;

	struct Employee **originalListOfEmp = listOfEmp;//preserve original pointer
	/*
	 * Loop invariant
	 * size decremented each time, terminate when size reach 0
	 */
	while (size-- > 0) {
		/* make a deep copy of each element in the original list
		 * and assign it to the new list's current element
		 */
		*(listOfEmp++) = deepCopyEmp(*(list++));
	}
	return originalListOfEmp;
}

