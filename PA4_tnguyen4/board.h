/*
 * board.h
 *
 * Created on Sep 22, 2018
 * 	Author: Dung (Kevin) Nguyen
 */

#ifndef BOARD_H_
#define BOARD_H_

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "organism.h"
#include "ant.h"
#include "doodlebug.h"

class Board {
public:
	Board(int dim, long seed);
	~Board();
	void printBoard();
	int getDim();

	int *getEmptyCell(int row, int col, int *nextCell); // return the valid coordinate to move
	bool isEmptyCell(int row, int col, int nextRow, int nextCol);

	int *getAntCell(int row, int col, int *nextCell);
	bool isAntCell(int row, int col, int nextRow, int nextCol);

	void setCell(int row, int col, Organism * organism);
	void updateBoard();
	void fillInitialBoard(int numAnts, int numBugs);

	void checkBreed(int r, int c);
	bool checkStarvation(int r, int c);

	void moveEatAnt(int r, int c, int nextR, int nextC);
	void moveToEmptyCell(int r, int c, int nextR, int nextC);

private:
	int size;
	long seed;
	Organism*** grid;
};

#endif
