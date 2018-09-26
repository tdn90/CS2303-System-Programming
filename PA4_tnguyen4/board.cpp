#include <iostream>
#include "board.h"

/**
 * Board.cpp
 * @author Dung (Kevin) Nguyen
 */

/**
 * Constructor for creating a board.
 * Pre-condition: numAnts + numBugs < size*size
 * @param dim height and width of the square grid
 * @param seed specified seed given to random generator
 * @param numAnts given number of ants to be filled in the board
 * @param numBugs given number of bugs to be filled in the board
 * @return a pointer to a block of memory allocated for the new board
 */
Board::Board(int dim, int numAnts, int numBugs) {
	size = dim; // set dimension of the board

	// set initial grid
	// declare + allocate memory for 'Organism***'
	grid = new Organism**[size];

	/*
	 * Loop invariant:
	 * r is the cursor moving through the rows of the grid
	 * At the end, r = size
	 */
	// visit every 'Organism**' element
	for (int r = 0; r < size; r++) {
		// allocate a 'Organism *' to each 'Organism**' element
		grid[r] = new Organism*[size];
		// now every element of this array "grid[r]" is an 'Organism*'
	}

	// randomly fill up the initial board given the number of ants and bugs
	fillInitialBoard(numAnts, numBugs);

	totalNumAnts = numAnts; // keep track of total number of ants appear in game
	totalNumBugs = numBugs; // keep track of total number of bugs appear in game
	currentNumAnts = numAnts; // keep track of the remaining (or current) ants
	currentNumBugs = numBugs; // keep track of the remaining (or current) bugs
}

/**
 * Helper function for constructor
 * Randomly fill up the initial configuration of the board
 * Pre-condition: numAnts + numBugs < total cells in the grid
 * @param numAnts number of ants to be filled
 * @param numBugs number of bugs to be filled
 */
void Board::fillInitialBoard(int numAnts, int numBugs) {
	/* Make a 1D array of pointers to Organism
	 * where all the ants and bugs given are put in randomly
	 */
	Organism **arr = getRandomArr(numAnts, numBugs);

	/*
	 * Loop invariant:
	 * r is the current row in grid
	 * c is current column in grid
	 * i is current index in arr
	 * Truth: number of cells in grid = number of elements in arr = size * size
	 */
	int i = 0; // keep track of current index in arr
	for (int r = 0; r < size; r++) {
		for (int c = 0; c < size; c++) {
			if (arr[i]) { // if there is an Organism present
				grid[r][c] = arr[i]; // assign it to the according position in grid
				grid[r][c]->initCoord(r, c); // change its coord to the current [r,c]
				arr[i] = (Organism *) NULL; // make this null so we can delete later
			}
			i++; // done with arr[i], move on to next element
		}
	}
	// now every element in arr[i] is null pointer
}

/**
 * Generate a 1D array that is randomly filled with the
 * given number of ants and bugs
 * @param numAnts given number of ants
 * @param numBugs given number of bugs
 * @return a 1D array randomly filled with given number of ants and given number of bugs
 */
Organism **Board::getRandomArr(int numAnts, int numBugs){
	/*
	 * Declare and allocate memory for a 1D array of pointers to Organism
	 */
	Organism **arr = new Organism*[size * size];
	int i = 0; // i is the current index in arr

	// Essentially fill up arr with ants first and then bugs sequentially
	/*
	 * Loop invariant:
	 * numAnts will keep decreasing
	 * Stop when numAnts = 0
	 */
	// fill up ants
	while (numAnts > 0) {
		// Create new ant and put it in arr, set default position 0,0
		arr[i++] = new Ant(0,0);
		numAnts--;
	}

	/*
	 * Loop invariant:
	 * numBugs will keep decreasing
	 * Stop when numAnts = 0
	 */
	// fill up bugs
	while (numBugs > 0) {
		// Create new bug and put it in arr, set default position 0,0
		arr[i++] = new Doodlebug(0,0);
		numBugs--;
	}

	/*
	 * Loop invariant:
	 * j is the current index of arr, start from beginning
	 * At the end of the loop, j = i
	 */
	// Essentially go through the array and shuffle everything randomly
	for (int j = 0; j < i; j++) {
		int randomIndex = rand() % (size * size); // get random index to swap
		// swap Organism in current index with random index
		swap(arr, size*size, j, randomIndex);
	}
	return arr;
}

/**
 * Helper function for getRandomArr
 * Swap two elements at two given index with each other
 * @arr given array of Organism pointers
 * @size size of the given array
 * @indexOne first index to be swapped
 * @indexTwo second index to be swapped
 */
void Board::swap(Organism **arr, int size, int indexOne, int indexTwo) {
	Organism * temp = arr[indexOne];
	arr[indexOne] = arr[indexTwo];
	arr[indexTwo] = temp;
}

/**
 * Free the memory given to the 2D grid to prevent memory leak
 */
Board::~Board() {
	// Loop invariant: i is the current row in the grid
	// Loop through each row in grid and delete the organism
	for (int i = 0; i < size; i++) {
		delete[] grid[i];
	}
	delete[] grid;
}

/**
 * Print out the current representation of the board
 */
void Board::printBoard() {
	/*
	 * Loop invariant:
	 * r is current row in the grid
	 * c is current column in the grid
	 */
	for (int r = 0; r < size; r++) {
		for (int c = 0; c < size; c++) {
			if (grid[r][c]) // if there is organism, print out its representation
				std::cout << grid[r][c]->draw();
			else // otherwise the cell is empty
				std::cout << EMPTY_CELL;
		}
		std::cout << "\n";
	}
}

/**
 * @return total number of ants throughout the course of simulation
 */
int Board::getAllAnts() {
	return totalNumAnts;
}

/**
 * @return total number of bugs throughout the course of simulation
 */
int Board::getAllBugs() {
	return totalNumBugs;
}

/**
 * @return current number of ants
 */
int Board::getCurrentAnts() {
	return currentNumAnts;
}

/**
 * @return current number of bugs
 */
int Board::getCurrentBugs() {
	return currentNumBugs;
}


/**
 * Attempt to find the cell of next valid (empty cell) move.
 * @param current row
 * @param current column
 * @return an array of 2 integers that represent the coordinate of next valid move.
 * Return NULL POINTER if no valid move is found
 */
int *Board::getEmptyCell(int row, int col) {
	/* prepare a 2D array to be able to hold maximum number of moves
	 * Each row represent a valid coordinate
	 */
	int potentialMoves[4][2];
	int numValidMove = 0;

	// check top
	if (isEmptyCell(row, col, row - 1, col)) {
		// if valid, add this to potentialMoves
		potentialMoves[numValidMove][0] = row - 1;
		potentialMoves[numValidMove++][1] = col;
	}

	// check right
	if (isEmptyCell(row, col, row, col + 1)) {
		// if valid, add this to potentialMoves
		potentialMoves[numValidMove][0] = row;
		potentialMoves[numValidMove++][1] = col + 1;
	}

	// check bottom
	if (isEmptyCell(row, col, row + 1, col)) {
		// if valid, add this to potentialMoves
		potentialMoves[numValidMove][0] = row + 1;
		potentialMoves[numValidMove++][1] = col;
	}

	// check left
	if (isEmptyCell(row, col, row, col - 1)) {
		// if valid, add this to potentialMoves
		potentialMoves[numValidMove][0] = row;
		potentialMoves[numValidMove++][1] = col - 1;
	}

	// if no empty cell is found, then return null pointer
	if (numValidMove == 0) {
		return (int *) NULL;
	}


	// otherwise allocate memory and create a coordinate array
	int *nextCell = new int[2];
	int randomIndex = rand() % numValidMove; // pick a random move from potential moves
	// store this random move coordinate to nextCell
	nextCell[0] = potentialMoves[randomIndex][0];
	nextCell[1] = potentialMoves[randomIndex][1];
	return nextCell;
}

/**
 * Check valid move for empty cell
 * @param curRow current row
 * @param curCol current column
 * @param nextRow potential move's row
 * @param nextCol potential move's column
 * @return true if a move is possible from current cell to next empty cell, false otherwise
 */
bool Board::isEmptyCell(int curRow, int curCol, int nextRow, int nextCol) {
	// check if out of bound
	if (nextRow >= size || nextRow < 0 || nextCol >= size || nextCol < 0)
		return false; //out of bound
	return !grid[nextRow][nextCol]; // check if empty
}

/**
 * Attempt to find the valid neighbor cell that contain an ant
 * @param row current row
 * @param col current column
 * @return a 1x2 array representing the coordinate of the ant.
 * Return null pointer if no such cell is found.
 */
int *Board::getAntCell(int row, int col) {
	/* prepare a 2D array to be able to hold maximum number of moves
	 * Each row represent a valid coordinate
	 */
	int potentialMoves[4][2];
	int numAntCell = 0;

	// check top
	if (isAntCell(row, col, row - 1, col)) {
		// if this cell is valid and contains the ant, add to potentialMoves
		potentialMoves[numAntCell][0] = row - 1;
		potentialMoves[numAntCell++][1] = col;
	}

	// check right
	if (isAntCell(row, col, row, col + 1)) {
		// if this cell is valid and contains the ant, add to potentialMoves
		potentialMoves[numAntCell][0] = row;
		potentialMoves[numAntCell++][1] = col + 1;
	}

	// check bottom
	if (isAntCell(row, col, row + 1, col)) {
		// if this cell is valid and contains the ant, add to potentialMoves
		potentialMoves[numAntCell][0] = row + 1;
		potentialMoves[numAntCell++][1] = col;
	}

	// check left
	if (isAntCell(row, col, row, col - 1)) {
		// if this cell is valid and contains the ant, add to potentialMoves
		potentialMoves[numAntCell][0] = row;
		potentialMoves[numAntCell++][1] = col - 1;
	}

	// no valid cell that contains ant are found, return null pointer
	if (numAntCell == 0) {
		return (int *) NULL;
	}


	// if there is at least one available, allocate memory for its coordinate
	int *nextCell = new int[2];
	// get random valid ant cell
	int randomIndex = rand() % numAntCell;
	// assign ant cell to nextCell
	nextCell[0] = potentialMoves[randomIndex][0];
	nextCell[1] = potentialMoves[randomIndex][1];
	return nextCell;
}

/**
 * Check if grid[nextRow][nextCol] is valid cell and contains the ant
 * @param row current row
 * @param col current column
 * @param nextRow potential next move's row
 * @param nextCol potential next move's column
 * @return true if grid[nextRow][nextCol] is valid cell and contains the ant; false otherwise
 */
bool Board::isAntCell(int row, int col, int nextRow, int nextCol) {
	//check out of bound
	if (nextRow >= size || nextRow < 0 || nextCol < 0 || nextCol >= size)
		return false; //out of bound
	else {
		// check if there is some organism in next cell and whether it is an ant
		if (grid[nextRow][nextCol] && grid[nextRow][nextCol]->isPrey())
			return true;
		return false;
	}
}

/**
 * This is the function representing the game's logic
 * Update the board from current state to next state, according to game's rule
 */
void Board::updateBoard() {
	// scan and update the bugs first
	// Loop invariant: r is row and c is column
	for (int r = 0; r < size; r++) {
		for (int c = 0; c < size; c++) {
			/* some organism is here, can move and it is a doodlebug.
			 * canMove() act as a helper to determine whether the bug has
			 * been moved. We certainly don't want to move the bug twice in
			 * one turn
			 */
			if (grid[r][c] && grid[r][c]->canMove() && !grid[r][c]->isPrey()) {
				// Find ants to eat first
				int *antCell = getAntCell(r, c);
				if (!antCell) { // no ants around
					// attempt to find empty cell
					int *emptyCell = getEmptyCell(r, c);
					if (emptyCell) { // there is an empty cell, move there
						moveToEmptyCell(r, c, emptyCell[0], emptyCell[1]);
						delete[] emptyCell; // prevent memory leak
					} else { //get stuck, cannot breed either
						grid[r][c]->move(r, c); //update stepSurvived
						checkStarvation(r, c); // if starved then kill it
					}
				} else { // there is some ant. Eat it! Yummy!
					int nextRow = antCell[0];
					int nextCol = antCell[1];
					moveEatAnt(r, c, nextRow, nextCol);
					delete[] antCell; // prevent memory leak
				}
			}
		}
	}

	// Then update ants
	// Loop invariant: r is row and c is column
	for (int r = 0; r < size; r++) {
		for (int c = 0; c < size; c++) {
			/* some organism is here, can move and it is an ant.
			 * canMove() act as a helper to determine whether the ant has
			 * been moved. We certainly don't want to move the ant twice in
			 * one turn
			 */
			if (grid[r][c] && grid[r][c]->canMove() && grid[r][c]->isPrey()) {
				int *emptyCell = getEmptyCell(r, c); // try to find empty cell
				if (emptyCell) { // found an empty cell, jump there
					moveToEmptyCell(r, c, emptyCell[0], emptyCell[1]);
					checkBreed(emptyCell[0], emptyCell[1]); // see if breed
					delete[] emptyCell; //done with this, delete to prevent memory leak
				} else { // oops! Get stuck here!
					grid[r][c]->move(r, c); // update stepSurvived
				}
			}
		}
	}
}

/**
 * Move the bug to eat the ant on the next move's cell, which is grid[nextR][nextC]
 * @param r current row
 * @param c current col
 * @param nextR next move's row
 * @param nextC next move's column
 */
void Board::moveEatAnt(int r, int c, int nextR, int nextC) {
	delete grid[nextR][nextC]; //remove ant
	currentNumAnts--;
	grid[nextR][nextC] = grid[r][c]; // move doodlebug to new grid
	grid[r][c] = (Organism *) NULL; // old grid turns empty
	grid[nextR][nextC]->move(nextR, nextC); // increase survival steps
	((Doodlebug *) grid[nextR][nextC])->eat(); // reset lastEaten (just ate)
	checkBreed(nextR, nextC); // if breed then make new doodlebug
}

/**
 * Move the Organism to the empty cell
 * @param r current row
 * @param c current col
 * @param nextR next move's row
 * @param nextC next move's column
 */
void Board::moveToEmptyCell(int r, int c, int nextR, int nextC) {
	grid[nextR][nextC] = grid[r][c]; // move to new empty grid
	grid[r][c] = (Organism *) NULL; // set old grid to empty
	grid[nextR][nextC]->move(nextR, nextC); // increase survival steps
	// if it is a bug, check starvation first and then check breed
	if (!grid[nextR][nextC]->isPrey() && !checkStarvation(nextR, nextC))
		checkBreed(nextR, nextC);
}

/**
 * Check to see if the organism in current cell can breed.
 * If yes, then choose an empty cell around it and put new Organism there.
 * @param r current row
 * @param c current col
 */
void Board::checkBreed(int r, int c) {
	if (grid[r][c]->readyToBreed()) {
		int *emptyCell = getEmptyCell(r, c); // attempt to find empty cell
		if (emptyCell) { // if there is an empty cell
			// create new Organism and put it in the empty cell
			grid[emptyCell[0]][emptyCell[1]] = grid[r][c]->breed(emptyCell[0], emptyCell[1]);
			// just update the board's fields
			if (grid[r][c]->isPrey()) {
				totalNumAnts++;
				currentNumAnts++;
			}
			else {
				totalNumBugs++;
				currentNumBugs++;
			}
			delete[] emptyCell;
		}
	}
}

/**
 * Check whether the bug in the given cell is starved to death.
 * If yes, remove it from the grid
 * @param r current row
 * @param c current column
 * @return true if the bug in given cell is starved, false otherwise
 */
bool Board::checkStarvation(int r, int c) {
	if (((Doodlebug *) grid[r][c])->starved()) {
		delete grid[r][c]; // prevent memory leak
		grid[r][c] = (Organism *) NULL; // set current cell to null
		currentNumBugs--;
		return true;
	}
	return false;
}

/**
 * Set the board ready for next state
 * @return true if the board can move on to next state, false if every organism died.
 */
bool Board::setBoardReady() {
	bool ready = false;
	// Loop invariant: r is row, c is column
	for (int r = 0; r < size; r++) {
		for (int c = 0; c < size; c++) {
			if (grid[r][c]) { // something here
				grid[r][c]->readyToMove(); //set it to ready state
				ready = true; // oh, something is alive, then we can have a next state
			}
		}
	}
	return ready;
}

