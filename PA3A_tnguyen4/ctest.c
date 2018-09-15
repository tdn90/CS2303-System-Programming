#include <stdio.h>
#include <string.h>
// string.h covers the C-style string functions.
#include "mystring.h"

/** ctest.c
 * Program to demonstrate character arrays and
 * dynamically-allocated memory.
 * @author Mike Ciaraldi
 * Add your own @author line below.
 * @author Dung (Kevin) Nguyen
 */
const int MAX_CHARS = 20; // Maximum number of characters in array

int main() {
	char a1[MAX_CHARS + 1]; // Character array--initially empty
	char a2[] = "Hello"; // Character array--unsized but initialized
	char a3[MAX_CHARS + 1]; // Character array--we will underfill it
	char* p1 = "Hello"; // Pointer to constant string
	char* p2 = NULL;        // Will be a pointer to dynamically-allocated string
	char* p3 = "Hi"; // Pointer to another constant string
	int copy_limit;     // Maximum characters to copy.

	strcpy(a3, "Hello, one more time."); // Initialize underfilled character array

	/* Print the pointers.
	 Note: this example prints
	 the values of the pointers themselves, not the targets.
	 */
	printf("Initial state:\n");
	printf("Pointers: a1 = %p, a2 = %p, a3 = %p\n", a1, a2, a3);
	printf("          p1 = %p p2 = %p\n", p1, p2);

	strcpy(a1, p3); // Initialize character array

	printf("a1 = %s\n", a1);
	printf("a2 = %s\n", a2);
	printf("a3 = %s\n", a3);

	printf("\n");
	// Part 2 test here
	// Note that strlen() returns size_t, which is typedef'd to
	//   unsigned long, so we need to print it with %ld instead of just %d.
	printf("For string /%s/, strlen() returns %ld\n", p1, strlen(p1));
	printf("For string /%s/, strlen() returns %ld\n", p3, strlen(p3));
	printf("For string /%s/, strlen() returns %ld\n", a1, strlen(a1));
	printf("For string /%s/, strlen() returns %ld\n", a2, strlen(a2));
	printf("For string /%s/, strlen() returns %ld\n", a3, strlen(a3));
	// Testing my version of strlen
	printf("\nMy version of strlen1\n");
	printf("For string /%s/, strlen1() returns %ld\n", p1, mystrlen1(p1));
	printf("For string /%s/, strlen1() returns %ld\n", p3, mystrlen1(p3));
	printf("For string /%s/, strlen1() returns %ld\n", a1, mystrlen1(a1));
	printf("For string /%s/, strlen1() returns %ld\n", a2, mystrlen1(a2));
	printf("For string /%s/, strlen1() returns %ld\n", a3, mystrlen1(a3));

	printf("\nMy version of strlen2\n");
	printf("For string /%s/, strlen2() returns %ld\n", p1, mystrlen2(p1));
	printf("For string /%s/, strlen2() returns %ld\n", p3, mystrlen2(p3));
	printf("For string /%s/, strlen2() returns %ld\n", a1, mystrlen2(a1));
	printf("For string /%s/, strlen2() returns %ld\n", a2, mystrlen2(a2));
	printf("For string /%s/, strlen2() returns %ld\n", a3, mystrlen2(a3));

	// Duplicate a string, using strdup(), then print
	printf("\nBefore calling strdup(), pointer a2 = %p, contents = %s\n", a2,
			a2);
	p2 = strdup(a2);
	printf("Duplicated string: \n");
	printf("Pointer p2 = %p, contents = %s\n", p2, p2);

	// Duplicate a string, using my function, then print
	printf("\nBefore calling mystrdup1(), pointer a2 = %p, contents = %s\n", a2,
			a2);
	p2 = mystrdup1(a2);
	printf("Duplicated string: \n");
	printf("Pointer p2 = %p, contents = %s\n", p2, p2);

	// Duplicate a string, using my function 2, then print
	printf("\nBefore calling mystrdup2(), pointer a2 = %p, contents = %s\n", a2,
			a2);
	p2 = mystrdup2(a2);
	printf("Duplicated string: \n");
	printf("Pointer p2 = %p, contents = %s\n", p2, p2);

	// Be sure there is a terminator character in the last element of the array
	a1[MAX_CHARS] = '\0';

	// Concatenate two character arrays, then print.
	strcpy(a1, p3); // Reset character array
	strcat(a1, a2);
	printf("Using strcat() to concatenate a2 to the end of a1\n");
	printf("a1 = %s\n", a1);

	// Concatenate two character arrays safely, then print.
	strcpy(a1, p3); // Reset character array
	a1[MAX_CHARS] = 'A'; // Remove terminator, to prove strncat() puts it back in.
	copy_limit = MAX_CHARS - strlen(a1); // How much space is left?
	printf(
			"Using strncat() to concatenate to the end of a1, with copy_limit = %d\n",
			copy_limit);
	if (copy_limit > 0)
		strncat(a1, a3, copy_limit);
	printf("a1 = %s\n", a1);

	printf("\n");
	// Part 3:
	char mystr1[10];
	char mystr2[5];
	char mystr3[7] = "123456";

	strcpy(mystr1, mystr3);
	printf("After using strcpy to copy from mystr3 to mystr1:\n");
	printf("Value of mystr3: %s\n", mystr3);
	printf("Value of mystr1: %s\n", mystr1);

	//TODO: test part 4,5,6

	return 0;
}
