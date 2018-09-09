#include <stdio.h>
#include <stdlib.h>
#include "term.h"
#include "gridConfig.h"

/**
 * Given equal-sized grid, determine whether their contents are equal.
 * @first first grid
 * @second second grid
 * @nrows number of rows
 * @ncolumns number of columns
 * @return 1 if the two grids are equal, 0 otherwise.
 *
 * @author: Dung (Kevin) Nguyen
 */
int equalsGrid(char **first, char **second, int nrows, int ncolumns) {
	int isEqual = 1;
	for (int row = 0; row < nrows; row++) {
		for (int col = 0; col < ncolumns; col++) {
			if (*(*(first + row) + col) != *(*(second + row) + col)) isEqual = 0;
		}
	}
	return isEqual;
}

/**
 * @array given grid
 * @nrows number of rows
 * @ncolumns number of columns
 * @return 1 if all organisms are dead; 0 otherwise.
 * @author: Dung (Kevin) Nguyen
 */
int allDead(char **array, int nrows, int ncolumns) {
	int result = 1;
	for (int row = 0; row < nrows; row++) {
		for (int col = 0; col < ncolumns; col++) {
			if (*(*(array + row) + col) == LIVE) result = 0;
		}
	}
	return result;
}
