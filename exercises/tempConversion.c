#include <stdio.h>
#define START 0   /* Start temp */
#define END 300 /* End temp */
#define STEP 20

double toCelcius(int fahr);

main() {
	int fahr; 
	
	printf("Conversion Table\nFahrenheit To Celcius\n\nF\tC\n");
	for (fahr = START; fahr <= END; fahr+=STEP) {
		printf("%d\t%3.2f\n", fahr, toCelcius(fahr));
	}
}

double toCelcius(int fahr) {
	return (fahr - 32.0) / (9.0 / 5);
}
