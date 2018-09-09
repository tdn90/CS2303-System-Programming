#include <stdio.h>
#include <stdlib.h>
#include "gridConfig.h"

/**
 * Fill grid with INITVAL
 * @array given grid
 * @nrows number of rows
 * @ncolumns number of columns
 *
 * @author Dung (Kevin) Nguyen
 */
void fillInitGrid(char **array, int nrows, int ncolumns) {
	for (int row = 0; row < nrows; row++) {
		for (int col = 0; col < ncolumns; col++) {
			*(*(array + row) + col) = INITVAL;
		}
	}
}

/**
 * Set grid according to configurations given in file
 * @array given grid
 * @nrows number of rows
 * @ncolumns number of columns
 * @fp pointer to the given file
 * @return 0 if everything is normally set, 1 otherwise
 *
 * @author: Dung (Kevin) Nguyen
 */
int setGridFromFile(char **array, int nrows, int ncolumns, FILE *fp) {
	int c;
	int curCol = 0;
	int curRow = 0;
	do {
		c = fgetc(fp);
		if (feof(fp))
			break;
		if (c == '\n') {
			curRow++;
			curCol = 0;
		} else {
			if (curCol == ncolumns) { // line's length > grid width
				return EXIT_FAILURE;
			}
			*(*(array + curRow) + curCol) = (c == 'x') ? 'x' : ' ';
			curCol++;
		}
	} while (curRow < nrows);
	if ((c = fgetc(fp)) != EOF)
		return EXIT_FAILURE; // more lines than grid height
	return 0;
}

/**
 * Fill up empty spots in the grid
 * @array given grid
 * @nrows number of rows
 * @ncolumns number of columns
 * @author: Dung (Kevin) Nguyen
 */
void fillUpGrid(char **array, int nrows, int ncolumns) {
	for (int row = 0; row < nrows; row++) {
		for (int col = 0; col < ncolumns; col++) {
			if (*(*(array + row) + col) == INITVAL) {
				*(*(array + row) + col) = RIP;
			}
		}
	}
}

/**
 * @original original grid
 * @centered centered grid
 * @nrows number of rows
 * @ncolumns number of columns
 * @maxWidth maxWidth of grid given in file
 * @maxHeight max height of grid given in file
 *
 * @author: Dung (Kevin) Nguyen
 */
void centerGrid(char **original, char **centered, int nrows, int ncolumns,
		int maxWidth, int maxHeight) {
	int horizontalDiff = ncolumns - maxWidth;
	int verticalDiff = nrows - maxHeight;

	int topPadding = verticalDiff / 2;
	int leftPadding = horizontalDiff / 2;

	for (int row = 0; row < maxHeight; row++) {
		for (int col = 0; col < maxWidth; col++) {
			*(*(centered + row + topPadding) + col + leftPadding) = *(*(original
					+ row) + col);
		}
	}
}

