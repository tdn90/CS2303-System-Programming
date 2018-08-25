#include <stdio.h>

#define JAN 1
#define FEB 2
#define MAR 3
#define APR 4
#define MAY 5
#define JUN 6
#define JUL 7
#define AUG 8
#define SEPT 9
#define OCT 10
#define NOV 11
#define DEC 12

int get_days_print_month(int month_code);
void printDays();
int printDaysInMonth(int total_day, int start_day);
void printLine();
int checkLeapYear(int year);

main() {
	int year;
	scanf("Please enter chosen year: \n%d", &year);
	

	int cur_month_start_date = 0; /* Write a function to determine the start date later */
	for (int i = 1; i <= 12; i++) {
		printLine();
		printf("\t\t\t");
		int cur_month_days = get_days_print_month(i);
		if (i == 2) cur_month_days += checkLeapYear(year);
		printf("\n");
		printf("\n");
		printDays();
		cur_month_start_date = printDaysInMonth(cur_month_days, cur_month_start_date);		}
}

// Check if this function is correct
int checkLeapYear(int year) {
	return ((year % 100) % 4 == 0) ? 1 : 0;
}

void printLine() {
	for (int i = 0; i < 56; i++) {
		printf("-");
	}
	printf("\n");
}

void printDays() {
	printf("S\tM\tT\tW\tT\tF\tS\n");
}

int get_days_print_month(int month_code) {
	switch(month_code) {
		case JAN: printf("January");
			return 31;
		case FEB: printf("February");
			return 28;	
		case MAR: printf("March");
			return 31;
		case APR: printf("April");
			return 30;
		case MAY: printf("May");
			return 31;
		case JUN: printf("June");
			return 30;
		case JUL: printf("July");
			return 31;
		case AUG: printf("August");
			return 31;
		case SEPT: printf("September");
			return 30;
		case OCT: printf("October");
			return 31;
		case NOV: printf("November");
			return 30;
		case DEC: printf("December");
			return 31;
	}
}


int printDaysInMonth(int total_day, int start_day) {
	int start = 0;
	while (start < start_day) {	
		printf(" \t");
		start++;
	}

	int current_day = 1;
	while (current_day <= total_day) {
		printf("%d\t",current_day);

		if ((current_day + start_day - 1) % 7 == 6) printf("\n");

		current_day++;
	}

	int check = (start_day + total_day) % 7;
	if (check != 0) printf("\n");
	printf("\n");
	return check;
}
