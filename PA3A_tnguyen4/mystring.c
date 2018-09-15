/** mystring.c
 * @author Mike Ciaraldi
 * My own versions of some of the C-style string functions
*/

#include <string.h>
#include <stdlib.h>
// Have to #include stdlib.h because it is needed to use malloc()
#include "mystring.h"

/** Duplicates a C-style string, with help from mystrlen1()
 @param src Pointer to string to be copied
 @return Pointer to freshly-allocated string containing a duplicate of src
         or null if no memory is available
*/
char* mystrdup1(const char* src) {
  int length; // Length of the source string
  char* newstr; // Pointer to memory which will hold new string

  // use mystrlen1 function
  length = mystrlen1(src) + 1;  // Leave space for the terminator
  newstr = (char*) malloc(length); // Must cast!

  // If no memory was available, return null pointer immediately
  if (newstr == 0) return (char *) 0;

  // Otherwise, copy the string and return pointer to new string
  strcpy(newstr, src);
  return newstr;
}

/** Duplicates a C-style string, with help from mystrlen2()
 @param src Pointer to string to be copied
 @return Pointer to freshly-allocated string containing a duplicate of src
         or null if no memory is available
*/
char* mystrdup2(const char* src) {
  int length; // Length of the source string
  char* newstr; // Pointer to memory which will hold new string

  // use mystrlen1 function
  length = mystrlen2(src) + 1;  // Leave space for the terminator
  newstr = (char*) malloc(length); // Must cast!

  // If no memory was available, return null pointer immediately
  if (newstr == 0) return (char *) 0;

  // Otherwise, copy the string and return pointer to new string
  strcpy(newstr, src);
  return newstr;
}

/**
 * Step through each array using a subscript (str[i])
 * Calculate the length of the string
 * @str given string as a character array
 */
size_t mystrlen1(char *str) {
	int currentIndex = 0; //current index in the given string
	size_t strlen = 0; // keep track of string length
	while (str[currentIndex] != '\0') { // stop when reach null terminator
		strlen++;
		currentIndex++;
	}
	return strlen;
}

/**
 * Step through each array using incrementing pointers
 * Calculate the length of the string
 * @str given string as a character array
 */
size_t mystrlen2(char *str) {
	size_t strlen = 0; // keep track of string length

	// keep looking at character at the next memory
	while (*(str++) != '\0') { // stop when see null terminator
		strlen++;
	}
	return strlen;
}



