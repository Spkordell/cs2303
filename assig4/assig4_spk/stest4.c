#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <readline/readline.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "employeef.h"

int main() {
  int count; //Store the number of Employees to make

  printf("Starting program stest4.\n\n"); 

  #ifdef DEBUG
  printf("--------BUILT WITH DEBUD MODE--------\n");
  #endif

  //Prompt user for the number of Employees to make
  while (!sscanf(readline("Number of Employees to make: "),"%d",&count) || count < 0) {
    printf("Invalid. Try again.\n");
  }
  printf("Please enter the data for %d Employees below: \n\n",count);

  Employee** employeePtrArray = scanEmployeeArray(count); //Read in some Employees
  printEmployeeArray(employeePtrArray,count);

  //Write Employees to binary file
  printf("About to write to the file.\n");
  int outfile = open("stest4.txt", O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR); // Open or create file for writing
  if (outfile == -1) {
    fprintf(stderr, "\nOh no! It seems I can't write to  the file, stest4.txt.\nError %d has occured, %s.\n\n",errno,strerror(errno));
    return 1;
  }
  outputBinaryEmployeeArray(outfile,employeePtrArray,count);
  close(outfile); // Close the file
  printf("Success.\n");


  freeEmployeeArray(employeePtrArray,count);
  printf("Memory Freed.\n");

  printf("\nEnding program stest.\n");
  return 0;
}
