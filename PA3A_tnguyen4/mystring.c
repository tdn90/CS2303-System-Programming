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
	if (newstr == 0)
		return (char *) 0;

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
	if (newstr == 0)
		return (char *) 0;

	// Otherwise, copy the string and return pointer to new string
	strcpy(newstr, src);
	return newstr;
}

/**
 * Similar to strdup, but copies at most n bytes
 * If s is longer than n, only n bytes are copied,
 * and a null terminator is added
 * @s
 * @n
 */
char *strndup(const char *s, size_t n) {
	char *newstr;

	//use mystrlen2 function
	newstr = (char*) malloc(n+1); // n bytes + one null terminator

	// If no memory was available, return null pointer
	if (newstr == 0) return (char *) 0;

	// otherwise, copy n bytes from s and return pointer to new string
	strncpy(newstr, s, n);
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

/**
 * Use incrementing pointer
 * The  strcpy()  function  copies the string pointed to by src, including
 the terminating null byte ('\0'), to the buffer  pointed  to  by  dest.
 The  strings  may  not overlap, and the destination string dest must be
 large enough to receive the copy.
 * @dest destination array of characters, waiting to be copied over
 * @src source array of characters, which is used to copy
 */
char *strcpy(char *dest, const char *src) {
	char *dest2 = dest; // new pointer to first character in array, so dest still point to first character
	while ((*(dest2++) = *(src++)) != '\0')
		;  // stop if reach null terminator
	return dest;
}

/**
 * Similar to strcpy, except that at most n bytes of src
 * are copied.
 * If there is no null byte among the first n bytes of src,
 * the string placed in dest will not be null-terminated
 * If the length of src is less than , strncopy writes additional
 * null bytes to dest to ensure that a total of n bytes
 * are written
 */
char *strncpy(char *dest, const char *src, size_t n) {
	char *dest2 = dest;
	while (n > 0 && *(src) != '\0') {
		*(dest2++) = *(src++);
	} // dest2 stop after n bytes is copied or src reach null terminator

	// Fill up the rest with null bytes of applicable
	while (n-- > 0) {
		*(dest2++) = '\0';
	}
	return dest;
}


/**
 * The  strcat()  function  appends  the  src string to the dest string, overwriting the terminating null byte
 ('\0') at the end of dest, and then adds a terminating null byte.  The strings may  not  overlap,  and  the
 dest string must have enough space for the result.  If dest is not large enough, program behavior is unpre‐
 dictable
 */
char *strcat(char *dest, const char *src) {
	char *dest2 = dest; // new pointer to first character in array, so dest still point to first character
	while (*(dest2) != '\0') {// loop until null terminator of dest
		dest2++;
	} // dest2 is now at null terminator

	while (*(src) != '\0') { //loop until null terminator of src
		*(dest2++) = *(src++);
	} // src is now at null terminator

	*dest2 = '\0'; // add null terminator at the end
	return dest;
}
/**
 * This is similar to strcat, except:
 * It will use at most n bytes from src
 * src does not need to be null-terminated if it contains n or more bytes
 * The size of dest must be at least strlen(dest) + n + 1
 * @dest
 * @src
 * @n
 */
char *strncat(char *dest, const char *src, size_t n) {
	char *dest2 = dest;
	while (*(dest2) != '\0') {
		dest2++;
	} // dest 2 is now at null terminator
	while (n > 0 && *(src) != '\0') {
		*(dest2++) = *(src++);
		n--;
	} // src2 either is at null terminator or n is 0
	*dest2 = '\0';
	return dest;
}




