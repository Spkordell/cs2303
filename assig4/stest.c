#include <stdio.h>
#include <string.h>
#include <errno.h>
#include "employeef.h"

int main() {
  printf("Starting program stest.\n\n"); 

  #ifdef DEBUG
  printf("--------BUILT WITH DEBUD MODE--------\n");
  #endif

  //Make some employees
  Employee harry; // Declare a local variable (a struct).
  harry.salary = 5000;
  harry.name = strdup("Harry Palmer"); // Make a dynamic copy.
  harry.department = strdup("Department A");

  Employee bluejay; // Declare a local variable (a struct).
  bluejay.salary = 10000;
  bluejay.name = strdup("Erik Grantby"); // Make a dynamic copy.
  bluejay.department = strdup("Department B");
  Employee* neo = createEmployee("Thomas Anderson",2000,"The One");
  Employee* smith = createEmployee("Agent Smith",50000,"Software Agents");

  Employee* userEmployee = scanEmployee(); //Prompt the user to enter an employee

  // Output the employees to stdout.
  printEmployee(&harry);
  printEmployee(&bluejay);
  printEmployee(neo);
  printEmployee(smith);
  printEmployee(userEmployee);

  // Output the employees to a file.
  printf("About to write to file.\n");
  FILE *outfile = fopen("stest.txt", "w"); // Open or create file for writing
  if (outfile == NULL) {
    fprintf(stderr, "\nOh no! It seems I can't write to the file, stest.txt.\nError %d has occured, %s.\n\n",errno,strerror(errno));
    return 1;
  }
  outputEmployee(outfile, &harry);
  outputEmployee(outfile, &bluejay);
  outputEmployee(outfile, neo);
  outputEmployee(outfile, smith);  
  outputEmployee(outfile, userEmployee);
  fclose(outfile); // Close the file

  printf("\nEnding program stest.\n"); 
  return 0;
}
