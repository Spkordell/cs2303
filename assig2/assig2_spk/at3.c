/** file at3.c
 * @author Mike Ciaraldi
 * @author Steven Kordell
 * Program to demonstrate arrays in C.
 */

#include "print_arrays.h"
#include "sort_arrays.h"
#include "stdio.h"

#define SAMPLE_INT_ARRAY_SIZE (10)

/** Main program for demonstrating arrays. It fills them, sorts them,  and prints them.
 * @return 0, Indicating success.
 */

int main() {
  int a[SAMPLE_INT_ARRAY_SIZE]; // Sample array for demonstration
  genRandArray(a, SAMPLE_INT_ARRAY_SIZE, 100);

  //Print the generated data
  printf("Random Data:\n");
  print_int_array(a, SAMPLE_INT_ARRAY_SIZE);


  //sort the array and print it
  sortIntArrayAsc(a, SAMPLE_INT_ARRAY_SIZE);
  printf("Sorted random data - ascending order:\n");
  print_int_array(a, SAMPLE_INT_ARRAY_SIZE);

  return 0; // Success!
}
