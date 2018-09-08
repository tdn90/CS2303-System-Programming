/* Game of Life
*/

#include <stdio.h>
#include <stdlib.h>
#include "twoD.h"

/**
 * @array given grid
 * @nrows number of rows
 * @ncolumns number of columns
 */
int gridMalloc(char **array, int nrows, int ncolumns) {
	// Allocate an array to hold the grid.
	array = make2Dchar(nrows, ncolumns);
	// Check if memory allocation succeeded.
	if (array == (char **) NULL) {
		printf("Unable to allocate memory for the grid.\n");
		return EXIT_FAILURE;
	}
	return 0;
}

/** Main function.
 * @param argc Number of words on the command line.
 * @param argv Array of pointers to character strings containing the
 *    words on the command line.
 * @return 0 if success, 1 if invalid command line or unable to open file.
 *
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
	char **gridA; // A 2D array to hold the pattern
	char **gridB; // 2D array to hold the pattern (centered)

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
	   A switch statement might be handy here.
	*/
	nrows = atoi(argv[1]); // Convert from character string to integer.
	ncolumns = atoi(argv[2]);
	gens = atoi(argv[3]);
	inputFileName = argv[4];

	if (argc > 5) { // [print] is provided
		doPrint = (*argv[5] == 'y' ? 1 : 0);
		if (argc == 7) { // [pause is provided]
			doPause = (*argv[6] == 'y' ? 1 : 0);
		}
		else doPause = 0;
	}
	else doPrint = 0;

	// Allocate memory for gridA
	if (gridMalloc(gridA, nrows, ncolumns) == EXIT_FAILURE) {
		return EXIT_FAILURE;
	}

	// Allocate memory for gridB
	if (gridMalloc(gridB, nrows, ncolumns) == EXIT_FAILURE) {
		return EXIT_FAILURE;
	}

	/* Eventually, need to try to open the input file.
	*/
	input = fopen(inputFileName, "r");
	if (!input) {
		printf("Unable to open input file: %s\n", inputFileName);
		return EXIT_FAILURE;
	}

	/*Once opened, you can read from the file one character at a time with fgetc().
	 * You can read one line at a time using fgets().
	 * You can read from standard input (the keyboard) with getchar().
	*/


	return EXIT_SUCCESS;
}
