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
int getJan1(int year);

int main() {
	printf("\t\tMONTHLY CALENDAR\n\n");
	int year;
	printf("Please enter year for this calendar: ");
	scanf("%d", &year);
	printf("\n");

	if (year <= 1582) {
		printf("Invalid year number for Gregorian Calendar.\n");
		return 1;
	}

	printf("* * *\t\tCALENDAR for %d\t\t* * *\n\n", year);
	
	int cur_month_start_date = getJan1(year);
	for (int i = JAN; i <= DEC; i++) {
		printLine();
		printf("\t\t\t");
		int cur_month_days = get_days_print_month(i);
		if (i == FEB) cur_month_days += checkLeapYear(year);
		printf("\n\n");
		printDays();
		cur_month_start_date = printDaysInMonth(cur_month_days, cur_month_start_date);		
	}
	return 0;
}

/**
 * Determine the start date of the year
 * Day code:
 * Sunday: 0
 * Monday: 1
 * Tuesday: 2
 * Wednesday: 3
 * Thursday: 4
 * Friday: 5
 * Saturday: 6
 */
int getJan1(int year) {
	int num_day, zeller_month, year_code, century; 

	num_day = 1; // First day of the month
	zeller_month = 11; // According to Zeller's Rule, the month code for January is 11
	year_code = year % 100 - 1; // Last two digit of the year - 1
	century = year / 100;

	return (num_day + ((13 * zeller_month - 1) / 5) + year_code + (year_code / 4) + (century / 4) - 2 * century) % 7;
}

/**
 * Determine whether the given year is a leap year.
 * If it is a leap year, return 1 so we can add one more day to February. Else return 0.
 */
int checkLeapYear(int year) {
	if (year % 4 == 0) {
		if (year % 100 == 0) {
			if (year % 400 == 0) return 1;
			else return 0;
		}
		else return 1;
	}
	else return 0;
}

// Make the calendar look more organized
void printLine() {
	for (int i = 0; i < 56; i++) printf("-");
	printf("\n");
}

void printDays() {
	printf("Sun\tMon\tTue\tWed\tThu\tFri\tSat\n");
}

// Print the month and return the days that the given month has
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
		default: return 0;
	}
}

/**
 * Given the total day in a month and the start day 
 * Print out all days of that month
 * And return the start day of next month 
 */
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

	int next_start = (start_day + total_day) % 7;
	if (next_start != 0) printf("\n");
	printf("\n");
	return next_start;
}
