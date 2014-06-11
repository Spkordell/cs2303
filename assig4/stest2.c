#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <readline/readline.h>
#include "employeef.h"

int main() {
  int count; //Store the number of Employees to make

  printf("Starting program stest2.\n\n"); 

  #ifdef DEBUG
  printf("--------BUILT WITH DEBUD MODE--------\n");
  #endif

  //Prompt user for the number of Employees to make
  while (!sscanf(readline("Number of Employees to make: "),"%d",&count) || count < 0) {
    printf("Invalid. Try again.\n");
  }
  printf("Please enter the data for %d Employees below: \n\n",count);

  Employee** employeePtrArray = scanEmployeeArray(count);  //Get the Employees
  printEmployeeArray(employeePtrArray,count); //Write them to the terminal

  // Output the employees to a file.
  printf("About to write to file.\n");
  FILE *outfile = fopen("stest2.txt", "w"); // Open or create file for writing
  if (outfile == NULL) {
    fprintf(stderr, "\nOh no! It seems I can't write to the file, stest2.txt.\nError %d has occured, %s.\n\n",errno,strerror(errno));
    return 1;
  }
  outputEmployeeArray(outfile, employeePtrArray,count); //write them to the file
  fclose(outfile); // Close the file
  printf("Success\n");


  freeEmployeeArray(employeePtrArray,count);
  printf("\nMemory freed.\n");

  printf("\nEnding program stest.\n");
  return 0;
}
