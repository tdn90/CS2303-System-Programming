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

/**
 * Print out a 12-month Gregorian Calendar.
 * @return 0 if the program execute normally, 1 for early exit.
 * @author: Dung (Kevin) Nguyen
 */
int main() {
	printf("\t\tMONTHLY CALENDAR\n\n");

	// Ask for input year
	int year;
	printf("Please enter year for this calendar: ");
	scanf("%d", &year);
	printf("\n\n");

	// Error checking
	if (year <= 1582) {
		printf("Invalid year number for Gregorian Calendar.\n");
		return 1;
	}

	printf("***     CALENDAR for %d     ***\n\n", year);
	
	// Keep track of the first day of each month 	
	int cur_month_start_date = getJan1(year);

	// Print each month
	for (int i = JAN; i <= DEC; i++) {
		printLine();

		// Print current month's name and get current month's total days
		int cur_month_days = get_days_print_month(i);
		printf(" %d", year);

		// Add another day if leap year
		if (i == FEB) cur_month_days += checkLeapYear(year);
		printf("\n\n");
		printDays();

		// print every days in given month
		cur_month_start_date = printDaysInMonth(cur_month_days, cur_month_start_date);		
	}
	return 0;
}

/**
 * Determine the start date of the year
 * Day code table:
 * +-----+-----+-----+-----+-----+-----+-----+
   | Sun | Mon | Tue | Wed | Thu | Fri | Sat |
   +-----+-----+-----+-----+-----+-----+-----+
   |   0 |   1 |   2 |   3 |   4 |   5 |   6 |
   +-----+-----+-----+-----+-----+-----+-----+
 * @param year Given year (after 1582)
 * @return: the day code of January 1st of the given year
 * @author: Dung (Kevin) Nguyen
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
 * @param year Given year (after 1582 exclusive)
 * @return 1 if it is a leap year, 0 otherwise.
 * @author: Dung (Kevin) Nguyen
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

/** 
 * Print out a horizontal line, make the calendar look more organized
 * @author: Dung (Kevin) Nguyen
 */
void printLine() {
	for (int i = 0; i < 34; i++) printf("-");
	printf("\n");
}

/**
 * Print out days' name in the week
 * @author: Dung (Kevin) Nguyen
 */ 
void printDays() {
	printf("Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");
}

/**
 * Print out the current month's name
 * @param month_code Given month_code to determine the current month. Follows the pattern: 1-12 --- Jan-Dec
 * @return number of days in the given month
 * @author: Dung (Kevin) Nguyen
 */ 
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
 * Print out the calendar of the given month
 * @param totay_day: given month's number of days
 * @param start_day: given month's start date, following day_code table
 * @return the start date of the following month.
 * @author: Dung (Kevin) Nguyen
 */ 
int printDaysInMonth(int total_day, int start_day) {
	// Customize spacing
	if (start_day > 0) printf("   ");
	int start = 1;
	while (start < start_day) {	
		printf("     ");
		start++;
	}
	
	int current_day = 1; 
	// print out the days in month
	while (current_day <= total_day) {
		int day_code = (current_day + start_day - 1) % 7;
		if(day_code == 0) printf("%3d", current_day);
		else printf("%5d",current_day);
		if (day_code == 6) printf("\n");
		current_day++;
	}
	
	// Get start date of following month 
	int next_start = (start_day + total_day) % 7;
	if (next_start != 0) printf("\n");
	printf("\n");
	return next_start;
}
