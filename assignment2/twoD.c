#include <stdio.h>
#include <stdlib.h>
#include "twoD.h"

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

/**
 * Get the total number of neighbors of a given cell
 * @array given grid
 * @nrows number of rows
 * @ncolumns number of columns
 * @currentR given cell's row
 * @currentC given cell's column
 */
int getNeighbors(char **array, int nrows, int ncolumns, int currentR, int currentC) {
	int neighbors = 0;
	for (int row = currentR - 1; row <= currentR + 1; row++) {
		for (int col = currentC - 1; col <= ncolumns + 1; col++) {
			if (row != currentR && col != currentC) {
				neighbors += getCellVal(array, nrows, ncolumns, currentR, currentC);
			}
		}
	}
	return neighbors;
}

/**
 * Helper function for getNeighbors
 * Get a specific value of the cell.
 * @array given grid
 * @nrows number of rows
 * @columns number of columns
 * @row current row
 * @col current column
 */
int getCellVal(char **array, int nrows, int ncolumns, int row, int col) {
	if (row >= 0 && row < nrows && col >= 0 && col < ncolumns) {
		return *(*(array + row) + col) == 'x' ? 1 : 0;
	}
	else return 0;
}
