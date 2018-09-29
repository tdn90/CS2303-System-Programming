#include <stdio.h>
#include <sys/time.h>
#include "sort.h"

/** Prints an array of integers, one per line.
 * @param nums Array to print
 * @param count Number of elements to print
 */

void print_int_array(int nums[], int count) {
	int i; // Loop counter
	for (i = 0; i < count; i++) {
		printf("%d\n", nums[i]); // Print each array element in turn
	}
}

/** Sorts an array of integers into descending order.
 * Uses the bubble sort algorithm.
 *
 * @param nums Array to sort
 * @param count Number of elements to sort
 */
void sort_descending(int nums[], int count) {
	int round; // How many times left to go through the outer loop.
	int i; // Loop counter for the inner loop
	int inorder; // Used as a boolean (logical). 1 = array is in correct order.
	int temp; // Temporary variable used while swapping array elements

	inorder = 0; // Assume not sorted at the beginning

	// Repeat outer loop, one time less than the size of the array.
	// Terminate early if array is in correct order.
	for (round = count - 1; (round > 0) && (!inorder); round--) {
		inorder = 1; // Assume in correct order, until found otherwise.
		// Repeat inner loop, testing array elements 0 through round
		for (i = 0; i < round; i++) {
			// Compare two adjacent elements of the array
			if (nums[i] < nums[i + 1]) {
				// Not in correct relative order, so swap.
				inorder = 0; // At least one pair had to be swapped
				temp = nums[i]; // Swap!
				nums[i] = nums[i + 1];
				nums[i + 1] = temp;
			}
		}
	}
}

/**
 * My first alternate version of bubble sort
 * Sorts an array of integers into descending order.
 * Uses the bubble sort algorithm.
 *
 * @param nums Array to sort
 * @param count Number of elements to sort
 */
void mySort1(int nums[], int count) {
	int round; // How many times left to go through the outer loop.
	int i; // Loop counter for the inner loop
	int inorder; // Used as a boolean (logical). 1 = array is in correct order.
	int temp; // Temporary variable used while swapping array elements

	inorder = 0; // Assume not sorted at the beginning

	// Repeat outer loop, one time less than the size of the array.
	// Terminate early if array is in correct order.
	for (round = count - 1; (round > 0) && (!inorder); round--) {
		inorder = 1; // Assume in correct order, until found otherwise.
		// Repeat inner loop, testing array elements 0 through round
		for (i = 0; i < round; i++) {
			// Compare two adjacent elements of the array
			if (*(nums + i) < *(nums + i + 1)) {
				// Not in correct relative order, so swap.
				inorder = 0; // At least one pair had to be swapped
				temp = *(nums + i); // Swap!
				*(nums + i) = *(nums + i + 1);
				*(nums + i + 1) = temp;
			}
		}
	}
}

/**
 * My second version of bubble sort, using incrementing pointers
 * Sorts an array of integers into descending order.
 * Uses the bubble sort algorithm.
 *
 * @param nums Array to sort
 * @param count Number of elements to sort
 */

void mySort2(int nums[], int count) {
	int round; // How many times left to go through the outer loop.
	int i; // Loop counter for the inner loop
	int inorder; // Used as a boolean (logical). 1 = array is in correct order.
	int temp; // Temporary variable used while swapping array elements

	inorder = 0; // Assume not sorted at the beginning

	// Repeat outer loop, one time less than the size of the array.
	// Terminate early if array is in correct order.
	for (round = count - 1; (round > 0) && (!inorder); round--) {
		inorder = 1; // Assume in correct order, until found otherwise.
		// Repeat inner loop, testing array elements 0 through round
		i = 0;
		int *current = nums; // preserve nums as a pointer to first element in array
		// loop through the array and check whether it is already in order
		while (i++ < round) {
			int *next = current + 1;  // keep track of the next element
			if (*current < *next) {  // current less than next so out of order
				inorder = 0; // out of order so set this flag to 0 to indicate continuing sorting

				// swap - bubble up
				temp = *current;
				*current = *next;
				*next = temp;
			}
			current++; // move on to next element
		}
	}
}

/** Prints the contents of a timeval struct.
 * @param t Struct to print.
 */
void print_timeval(struct timeval t) {
	printf("Seconds, %ld, Microseconds: %ld\n", t.tv_sec, t.tv_usec);
}

/** Calculates difference between two timestamps. 
 * Note that this takes structs as parameters and returns a struct;
 * it does not use pointers.
 * @param time1 A time stamp
 * @param time2 another timestamp (assumed same as or later than time 1)
 * @return A timeval struct representing time2 - time1
 */
struct timeval timediff(struct timeval time1, struct timeval time2) {
	struct timeval diff;

	// For now, set it to all zeroes
	time_t secDiff = time2.tv_sec - time1.tv_sec;
	suseconds_t microDiff = time2.tv_usec - time1.tv_usec;

	if (microDiff < 0) { // microDiff is negative, need to do more calculation
		time_t secPart = (-microDiff) / MAX_MICROSEC; // extract the second part of microDiff
		suseconds_t microPart = (-microDiff) % MAX_MICROSEC; // extract the microsecond part of microDiff
		diff.tv_sec = secDiff - secPart - 1; // minus 1 because we want to round down to the previous second
		diff.tv_usec = MAX_MICROSEC - microPart;
	} else { // otherwise just set these variables as normal
		diff.tv_sec = secDiff;
		diff.tv_usec = microDiff;
	}
	return diff;
}
