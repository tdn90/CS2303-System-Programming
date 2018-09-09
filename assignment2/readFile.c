#include <stdio.h>
#include <stdlib.h>
#include "readFile.h"

/**
 * Get the longest line's length in the given file
 * @fp the pointer to a given file
 *
 * @author Dung (Kevin) Nguyen
 */
int getMaxLineLength(FILE *fp) {
	int c;
	int currentLen;
	int max = 0;

	do {
		c = fgetc(fp);
		if (feof(fp))
			break;
		if (c == '\n') {
			if (currentLen > max)
				max = currentLen;
			currentLen = 0;
		} else {
			currentLen++;
		}
	} while (1);
	return max;
}

/**
 * Get number of lines
 * @fp pointer to the given file
 *
 * @author Dung (Kevin) Nguyen
 */
int getNumLines(FILE *fp) {
	int c;
	int numLine = 0;

	while ((c = fgetc(fp)) != EOF) {
		if (c == '\n')
			numLine++;
	}
	return numLine;
}
