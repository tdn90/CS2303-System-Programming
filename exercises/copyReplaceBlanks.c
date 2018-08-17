#include <stdio.h>

main() {
	int c;
	int isPrevBlank = 0;
	while ((c = getchar()) != EOF) {
		if (isPrevBlank == 0) {
			if (c == ' ') {
				isPrevBlank = 1;
			}
			putchar(c);
		}
		else {
			if (c == ' ') {
				continue;
			}
			else {
				isPrevBlank = 0;
			}
			putchar(c);
		}
	}
}
