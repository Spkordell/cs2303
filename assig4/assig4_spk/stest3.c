#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <readline/readline.h>
#include "employeef.h"

int main() {
  int count; //The number of Employees read, will be filled by the read function
  printf("Starting program stest3.\n\n"); 

  #ifdef DEBUG
  printf("--------BUILT WITH DEBUD MODE--------\n");
  #endif


  //Read Employees from a file
  printf("About to read from file.\n");
  FILE *infile = fopen("stest.txt", "r"); // Open or create file for writing
  if (infile == NULL) {
    fprintf(stderr, "\nOh no! It seems I can't read the file, stest.txt.\nError %d has occured, %s.\n\n",errno,strerror(errno));
    return 1;
  }
  Employee** employeePtrArray = readAllEmployeesFromFile(infile,&count); //Read all the Employees from the open file
  fclose(infile); // Close the file
  printf("Success.\n");

  printEmployeeArray(employeePtrArray,count);


  freeEmployeeArray(employeePtrArray,count);
  printf("\nMemory freed.\n");

  printf("\nEnding program stest.\n");
  return 0;
}
