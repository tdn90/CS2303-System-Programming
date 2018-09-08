/**
 * twoD.h
 *
 * @author: Mike Ciaraldi
 */

#ifndef TWOD_H_
#define TWOD_H_

// Function prototypes:
char** make2Dchar(int nrows, int ncolumns);
void print2DArray(char **array, int nrows, int ncolumns);
int getNeighbors(char **array, int nrows, int ncolumns, int currentR, int currentC);
int getCellVal(char **array, int nrows, int ncolumns, int row, int col);
void fillInitGrid(char **array, int nrows, int ncolumns, char initVal);
void setGridFromFile(char **array, int nrows, int ncolumns, FILE *fp);
int getMaxLineLength(FILE *fp);
int getNumLines(FILE *fp);
void fillUpGrid(char **array, int nrows, int ncolumns);
void centerGrid(char **original, char **centered, int nrows, int ncolumns, int maxWidth, int maxHeight);

#endif /* 2D_H_ */
