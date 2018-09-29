#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/* Program which reads numbers from the command line,
 * outputs them, sorts them in descending order, and outputs the sorted list.
 *
 * Usage:
 *         ./sorttest2 size [option]
 * Example:
 *         ./sorttest2 2014 0
 *
 */

#define MAX_RAND 100000

/** Main program
 * @param argc Number of words on the command line
 * @param argv[] Array of character strings, the words from the command line.
 * @return 0 if success, 1 if error (wrong number of arguments)
 */

int main (int argc, const char* argv[]) {
	int size; // size of randomly allocated array
	int *nums; // space to store numbers entered from the command line.

	int choice = 0; // specify which sort function to use

	/* Usage of choice:
	 * 0 is default (use the function provided in the assignment
	 * 1 is mysort1()
	 * 2 is mysort2()
	 */
	// check arguments
	if (argc != 2 && argc != 3) {
		printf("Invalid number of arguments.\nUsage:\n");
		printf("./sorttest2 size [choice]\n");
		printf("where:\n\tSize is the size of the randomized array.\n");
		printf("\tChoice is an optional argument from 0 to 2 to choose which version of sort to use.\n");
		return EXIT_FAILURE;
	}
	size = atoi(argv[1]); // pass argument into size
	if (argc == 3) {
		choice = atoi(argv[2]);
		// check appropriate choice argument
		if (choice > 2 || choice < 0) {
			printf("\tChoice is an optional argument from 0 to 2 to choose which version of sort to use.\n");
			return EXIT_FAILURE;
		}
	}

	// allocate memory for array of random numbers of length [size]
	nums = (int*) calloc(size, sizeof(int));
	if (nums == NULL) {
		fprintf(stderr,
				"Unable to allocate enough memory to hold the numbers.\n");
	}

	// popularize the array with random numbers
	for (int i = 0; i < size; i++) {
		nums[i] = rand() % MAX_RAND;
	}

	// Now print, sort, and print the array, and time how long the sorting took.
	timesort(nums, size, choice);

	return 0; // Indicate success!
}
