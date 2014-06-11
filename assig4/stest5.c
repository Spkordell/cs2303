#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <readline/readline.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "employeef.h"

int main() {
  int count; //Will be filled with the number of employees read

  printf("Starting program stest5.\n\n"); 

  #ifdef DEBUG
  printf("--------BUILT WITH DEBUD MODE--------\n");
  #endif



  //Write Employees to binary file
  printf("About to read the file.\n");
  int infile = open("stest4.txt",O_RDONLY); // Open or create file for writing
  if (infile == -1) {
    fprintf(stderr, "\nOh no! It seems I can't read the file, stest4.txt.\nError %d has occured, %s.\n\n",errno,strerror(errno));
    return 1;
  }
  Employee** employeePtrArray = readAllEmployeesFromBinaryFile(infile,&count); //Read all the Employees from the file
  close(infile); // Close the file
  printf("Success.\n");

  printEmployeeArray(employeePtrArray,count);

  freeEmployeeArray(employeePtrArray,count);
  printf("Memory Freed.\n");

  printf("\nEnding program stest.\n");
  return 0;
}
