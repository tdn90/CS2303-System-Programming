/* Game of Life
 */

#include <stdio.h>
#include <stdlib.h>
#include "twoD.h"
#include "term.h"
#include "gridConfig.h"
#include "readFile.h"

/**
 * Play one round of game of life
 * @nr number of rows
 * @nc number of columns
 * @current current configuration
 * @next next generation's configuration
 *
 * @author Dung (Kevin) Nguyen
 */
void playOne(unsigned int nr, unsigned int nc, char **current, char **next) {
	for (unsigned int row = 0; row < nr; row++) {
		for (unsigned int col = 0; col < nc; col++) {
			int neighbors = getNeighbors(current, nr, nc, row, col);
			if ((*(*(current + row) + col) == LIVE
					&& (neighbors == 2 || neighbors == 3))
					|| (*(*(current + row) + col) == RIP && neighbors == 3)) {
				*(*(next + row) + col) = LIVE;
			} else {
				*(*(next + row) + col) = RIP;
			}
		}
	}
}

/** Main function.
 * @param argc Number of words on the command line.
 * @param argv Array of pointers to character strings containing the
 *    words on the command line.
 * @return 0 if success, 1 if invalid command line or unable to open file.
 *
 * @author: Dung (Kevin) Nguyen
 */
int main(int argc, char **argv) {
	printf("Game of Life\n");

	char *inputFileName; // Name of file containing initial grid
	FILE *input; // Stream descriptor for file containing initial grid
	int nrows; // Number of rows in the grid
	int ncolumns; // Number of columns in the grid
	int gens; // Number of generations to produce
	int doPrint; // 1 if user wants to print each generation, 0 if not
	int doPause; // 1 if user wants to pause after each generation, 0 if not
	char **gridA; // A 2D array to hold the pattern given in the file

	// Three main 2D array (grid) for game logic
	char **firstGen;
	char **secondGen;
	char **thirdGen;

	// See if there are the right number of arguments on the command line
	if ((argc < 5) || (argc > 7)) {
		// If not, tell the user what to enter.
		printf("Usage:\n");
		printf("  ./life rows columns generations inputFile [print] [pause]\n");
		return EXIT_FAILURE;
	}

	/* Save the command-line arguments.
	 Also need to check if print and/or pause arguments were entered,
	 and if so, what they were.
	 */
	nrows = atoi(argv[1]); // Convert from character string to integer.
	ncolumns = atoi(argv[2]);
	gens = atoi(argv[3]);
	if (gens <= 0) {  // gens must be positive
		printf("Usage:\n");
		printf("  ./life rows columns generations inputFile [print] [pause]\n");
		printf("The generators argument must be greater than 0.\n");
		return EXIT_FAILURE;
	}
	inputFileName = argv[4];

	// Check for [print] and [pause]
	if (argc > 5) { // [print] is provided
		if (*argv[5] == 'y')
			doPrint = 1;
		else if (*argv[5] == 'n')
			doPrint = 0;
		else {
			printf("Option [print] should either be 'y' or 'n'\n");
			return EXIT_FAILURE;
		}

		if (argc == 7) { // [pause is provided]
			if (*argv[6] == 'y')
				doPause = 1;
			else if (*argv[6] == 'n')
				doPause = 0;
			else {
				printf("Option [pause] should either be 'y' or 'n'\n");
				return EXIT_FAILURE;
			}
		} else
			doPause = 0;
	} else
		doPrint = 0;

	// Allocate memory for gridA
	gridA = make2Dchar(nrows, ncolumns);
	// Check if memory allocation succeeded.
	if (gridA == (char **) NULL) {
		printf("Unable to allocate memory for the grid.\n");
		return EXIT_FAILURE;
	}

	// Allocate memory for firstGen
	firstGen = make2Dchar(nrows, ncolumns);
	// Check if memory allocation succeeded.
	if (firstGen == (char **) NULL) {
		printf("Unable to allocate memory for the grid.\n");
		return EXIT_FAILURE;
	}

	// Allocate memory for secondGen
	secondGen = make2Dchar(nrows, ncolumns);
	// Check if memory allocation succeeded.
	if (secondGen == (char **) NULL) {
		printf("Unable to allocate memory for the grid.\n");
		return EXIT_FAILURE;
	}

	// Allocate memory for thirdGen
	thirdGen = make2Dchar(nrows, ncolumns);
	// Check if memory allocation succeeded.
	if (thirdGen == (char **) NULL) {
		printf("Unable to allocate memory for the grid.\n");
		return EXIT_FAILURE;
	}

	// Eventually, need to try to open the input file.
	input = fopen(inputFileName, "r");
	if (!input) {
		printf("Unable to open input file: %s\n", inputFileName);
		return EXIT_FAILURE;
	}

	// Fill up the original grid with '+' values
	fillInitGrid(gridA, nrows, ncolumns);
	fillInitGrid(firstGen, nrows, ncolumns);

	// Set initial grid based on configuration given in file
	if (setGridFromFile(gridA, nrows, ncolumns, input) == EXIT_FAILURE) {
		printf("Grid cannot contains all cells given in file\n");
		return EXIT_FAILURE;
	}

	fillUpGrid(gridA, nrows, ncolumns); // replace all elements in grid by blanks except for 'x'

	rewind(input); //Put the pointer to the beginning of the file again
	int maxHeight = getNumLines(input);

	rewind(input);
	int maxWidth = getMaxLineLength(input);
	fclose(input);

	centerGrid(gridA, firstGen, nrows, ncolumns, maxWidth, maxHeight);
	free2DGrid(gridA, nrows); //gridA is done with usage. Free the memory

	fillUpGrid(firstGen, nrows, ncolumns);

	/*
	 * Game Loop
	 */
	int termination_state = EXIT_CODE_3;
	char **p = firstGen;
	char **q = secondGen;
	char **spare = thirdGen;
	unsigned int currentGen = 0;

	do {
		if (doPrint) { //Printing current generation enabled
			printf("--------------------------------\n");
			printf("Generation %d:\n", currentGen);
			print2DArray(p, nrows, ncolumns);
			printf("\n");
		}

		playOne(nrows, ncolumns, p, q);
		currentGen++;

		// Terminate under condition 1
		if (allDead(q, nrows, ncolumns)) {
			termination_state = EXIT_CODE_1;
			break;
		}

		// Terminate under condition 2
		if (equalsGrid(p, q, nrows, ncolumns)
				|| equalsGrid(q, spare, nrows, ncolumns)) {
			termination_state = EXIT_CODE_2;
			break;
		}

		if (currentGen == gens)
			break; // Terminate under condition 3

		if (doPause) { // doPause is specified
			printf(
					"Press enter to continue, or Ctrl+C to stop the program: \n");
			getchar();
		}

		char **temp = p;
		p = q;
		q = spare;
		spare = temp;
	} while (1);

	// Print final configuration
	printf("-----------------------------------------\n");
	printf("Final Configuration:\nGeneration %d:\n", currentGen);
	print2DArray(q, nrows, ncolumns);
	printf("-----------------------------------------\n");

	// Done with all grids, clear them up
	free2DGrid(firstGen, nrows);
	free2DGrid(secondGen, nrows);
	free2DGrid(thirdGen, nrows);

	printf("Game ends after %d generations.\n", currentGen);
	switch (termination_state) {
	case EXIT_CODE_1:
		printf("All organisms died. Exit under condition 1.\n");
		break;
	case EXIT_CODE_2:
		printf("Steady state was reached. Exit under condition 2.\n");
		break;
	case EXIT_CODE_3:
		printf(
				"Predefined number of generations is reached. Exit under condition 3.\n");
		break;
	}

	return EXIT_SUCCESS;
}
