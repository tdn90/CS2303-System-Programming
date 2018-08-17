#include <stdio.h> 
#define MAXLINE 1000
#define MINLINE 5

int get_line(char line[], int lim);

main() {
	int len;
	char line[MAXLINE];

	while ((len = get_line(line, MAXLINE)) > 0) {
		if (len > MINLINE) printf("%s",line);
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
