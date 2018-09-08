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




/**
 * Fill grid with some initial values other than 'x' or 'o'
 * @array given grid
 * @nrows number of rows
 * @ncolumns number of columns
 * @initVal initial value to be set for each cell in grid
 */
void fillInitGrid(char **array, int nrows, int ncolumns, char initVal) {
	for (int row = 0; row < nrows; row++) {
		for (int col = 0; col < ncolumns; col++) {
			*(*(array + row) + col) = initVal;
		}
	}
}

/**
 *TODO: if a line > the width (columns) then trigger an error
 * Set grid according to configurations given in file
 * @array given grid
 * @nrows number of rows
 * @ncolumns number of columns
 * @fp pointer to the given file
 */
void setGridFromFile(char **array, int nrows, int ncolumns, FILE *fp) {
	int c;
	int curCol = 0;
	int curRow = 0;
	do {
		c = fgetc(fp);
		if (feof(fp)) break;
		if (c == '\n') {
			curRow++;
			curCol = 0;
		}
		else {
			*(*(array + curRow) + curCol) = c;
			curCol++;
		}
	} while (curRow < nrows && curCol <= ncolumns);
}

/**
 * Get the longest line's length in the given file
 * @fp the pointer to a given file
 */
int getMaxLineLength(FILE *fp) {
	int c;
	int currentLen;
	int max = 0;

	do {
		c = fgetc(fp);
		if (feof(fp))
			break;
		if (c == '\n') {
			if (currentLen > max) max = currentLen;
			currentLen = 0;
		} else {
			 currentLen++;
		}
	} while (1);
	return max;
}

