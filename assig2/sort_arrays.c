/** file sort_arrays.c
 * @author Steven Kordell
 *
 * Functions for sorting  arrays.
 */

#include <stdio.h>

/** Sorts an array of ints in assensing order using bubble_sort
*   @param a[] The array of integers. It will be filled with the sorted array
*   @param num_elements The size of the array
*/
void sortIntArrayAsc(int a[], int num_elements) {
  int i,j,temp;
  for (j = 0; j < (num_elements-1); j++) { //iterate over the array enough to sot all the elements
    for (i = 0; i < num_elements - j - 1; i++) { //iterate over the array
      if (a[i] > a[i+1]) { //if the element is greater than the next element
	//sway them
	temp = a[i];
	a[i] = a[i+1];
	a[i+1] = temp;
      }
    }
  }
}


/** Generates a random in between 0 and maxValue, inclusive
@paeam maxValue The maximum value output
@return A random integer between 0 and maxValue, inclusive
*/
int genRandInt(int maxValue){
  return rand()%(maxValue+1);
}

/** Fills an array of specified size with random integers numbers between 0 and maxValue
 *  @param a[] The integer array to fill with random numbers
 *  @param num_elements The size of the array
 *  @param maxValue The maximum value to place in the array, inclusive
 */
void genRandArray(int a[], int num_elements, int maxValue) {
  int i;
  srand(time(NULL));
  for(i = 0; i <= num_elements; i++) {
    a[i] = genRandInt(maxValue);
  }
}
