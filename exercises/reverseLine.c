#include <stdio.h> 
#define MAXLINE 1000


int get_line(char line[], int lim);
void reverse(char string[], int length);

main() {
	char string[MAXLINE];  /* The current line */
	int length;		/* current line length */
	while ((length = get_line(string, MAXLINE)) > 0) {
		reverse(string, length-2);   // Why length-1? Because the last character in string is null terminator
		printf("%s", string);
	}	
}

void reverse(char string[], int length) {
	int leftCursor = 0;
	int rightCursor = length; 

	while (leftCursor < rightCursor) {
		char leftChar = string[leftCursor];
		string[leftCursor++] = string[rightCursor];
		string[rightCursor--] = leftChar;
	}	
}


int get_line(char line[], int lim) {
	int c;
	int i;
	for (i = 0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; i++) 
		line[i] = c;

	if (c == '\n') 	line[i++] = c;

	line[i] = '\0';
	return i;
}

