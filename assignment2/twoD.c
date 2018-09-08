#include <stdio.h>
#include <stdlib.h>
#include "twoD.h"

// TODO Remove afterwards
/** Make a 2D array of integers (this is an example)
 *
 * @param nrows Number of rows
 * @param ncolumns Number of columns
 * @return Pointer to the array of pointers to the rows.
 * 	  or null pointer if unable to allocate memory.
 * 	  Note: Will not free partially-allocated memory.
 *
 * @author Mike Ciaraldi
 */

int** make2Dint(int nrows, int ncolumns) {

	int **a; // Array of pointers to rows
	unsigned int i; // Loop counter

	// First allocate the array of pointers to rows
	a = (int **) malloc(nrows * sizeof(int *));
	if (!a) { // Unable to allocate the array
		return (int **) NULL;
	}

	// Now allocate array for each row
	for (i = 0; i < nrows; i++) {
		// i is the row we are about to allocate
		a[i] = malloc(ncolumns * sizeof (int));
		if (!a[i]) {
			return (int **) NULL; // Unable to allocate
		}
	}
	return a;
}

/** Make a 2D array of characters
 *
 * @param nrows Number of rows
 * @param ncolumns Number of columns
 * @return Pointer to the array of pointers to the rows.
 * 	  or null pointer if unable to allocate memory.
 * 	  Note: Will not free partially-allocated memory.
 *
 * @author Dung (Kevin) Nguyen
 */
char** make2Dchar(int nrows, int ncolumns) {

	char **a; // Array of pointers to rows
	unsigned int i; // Loop counter

	// First allocate the array of pointers to rows
	a = (char **) malloc(nrows * sizeof(char *));
	if (!a) { // Unable to allocate the array
		return (char **) NULL;
	}

	// Now allocate array for each row
	for (i = 0; i < nrows; i++) {
		// i is the row we are about to allocate
		a[i] = malloc(ncolumns * sizeof(char));
		if (!a[i]) {
			return (char **) NULL; // Unable to allocate
		}
	}

	return a;
}

/**
 * Print out the 2D array to the console
 * @array given grid
 * @nrows number of rows
 * @ncolumns number of columns
 *
 * @author: Dung (Kevin) Nguyen
 */
void print2DArray(char **array, int nrows, int ncolumns) {
	for (int row = 0; row < nrows; row++) {
		for (int col = 0; col < ncolumns; col++) {
			printf("%c ", *(*(array + row) + col));
		}
		printf("\n");
	}
}
