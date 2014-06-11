/** @file treetest.c
 */

#include <stdlib.h>
#include <stdio.h>
#include "tree.h"


/** Generates a random in between 0 and maxValue, inclusive
 *  @param maxValue The maximum value output
 *  @return A random integer between 0 and maxValue, inclusive
 *  @author Steven Kordell
*/
int genRandInt(int maxValue){
  return rand()%(maxValue+1);
}

/** Fills a string of specified size with random alphabetic characters
 *  @param n The size to make the string, actul size will be n+1, accounting for the terminator
 *  @return Pointer to the new string or zero if no memory available
 *  @author Steven Kordell
 */
char *genRandString(int n) {
  char *s = (char*) malloc(sizeof(char)*(n+1)); //Make space for the string
  if (s == 0) return (char *) 0; //Return if no memory available
  char* p = s;                   //Duplicate the pointer
  while (p - s < n) {            //Go through the array
    *p = (char)genRandInt(57)+65;//Generate a random character
    if (*p >= 91 && *p <= 96);   //Ensure the character is in the proper range
    else p++;                    //increment the pointer
  }
  *p = '\0';                     //Set last charater to terminator
  return s;                      //return the pointer to the new string
}

int main() {
  int i; //a general loop  iterator
  srand(time(NULL)); //Set the seed for operations involving random numbers

  Tnode* root = add_tnode(NULL,genRandString(genRandInt(30))); //initialize the tree

  for (i = 0; i<=50; i++) {
    add_tnode(root,genRandString(genRandInt(30))); //add 50 random strings to the tree
  }
       
  printf("\n");
  traverseDescending(root); //traverse the tree in descending order

  freeTree(root);  //deallocate the tree
  return 0;
}
