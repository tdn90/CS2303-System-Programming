#include <stdio.h> 
#define TAB_STOP 8

main() {
	int c; 
	
	int current_line_length = 0;
	while ((c = getchar()) != EOF && c != '\n') {
		if (c != '\t') {
			current_line_length++;
			putchar(c);
		}
		else {
			for (int i = current_line_length % TAB_STOP; i < TAB_STOP; i++) {
				putchar(' ');
			}
			current_line_length = 0; 
		}
	}
	putchar('\n');	
}	
