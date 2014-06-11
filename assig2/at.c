/** file at.c
 * @author Mike Ciaraldi
 *
 * Program to demonstrate arrays in C.
 */

#include "print_arrays.h"

#define SAMPLE_INT_ARRAY_SIZE (10)

/** Main program for demonstrating arrays. It fills them and prints them.
 * @return 0, Indicating success.
 */

int main() {
  int i; // Loop counter
  int a[SAMPLE_INT_ARRAY_SIZE]; // Sample array for demonstration

  // Fill the array with consecutive integers
  for (i = 0; i < SAMPLE_INT_ARRAY_SIZE; i++) a[i] = i;

  // Now print it out
  print_int_array(a, SAMPLE_INT_ARRAY_SIZE);

  return 0; // Success!
}
