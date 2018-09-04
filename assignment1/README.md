# Gregorian Calendar Printer

This CLI (Command Line Interface) program will display a twelve month calendar for an arbitrary year after year 1582. 

## How to run this program
1. Compile the program by typing the following command on the command prompt (BASH): 

    `cc -Wall PA1.c -o printCalendar`

2. Run the program:

    `./printCalendar`

3. The program will prompt the user to enter the desired year as follow:
    `Please enter year for this calendar:`

4. Enter the year.
5. Enjoy!

## Dependency
The header file <stdio.h> provides the prototypes (interfaces) for the functions printf() and scanf().

## Assumptions and Restrictions
The Gregorian Calendar was first introduced by Pope Gregory XIII in the year 1582, so 1583 was the first full year it was in effect.

Therefore, the user may enter any strictly positive integer greater than 1582 for the year; if the user enters a number less than 1583, this program will print an informative error message and exit. 

## How it works
1. Determine the leap year:

    To determine whether a year is a leap year, follow these steps: 
    
    - Step 1: If the year is evenly divisible by 4, go to step 2. Otherwise, go to step 5.
    - Step 2: If the year is evenly divisible by 100, go to step 3. Otherwise, go to step 4.
    - Step 3: If the year is evenly divisible by 400, go to step 4. Otherwise, go to step 5.
    - Step 4: The year is a leap year (it has 366 days).
    - Step 5: The year is not a leap year (it has 365 days).

2. Determine the first day of the year:

- Use Zeller's Rule:

    `f = (k + [(13*m-1)/5] + D + [D/4] + [C/4] - 2*C) % 7`

    where
    - f is the day_code 
    - k is the day of the month. Let's use January 29, 2064 as an example. For this date, k = 29.
    - m is the month number. Months have to be counted specially for Zeller's Rule: March is 1, April is 2, and so on to February, which is 12. (This makes the formula simpler, because on leap years February 29 is counted as the last day of the year.)
    - D is the last two digits of the year. Mind that if the month used is January or February, we would use the last two digits of the (year minus 1) to fit Zeller's Rule.
    - C stands for century: it's the first two digits of the year (again, after minus 1)

    Day_code is assigned according to this table:

    | Sun | Mon | Tue | Wed | Thu | Fri | Sat
    |:---:|:---:|:---:|:---:|:---:|:---:|:---:|
    | 0   | 1   | 2   | 3   | 4   | 5   |  6  |



3. Internal Logic:
- Loop from January to December
- For each month, print out all days iteratively. Make spaces at the beginning based on the start date. Go to a new line when it is Sunday.
- Afterwards, get the start date of the following month. 
- Add one day to February if it is a leap year. 
- Continue.


## Cited Source
1. [Determine the leap year](https://support.microsoft.com/en-us/help/214019/method-to-determine-whether-a-year-is-a-leap-year)
   
2. [Determine the first day of the year](http://mathforum.org/dr.math/faq/faq.calendar.html)