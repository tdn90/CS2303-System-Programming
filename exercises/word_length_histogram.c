#include <stdio.h>

#define IN 1  /* Inside a word */
#define OUT 0  /* Outside a word */

void main() {
	int c;

	int word_lengths[11];

	for (int i = 0; i < 11; i++) {
		word_lengths[i] = 0;
	}
	
	int state = 0;
	int current_word_length = 0;
	while ((c = getchar()) != EOF) {
		if (state = IN) {
			if (c == ' ' || c == '\t' || c == '\n' || c == '\\') {
				state = OUT;
			       	if (current_word_length > 10) {
					word_lengths[10]++;
				}	
				else {		
					word_lengths[current_word_length-1]++;
				}

				current_word_length = 0;
			}
			else {
				current_word_length++;
			}
		}
		else {	
			if (!(c == ' ' || c == '\t' || c == '\n' || c == '\\')) {
				state = IN; 
				current_word_length = 1;
			}
		}
	}

	for (int i = 0; i < 11; i++) {
		printf("%d\n",word_lengths[i]);
	}

	int maxHeight = word_lengths[0];
	for (int i = 1; i < 11; i++) {
		if (word_lengths[i] > maxHeight) maxHeight = word_lengths[i];
	}

	printf("HISTOGRAM\nWord_Length vs Frequency\n\n");
	for (int currentHeight = maxHeight; currentHeight > 0; currentHeight--) {
		for (int j = 0; j < 11; j++) {
			if (currentHeight <= word_lengths[j]) printf("*\t");
			else printf(" \t");
		}
		printf("\n");
	}

	for (int i = 1; i < 11; i++) {
		printf("%d\t",i);
	}
	printf(">10\n");
}


