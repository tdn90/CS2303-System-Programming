/**
 * twoD.h
 *
 * @author: Dung (Kevin) Nguyen
 */

#ifndef TWOD_H_
#define TWOD_H_

char** make2Dchar(int nrows, int ncolumns);
void free2DGrid(char **array, int nrows);
void print2DArray(char **array, int nrows, int ncolumns);
int getNeighbors(char **array, int nrows, int ncolumns, int currentR,
		int currentC);
int getCellVal(char **array, int nrows, int ncolumns, int row, int col);

#endif /* 2D_H_ */
