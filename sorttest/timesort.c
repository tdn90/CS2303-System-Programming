#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include "sort.h"

/** Program which takes an array of integers, prints it,
 * sorts it, prints it again, and reports how long the sorting took.
 * @param a Array of integers.
 * @param count Number of integers in the array.
 * @param choice Specify which version of sort will be used.
 * 0 for default, 1 for mySort1(), and 2 for mySort2()
 * @return 0 if success, 1 if error (wrong number of arguments)
 */

void timesort (int a[], int count, int choice) {

  struct timeval start_time; // time stamps for start and end of sorting
  struct timeval end_time;
  struct timeval sort_time; // Elapsed time while sorting

  printf("Unsorted array:\n");
  print_int_array(a, count);

  // choose which function to use and test
  switch(choice) {
  case 0: // choose default
	  gettimeofday(&start_time, NULL); // Get timestamp
	  sort_descending(a, count);
	  gettimeofday(&end_time, NULL); // Get timestamp
	  break;
  case 1: // choose mySort1
	  gettimeofday(&start_time, NULL); // Get timestamp
	  mySort1(a, count);
	  gettimeofday(&end_time, NULL); // Get timestamp
	  break;
  case 2: // choose mySort2
	  gettimeofday(&start_time, NULL); // Get timestamp
	  mySort2(a, count);
	  gettimeofday(&end_time, NULL); // Get timestamp
	  break;
  }

  printf("Sorted array (descending order):\n");
  print_int_array(a, count);

  printf("Timestamp before sorting: ");
  print_timeval(start_time); 
  printf("Timestamp after sorting: ");
  print_timeval(end_time);
  sort_time = timediff(start_time, end_time);
  printf("Time spent sorting: ");
  print_timeval(sort_time); 

  return; // nothing to return
}
