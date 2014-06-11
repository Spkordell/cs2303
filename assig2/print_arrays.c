/** file print_arrays.c
 * @author Mike Ciaraldi
 *
 * Functions for printing arrays.
 */

#include <stdio.h>

/** Print an array of ints, one per line.
    @param a[] An Array to print
    @param num_elements  Number of elements in the array
*/
void print_int_array(int a[], int num_elements) {
  int i; // Loop counter

  for (i = 0; i < num_elements; i++) {
    printf("%d\n", a[i]);
  }
}
/** Print an array of doubles, one per line
    @param a[] An Array to print
    @param num_elements The number of elements in the array
*/
void print_double_array(double a[], int num_elements) {
  int i; // Loop counter

  for (i = 0; i < num_elements; i++) {
    printf("%f\n", a[i]);
  }
}


/**  Take integer data from the user and store it into an array,
 stopping when the array gets full or a negative value is entered.
 It will reject any input values greater than the max value.
     @param a[] The array to store the data in
     @param num_elements[] The size of the array
     @param max_value The maximum valid value of user input
     @return The number of data elements the user entered
*/
int collectInts(int a[], int num_elements, int max_value) {
  int userIn=0;
  int counter=0;
  while (userIn >= 0 && counter <  num_elements) {    //if the grade is non-negative and the array is not full
    printf( "Enter Data: " );  //Prompt for input
    scanf( "%d", &userIn);     //Read in data
    if (userIn >= 0){           // if input is non-negative 
      if (userIn <=  max_value) {     //check if input is less than maximum value
	a[counter]=userIn;      //Add input to array
	counter++;             // increment counter
	} else {
	printf("Input exceeds maximum value. Input must be less than 100\n"); // warn user
	}
    }
   }
  return counter;
}
