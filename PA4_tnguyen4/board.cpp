#include <iostream>

#include "board.h"

/**
 * Constructor for creating a board
 * @param dim height and width of the square grid
 * @seed specified seed given to random generator
 * @return a pointer to a block of memory allocated for the new board
 */
Board::Board(int dim, long seed) {
	size = dim;
	this->seed = seed;
	// declare / allocate memory for 'Organism***'
	grid = new Organism**[size];

	// visit every 'Organism**' element
	for (int r = 0; r < size; r++) {
		// allocate a 'Organism *' to each 'Organism**' element
		grid[r] = new Organism*[size];
		// now every element of this array "grid[r]" is an 'Organism*'

		/* visit every 'Organism *' element
		for (size_t c = 0; c < size; c++) {
			grid[r][c] = new Organism*;
		}
		*/
	}
}

/**
 * Free the memory given to the 2D grid
 */
Board::~Board() {
	for (int i = 0; i < size; i++) {
		delete[] grid[i];
	}
	delete[] grid;
}

/**
 * Print out the current representation of the board
 */
void Board::printBoard() {
	for (int r = 0; r < size; r++) {
		for (int c = 0; c < size; c++) {
			if (grid[r][c]) std::cout << grid[r][c]->draw();
			else std::cout << '-';
		}
		std::cout << "\n";
	}
}

/**
 * Get dimension of the grid
 * @return the width / height of the square grid
 */
int Board::getDim() {
	return size;
}


/**
 * Set the specific cell to the given organism
 * @param row given row, must be less than the dimension of grid
 * @param col given column, must be less than dimension of grid
 * @param organism the given organism to place in
 */
void Board::setCell(int row, int col, Organism * organism) {
	if (grid[row][col]) delete grid[row][col];
	grid[row][col] = organism;
}

/**
 * Get the cell of next valid (empty cell) move.
 * @param current row
 * @param current column
 * @return an array of 2 integers that represent the coordinate of next valid move.
 * Return NULL POINTER if no valid move is found
 */
int *Board::getEmptyCell(int row, int col, int *nextCell) {
	int potentialMoves[4][2];
	int numValidMove = 0;

	// check top
	if (isEmptyCell(row, col, row - 1, col)) {
		potentialMoves[numValidMove][0] = row - 1;
		potentialMoves[numValidMove++][1] = col;
	}

	// check right
	if (isEmptyCell(row, col, row, col + 1)) {
		potentialMoves[numValidMove][0] = row;
		potentialMoves[numValidMove++][1] = col+1;
	}

	// check bottom
	if (isEmptyCell(row, col, row + 1, col)) {
		potentialMoves[numValidMove][0] = row + 1;
		potentialMoves[numValidMove++][1] = col;
	}

	// check left
	if (isEmptyCell(row, col, row, col - 1)) {
		potentialMoves[numValidMove][0] = row;
		potentialMoves[numValidMove++][1] = col - 1;
	}

	if (numValidMove == 0) return (int *) NULL;
	nextCell = new int[2];
	int randomIndex = rand() % numValidMove;
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
	if (nextRow >= size || nextRow < 0 || nextCol >= size || nextCol < 0) return false; //out of bound
	return !grid[nextRow][nextCol];
}

//TODO
int *Board::getAntCell(int row, int col, int *nextCell) {
	int potentialMoves[4][2];
	int numAntCell = 0;

	// check top
	if (isAntCell(row, col, row - 1, col)) {
		potentialMoves[numAntCell][0] = row - 1;
		potentialMoves[numAntCell++][1] = col;
	}

	// check right
	if (isAntCell(row, col, row, col + 1)) {
		potentialMoves[numAntCell][0] = row;
		potentialMoves[numAntCell++][1] = col + 1;
	}

	// check bottom
	if (isAntCell(row, col, row + 1, col)) {
		potentialMoves[numAntCell][0] = row + 1;
		potentialMoves[numAntCell++][1] = col;
	}

	// check left
	if (isAntCell(row, col, row, col - 1)) {
		potentialMoves[numAntCell][0] = row;
		potentialMoves[numAntCell++][1] = col - 1;
	}

	if (numAntCell == 0)
		return (int *) NULL;
	nextCell = new int[2];
	int randomIndex = rand() % numAntCell;
	nextCell[0] = potentialMoves[randomIndex][0];
	nextCell[1] = potentialMoves[randomIndex][1];
	return nextCell;
}

//TODO
bool Board::isAntCell(int row, int col, int nextRow, int nextCol) {
	if (nextRow >= size || nextCol >= size) return false; //out of bound
	else {
		// check if there is some organism in next cell and whether it is an ant
		if (grid[nextRow][nextCol] && grid[nextRow][nextCol]->isPrey()) return true;
		return false;
	}
}

//TODO: implement updateBoard
void Board::updateBoard() {
	// update the bugs first
	for (int r = 0; r < size; r++) {
		for (int c = 0; c < size; c++) {
			// some organism is here and it is a doodlebug
			if (grid[r][c] && !grid[r][c]->isPrey()) {
				// Find ants to eat first
				int *antCell = (int *) NULL;
				antCell = getAntCell(r,c,antCell);
				if (!antCell) { // no ants around
					int *emptyCell = (int *) NULL;
					emptyCell = getEmptyCell(r,c, emptyCell);
					if (emptyCell) {
						moveToEmptyCell(r,c,emptyCell[0], emptyCell[1]);
					}
					else { //get stuck, cannot breed either
						grid[r][c]->setCoords(r, c); //update stepSurvived
						checkStarvation(r,c);
					}
				}
				else { // there is some ant. Eat it!
					int nextRow = antCell[0];
					int nextCol = antCell[1];
					moveEatAnt(r,c,nextRow, nextCol);
				}
			}
		}
	}

	// Then update ants
	for (int r = 0; r < size; r++) {
		for (int c = 0; c < size; c++) {
			if (grid[r][c] && grid[r][c]->isPrey()) {
				int *emptyCell = (int *) NULL;
				emptyCell = getEmptyCell(r,c, emptyCell);
				if (emptyCell) {
					moveToEmptyCell(r,c,emptyCell[0],emptyCell[1]);
					checkBreed(emptyCell[0],emptyCell[1]);
				}
				else {
					grid[r][c]->setCoords(r, c);
				}
			}
		}
	}
}

//TODO
void Board::moveEatAnt(int r, int c, int nextR, int nextC) {
	delete grid[nextR][nextC]; //remove ant
	grid[nextR][nextC] = grid[r][c]; // move doodlebug to new grid
	grid[r][c] = (Organism *) NULL; // old grid turns empty
	((Doodlebug *) grid[nextR][nextC])->eat(); // reset lastEaten (just ate)
	grid[nextR][nextC]->setCoords(nextR, nextC); // increase survival steps
	checkBreed(nextR, nextC);
}

//TODO
void Board::moveToEmptyCell(int r, int c, int nextR, int nextC) {
	grid[nextR][nextC] = grid[r][c]; // move to new empty grid
	grid[r][c] = (Organism *) NULL; // set old grid to empty
	grid[nextR][nextC]->setCoords(nextR, nextC); // increase survival steps
	if (!grid[nextR][nextC]->isPrey() && !checkStarvation(nextR, nextC)) checkBreed(nextR, nextC);
}

//TODO
void Board::checkBreed(int r, int c) {
	if (grid[r][c]->readyToBreed()) {
		int *emptyCell = (int *) NULL;
		emptyCell = getEmptyCell(r, c, emptyCell);
		if (emptyCell) // if there is an empty cell
			grid[r][c]->breed(emptyCell[0], emptyCell[1]);
	}
}

//TODO
bool Board::checkStarvation(int r, int c) {
	if (((Doodlebug *)grid[r][c])->starved()) {
		delete grid[r][c];
		return true;
	}
	return false;
}

/**
 * Fill up the initial configuration of the board
 * Pre-condition: numAnts + numBugs < total cells in the grid
 * @param numAnts number of ants to be filled
 * @param numBugs number of bugs to be filled
 * For now, just for the sake of a working program, we will fill the bugs
 * first from top left; and fill the ants from bottom right.
 * TODO: fill this up randomly if time permits
 */
void Board::fillInitialBoard(int numAnts, int numBugs) {
	// Fill up the ants first from top left
	for (int r = 0; r < size && numAnts > 0; r++) {
		for (int c = 0; c < size && numAnts > 0; c++) {
			grid[r][c] = new Ant(r,c);
			numAnts--;
		}
	}

	// Fill up the bugs first from bottom right
	for (int r = size-1; r >= 0 && numBugs > 0; r--) {
		for (int c = size-1; c >= 0 && numBugs > 0; c--) {
			grid[r][c] = new Doodlebug(r, c);
			numBugs--;
		}
	}
}


