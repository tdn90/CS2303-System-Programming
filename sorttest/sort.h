#ifndef SORT_H
#define SORT_H

#define MAX_MICROSEC 1000000

// Function prototypes:
void timesort (int a[], int count, int choice);
void print_int_array(int nums[], int count);
void sort_descending(int nums[], int count);
void mySort1(int nums[], int count);
void mySort2(int nums[], int count);
void print_timeval(struct timeval t);
struct timeval timediff(struct timeval time1, struct timeval time2);

#endif
