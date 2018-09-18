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
const int MAX_CHARS = 21; // Maximum number of characters in array

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
	printf("Pointers: a1 = %p, a2 = %p, a3 = %p\n", a1, a2, a3); // high value memory address
	printf("          p1 = %p p2 = %p\n", p1, p2); // low value memory address

	strcpy(a1, p3); // Initialize character array

	printf("a1 = %s\n", a1);
	printf("a2 = %s\n", a2);
	printf("a3 = %s\n", a3);

	printf("\n------------------STRLEN TEST---------------------------\n");
	printf("\n");
	// Part 2 test here
	// Note that strlen() returns size_t, which is typedef'd to
	//   unsigned long, so we need to print it with %ld instead of just %d.
	printf("For string /%s/, strlen() returns %ld\n", p1, strlen(p1));
	printf("For string /%s/, strlen() returns %ld\n", p3, strlen(p3));
	printf("For string /%s/, strlen() returns %ld\n", a1, strlen(a1));
	printf("For string /%s/, strlen() returns %ld\n", a2, strlen(a2));
	printf("For string /%s/, strlen() returns %ld\n", a3, strlen(a3));

	// Testing my version of strlen1
	printf("\nMy version of strlen1\n");
	printf("For string /%s/, strlen1() returns %ld\n", p1, mystrlen1(p1));
	printf("For string /%s/, strlen1() returns %ld\n", p3, mystrlen1(p3));
	printf("For string /%s/, strlen1() returns %ld\n", a1, mystrlen1(a1));
	printf("For string /%s/, strlen1() returns %ld\n", a2, mystrlen1(a2));
	printf("For string /%s/, strlen1() returns %ld\n", a3, mystrlen1(a3));

	// Testing my version of strlen2
	printf("\nMy version of strlen2\n");
	printf("For string /%s/, strlen2() returns %ld\n", p1, mystrlen2(p1));
	printf("For string /%s/, strlen2() returns %ld\n", p3, mystrlen2(p3));
	printf("For string /%s/, strlen2() returns %ld\n", a1, mystrlen2(a1));
	printf("For string /%s/, strlen2() returns %ld\n", a2, mystrlen2(a2));
	printf("For string /%s/, strlen2() returns %ld\n", a3, mystrlen2(a3));


	printf("\n------------------STRDUP TEST----------------------------\n");
	// Duplicate a string, using strdup(), then print
	printf("\nBefore calling strdup(), pointer a2 = %p, contents = %s\n", a2,
			a2);
	p2 = strdup(a2);
	printf("Duplicated string: \n");
	printf("Pointer p2 = %p, contents = %s\n", p2, p2);

	// Duplicate a string, using mystrdup1(), then print
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

	printf("\n----------------------STRCAT-------------------------\n");
	// Concatenate two character arrays, then print.
	strcpy(a1, p3); // Reset character array
	strcat(a1, a2);
	printf("\nUsing strcat() to concatenate a2 to the end of a1\n");
	printf("a1 = %s\n", a1);

	// Concatenate two character arrays using mystrcpy, then print.
	mystrcpy(a1, p3); // Reset character array
	mystrcat(a1, a2);
	printf("\nUsing mystrcat() to concatenate a2 to the end of a1\n");
	printf("a1 = %s\n", a1);


	printf("\n----------------------STRNCAT-------------------------\n");
	// Concatenate two character arrays safely, then print.
	// USe strncat()
	strcpy(a1, p3); // Reset character array
	a1[MAX_CHARS] = 'A'; // Remove terminator, to prove strncat() puts it back in.
	copy_limit = MAX_CHARS - strlen(a1); // How much space is left?
	printf("Using strncat() to concatenate to the end of a1, with copy_limit = %d\n",
			copy_limit);
	if (copy_limit > 0)
		strncat(a1, a3, copy_limit); // length of a3 is greater than n
	printf("a1 = %s\n", a1);

	// Use mystrncat
	strcpy(a1, p3); // Reset character array
	copy_limit = MAX_CHARS - strlen(a1); // How much space is left?
	printf("Using mystrncat() to concatenate to the end of a1, with copy_limit = %d\n",
			copy_limit);
	if (copy_limit > 0)
		mystrncat(a1, a3, copy_limit); // length of a3 is greater than n
	printf("a1 = %s\n", a1);


	// Use strncat
	printf("\nUsing strncat() to concatenate p1 to the end of a1, with copy_limit = %d\n",
				10);
		strcpy(a1, p3); //reset character array
		strncat(a1, p1, 10); //length of p1 is less than n
		printf("a1 = %s\n", a1);

	// Use mystrncat()
	printf("\nUsing mystrncat() to concatenate p1 to the end of a1, with copy_limit = %d\n",
			10);
	strcpy(a1, p3); //reset character array
	mystrncat(a1, p1, 10); //length of p1 is less than n
	printf("a1 = %s\n", a1);

	// Use strncat()
	char *str = "How are you?";
	printf("\nUsing strncat() to concatenate str to the end of a1, with copy_limit = %ld\n",
				mystrlen2(str));
	strcpy(a1, p3); //reset character array
	mystrncat(a1, str, mystrlen2(str)); //length of str = limit
	printf("a1 = %s\n", a1);

	// Use mystrncat
	printf("\nUsing mystrncat() to concatenate str to the end of a1, with copy_limit = %ld\n",
			mystrlen2(str));
	strcpy(a1, p3); //reset character array
	mystrncat(a1, str, mystrlen2(str)); //length of str = limit
	printf("a1 = %s\n", a1);

	printf("\n----------------------STRCPY-------------------------\n");
	// Use strcpy
	strcpy(a1, p3); //reset character array
	printf("Using strncpy() to copy from str to a1\n");
	strcpy(a1,str);
	printf("a1 = %s\n", a1);

	// Use mystrcpy
	strcpy(a1, p3); //reset character array
	printf("Using mystrcpy() to copy from str to a1\n");
	strcpy(a1, str);
	printf("a1 = %s\n", a1);

	// Use strcpy
	strcpy(a1, p3); //reset character array
	printf("Using strncpy() to copy from a3 to a1\n");
	strcpy(a1, a3);
	printf("a1 = %s\n", a1);

	// Use mystrcpy
	strcpy(a1, p3); //reset character array
	printf("Using mystrcpy() to copy from a3 to a1\n");
	strcpy(a1, a3);
	printf("a1 = %s\n", a1);

	printf("\n----------------------STRNCPY-------------------------\n");
	// Use strncpy
	strcpy(a1, p3); //reset character array
	printf("Using strncpy() to copy from str to a1, with limit = %d\n", 5);
	strncpy(a1,str, 5);
	printf("a1 = %s\n", a1); //string not null-terminated

	// Use mystrncpy
	strcpy(a1, p3); //reset character array
	printf("Using strncpy() to copy from str to a1, with limit = %d\n", 5);
	mystrncpy(a1, str, 5);
	printf("a1 = %s\n", a1); //string not null-terminated

	// Use strncpy
	strcpy(a1, p3); //reset character array
	printf("Using strncpy() to copy from a3 to a1, with limit = %d\n", 21);
	strncpy(a1, a3, 10);
	printf("a1 = %s\n", a1);

	// Use mystrncpy
	strcpy(a1, p3); //reset character array
	printf("Using strncpy() to copy from a3 to a1, with limit = %d\n", 21);
	mystrncpy(a1, a3, 10);
	printf("a1 = %s\n", a1);

	printf("\n----------------------STRNDUP-------------------------\n");\
	printf("Using strndup() to duplicate from a3 into p2, with limit = %d\n",
			8);
	p2 = strndup(a3, 8);
	printf("a1 = %s\n", p2);

	// mystrndup
	printf("Using mystrndup() to duplicate from a3 into p2, with limit = %d\n",
			8);
	p2 = mystrndup(a3, 8);
	printf("a1 = %s\n", p2);
}
