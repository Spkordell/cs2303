/** file at2.c
 * @author Mike Ciaraldi
 * @author Steven Kordell
 * Program to demonstrate arrays in C.
 */

#include "print_arrays.h"
#include "sort_arrays.h"
#include "stdio.h"

#define SAMPLE_INT_ARRAY_SIZE (10)
#define SAMPLE_DOUBLE_ARRAY_SIZE (10)

/** Main program for demonstrating arrays. It fills them and prints them.
 * @return 0, Indicating success.
 */

int main() {
  int i; //loop counter
  int amountEntered; //stores the amount of data the user entered 
  int a[SAMPLE_INT_ARRAY_SIZE]; // Sample array for demonstration
  double b[SAMPLE_DOUBLE_ARRAY_SIZE]; //sample array for demonstration

  // Fill the double array with consecutive integers
  for (i = 0; i < SAMPLE_DOUBLE_ARRAY_SIZE; i++) b[i] = i;

  amountEntered = collectInts(a,SAMPLE_INT_ARRAY_SIZE,100);

  if (amountEntered >= SAMPLE_INT_ARRAY_SIZE) {  //If the array is full
    printf("Maximum amount of inputs have been entered. You cannot enter anymore.\n"); //Tell the user
   }

  //Print the entered data
  printf("User entered data:\n");
  print_int_array(a, amountEntered);
  if (amountEntered < 1) printf("No data entered\n"); //If there was nothing to print, tell the user.

  //sort the array and print it
  sortIntArrayAsc(a, amountEntered);
  printf("Sorted data - ascending order:\n");
  print_int_array(a, amountEntered);


  printf("Test array of doubles:\n");
  print_double_array(b,SAMPLE_DOUBLE_ARRAY_SIZE);

  return 0; // Success!
}
