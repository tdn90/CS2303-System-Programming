/** mystring.c
 * @author Mike Ciaraldi
 * My own versions of some of the C-style string functions
 * @author Dung (Kevin) Nguyen
 */

#include <string.h>
#include <stdlib.h>
// Have to #include stdlib.h because it is needed to use malloc()
#include "mystring.h"

/** Duplicates a C-style string, with help from mystrlen1()
 * @param src Pointer to string to be copied
 * @return Pointer to freshly-allocated string containing a duplicate of src
 *  or null if no memory is available
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
 * @param src Pointer to string to be copied
 * @return Pointer to freshly-allocated string containing a duplicate of src
 	 or null if no memory is available
 */
char* mystrdup2(const char* src) {
	int length; // Length of the source string
	char* newstr; // Pointer to memory which will hold new string

	// use mystrlen2 function
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
 * @param s pointer to string to be duplicated
 * @param n number of bytes in given string to be duplicated into new string
 * @return a pointer to a new string that is the result of the duplication
 */
char *mystrndup(const char *s, size_t n) {
	char *newstr;
	newstr = (char*) malloc(n+1); // n bytes + one null terminator

	// If no memory was available, return null pointer
	if (newstr == 0) return (char *) 0;

	// otherwise, copy n bytes from s and return pointer to new string
	strncpy(newstr, s, n);
	*(newstr+n) = '\0'; // add null terminator at the end
	return newstr;
}


/**
 * Step through each array using a subscript (str[i])
 * Calculate the length of the string
 * @param str given string as a character array
 * @param return the length of the given string
 */
size_t mystrlen1(const char *str) {
	int currentIndex = 0; // current index in the given string
	size_t strlen = 0; // keep track of string length

	/*
	 * Invariant: currentIndex - current index of given string
	 * Loop until reaching null terminator
	 */
	while (str[currentIndex] != '\0') { // stop when reach null terminator
		strlen++;
		currentIndex++;
	}
	// currentIndex is now at null terminator
	return strlen;
}

/**
 * Step through each array using incrementing pointers
 * Calculate the length of the string
 * @param str given string as a character array
 * @return the length of the given string
 */
size_t mystrlen2(const char *str) {
	size_t strlen = 0; // keep track of string length
	/*
	 * Invariant:
	 * str: the current memory address in the array
	 * Keep moving the pointer from left to right
	 */
	while (*(str++) != '\0') { // stop when see null terminator
		strlen++;
	}
	return strlen;
}

/**
 * Use incrementing pointer
 * Copy the string pointed to by src, including the terminating
 * null byte ('\0'), to the buffer  pointed  to  by  dest.
 * The  strings  may  not overlap, and the destination string dest must be
 * large enough to receive the copy.
 * Bugs: if dest is not large enough, then anything can happen.
 * @param dest destination array of characters, waiting to be copied over
 * @param src source array of characters, which is used to copy
 * @return the original pointer to dest
 */
char *mystrcpy(char *dest, const char *src) {
	char *dest2 = dest; // new pointer to first character in array, thus leave the original dest untouched

	/* Loop invariant:
	 * As long as *(src) is not null terminator,
	 * assign its value to *(dest2)
	 * Then move both pointers to the next character
	 */
	while ((*(dest2++) = *(src++)) != '\0');  // stop if reach null terminator
	// dest2 is now at null terminator
	return dest;
}

/**
 * Similar to strcpy, except that at most n bytes of src are copied.
 * Warning: If there is no null byte among the first n bytes of src,
 * the string placed in dest will not be null-terminated
 * If the length of src is less than , strncopy writes additional
 * null bytes to dest to ensure that a total of n bytes
 * are written
 * @param dest pointer to given destination string
 * @param src pointer to given source string
 * @param n number of bytes to copied from source to destination string
 * @return the pointer to destination string
 */
char *mystrncpy(char *dest, const char *src, size_t n) {
	char *dest2 = dest; //preserve original dest
	/* Loop invariant:
	 * n is the number of bytes copied over, decrement each per copy
	 * As long as *(src) is not null terminator,
	 * assign its value to *(dest2)
	 * Then move both pointers to the next character
	 * Stop after either n bytes is copied over
	 */
	while (n > 0 && *(src) != '\0') {
		*(dest2++) = *(src++);
		n--;
	} // dest2 stop after n bytes is copied or src reach null terminator

	// Fill up the rest with null bytes of applicable
	while (n-- > 0) {
		*(dest2++) = '\0';
	}
	return dest;
}


/**
 * Appends  the  src string to the dest string,
 * overwriting the terminating null byte ('\0')
 * at the end of dest, and then adds a terminating null byte.
 * The strings may  not overlap
 * The dest string must have enough space for the result.
 * If dest is not large enough, program behavior is unpredictable
 * @param dest pointer to given destination string
 * @param src pointer to given source string
 */
char *mystrcat(char *dest, const char *src) {
	char *dest2 = dest; // new pointer to first character in array, to preserve original dest

	/*
	 * Loop invariant:
	 * dest2 is current pointer index in the string
	 * Stop when reaching null terminator
	 */
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
 * The resulting string in dest is always null-terminated
 * The size of dest must be at least strlen(dest) + n + 1
 * @param dest pointer to destination string
 * @param src pointer to source string
 * @param n number of characters / bytes to be copied over from src to dest (n does not include null-terminator)
 * @return the pointer to the destination string after concatenation
 */
char *mystrncat(char *dest, const char *src, size_t n) {
	char *dest2 = dest; // attempt to preserve original dest

	/*
	 * Loop invariant:
	 * dest2 is pointer to move from left to right of string dest
	 * Stop when reaching null terminator
	 */
	while (*(dest2) != '\0') {
		dest2++;
	} // dest 2 is now at null terminator, about to be overwritten

	/*
	 * Loop invariant:
	 * n is the number of bytes left needed to write
	 * src is pointer to move from left to right of string src
	 * Stop when finish copying over n bytes or reaching null terminator in src string
	 */
	while (n > 0 && *(src) != '\0') {
		*(dest2++) = *(src++); // copy over from src to dest
		n--;
	} // src2 either is at null terminator or n is 0

	*dest2 = '\0'; // add null terminator
	return dest;
}




