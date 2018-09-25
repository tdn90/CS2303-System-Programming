/*
 * board.h
 *
 * This object will be handling the game logic.
 *
 * Created on Sep 22, 2018
 * Author: Dung (Kevin) Nguyen
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
	Board(int dim, long seed, int numAnts, int numBugs);
	~Board();

	void printBoard();
	int getDim();
	int getAllAnts();
	int getAllBugs();
	int getCurrentAnts();
	int getCurrentBugs();

	void updateBoard();
	bool setBoardReady();


private:
	int totalNumAnts;
	int totalNumBugs;
	int currentNumAnts;
	int currentNumBugs;
	int size;
	long seed;
	Organism*** grid;

	Organism **getRandomArr(int numAnts, int numBugs);
	void swap(Organism **arr, int size, int indexOne, int indexTwo);
	void fillInitialBoard(int numAnts, int numBugs);

	int *getEmptyCell(int row, int col);
	bool isEmptyCell(int row, int col, int nextRow, int nextCol);

	int *getAntCell(int row, int col);
	bool isAntCell(int row, int col, int nextRow, int nextCol);

	void checkBreed(int r, int c);
	bool checkStarvation(int r, int c);

	void moveEatAnt(int r, int c, int nextR, int nextC);
	void moveToEmptyCell(int r, int c, int nextR, int nextC);
};

#endif
