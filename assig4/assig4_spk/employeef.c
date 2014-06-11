/** file employeef.c
 * @author Steven Kordell
 *
 * Functions for working with the Employee Struct
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <readline/readline.h>
#include "employeef.h"

/** Prints an employee struct to the terminal (standard output).
 * @param employee Pointer to the Employee struct to print
*/
void printEmployee(Employee *employee) {
  fprintf(stdout, "Employee  Name = %-18s Salary = %-7d Department = %-18s\n",
	  employee->name, employee->salary,employee->department);
}

/** Prints an employee struct to an already open file stream
 * @param stream Pointer to the FILE struct of the open stream to print to
 * @param employee Pointer to the Employee struct to print
 */
void outputEmployee(FILE *stream, Employee *employee) {
  fprintf(stream, "Employee  Name = %-18s Salary = %-7d Department = %-18s\n",
	  employee->name, employee->salary,employee->department);
}

/**  Dynamically allocates an Employee struct with the provided fields
 * @param name Character string of the name of the Employee - will be duplicated
 * @param salary The salary of the Employee
 * @param department Character string of the department of the employee - will be duplicated
 * @return Pointer to the newly allocated employee struct
 * @author Steven Kordell
 */
Employee* createEmployee(const char* name, int salary, const char* department) {
  Employee*  newEmployee = (Employee*)malloc(sizeof(Employee)); //Allocate space for the struct
  //Copy in the values
  newEmployee->name = strdup(name);
  newEmployee->salary = salary;
  newEmployee->department = strdup(department);
  return newEmployee; //return the pointer to the new struc
}

/** Prompts the user to enter the fields for a new employee struct. It then creates allocates the struct and returns a pointer to its location
 * @return Pointer to a new user generated employee struct
 * @author Steven Kordell
 */
Employee* scanEmployee() {
  char* name;        //Stores the entered name sting
  char* salaryString;//Stores the entered slary string
  char* department;  //Stores the entered department string
  int salary;        //Stores the salary
  Employee*  newEmployee; //Stores the pointer to the allocated Employee struct
  printf("Enter new employee information:\n"); //Prompt the user for information
  name = readline("Name: "); //Get the name
  do {
    salaryString = readline("Salary: ");  //get the salary
  } while (!sscanf(salaryString,"%d",&salary) || salary < 0); //ensure the slary is a number and it is positive 
  department = readline("Department: "); //Get the department
  newEmployee = createEmployee(name,salary,department); //make the new Employee struct
  //free the memory allocated
  free(name);
  free(salaryString);
  free(department);
  return newEmployee; //return the pointer to the new Employee struct
}


/** Promts the user for the number of Employees they would like to create. Then prompts the users for that many employees, creates the employees,  and fills an array with pointers to these structures. 
 * @param count Number of Employees to promt for
 * @return A pointer to the array of pointers to Employees
 * @author Steven Kordell
 */
Employee** scanEmployeeArray(int count) {
  int i; //variable to iterate over array of pointers to structs
  Employee** employeePtrArray = (Employee**)malloc(sizeof(Employee*)*count);  //Array of pointers to the new Employee Structs
  for(i = 0; i < count; i++) {
    employeePtrArray[i] = scanEmployee();
    printf("\n");
  }
  return employeePtrArray;
}

/** Prints all the Employee structures defined in an array of pointers to structures
 * @param employeePtrArray The array of pointers to structs to dereference and print
 * @param count Number of elements in the array
 *@author Steven Kordell
 */
void printEmployeeArray(Employee** employeePtrArray, int count) {
  int i; //An iterator for looping through the array
  for(i = 0; i < count; i++) {          //iterate over the array
    printEmployee(employeePtrArray[i]); //print the struct
  }
}

/** Outputs all the Employee structures defined in an array of pointers of structures to the specified file stream
 * @param stream The open stream to output to
 * @param employeePtrArray The array of pointers to structs to dereference and print
 * @param count Number of elements in the array
 *@author Steven Kordell
 */
void outputEmployeeArray(FILE* stream, Employee** employeePtrArray, int count) {
  int i; //An iterator for looping through the array
  for(i = 0; i < count; i++) {                  //iterater over the array
    outputEmployee(stream,employeePtrArray[i]); //write the struct to the file
  }
}

/** Frees all the memory allocated by the structures referenced in the provided array. Also frees memory allocated by the structure fields and by the array of pointers.
 * @param employeePtrArray Array of pointers to Employee Structs to 'deep' free
 * @param count Number of elements in the array
 * @author Steven Kordell
 */
void freeEmployeeArray(Employee** employeePtrArray, int count) {
  int i;// Iterator to use over the array
  for(i = 0; i < count; i++) {            //iterate over the array
    free(employeePtrArray[i]->name);      //free the name
    free(employeePtrArray[i]->department);//free the department
    free(employeePtrArray[i]);            //free the struct
  }
  free(employeePtrArray);                 //free the array of structs
}

/** Reads an Employee from an open file and returns a pointer to that employee structure
 * @param stream The open file to read from
 * @return A pointer to the new Employee stuct
 * @author Steven Kordell
 */
Employee* readEmployeeFromFile(FILE *stream) {
  char name[50] = "";
  char salaryString[10] = "";
  char department[10] = "";
  char readString[50];
  //If we are at the end of the file, exit immediatly
  if(fscanf(stream,"%s",readString) == EOF) return NULL; 

  //find name field
  while (fscanf(stream,"%s",readString) == 1 && strcmp(readString,"=")) {}
  //read name
  while (fscanf(stream,"%s",readString) == 1 && strcmp(readString,"Salary")) {
    strcat(name,readString);
    strcat(name," ");
  }
  //find salray
  while (fscanf(stream,"%s",readString) == 1 && strcmp(readString,"=")) {}
  fscanf(stream,"%s",salaryString); //read the salary
  //find the department
  while (fscanf(stream,"%s",readString) == 1 && strcmp(readString,"=")) {}
  //read the department
  while (fscanf(stream,"%s",readString) == 1 && strcmp(readString,"Employee")) {
    strcat(department,readString);
    strcat(department," ");
  }
  //build the Employee Struct and return its pointer
  return createEmployee(name,atoi(salaryString),department);
}

/** Reads all the Employees from an open File and builds an array pointing to them
 * @param stream An open FILE Stream
 * @return A pointer to the array of pointers to Employees
 * @param count Will be filled with the total number of employees read from the file
 * @author Steven Kordell
 */
Employee** readAllEmployeesFromFile(FILE *stream, int* count) {
  Employee* tempEmployeePtr;             //Temporarily hold the recently read employee
  Employee** employeePtrArray = NULL;   //Holds the array of Ptr
  *count = 1;                            //an iterator
 //While we haven't reached the end of the file
  while ((tempEmployeePtr = readEmployeeFromFile(stream)) != NULL) {
    //Make room for the new pointer
    employeePtrArray= (Employee**)realloc(employeePtrArray,sizeof(Employee*)*(*count));
    //save the pointer in the array
    employeePtrArray[((*count)++)-1] = tempEmployeePtr;
  }
  (*count)--; //incremented it at the end of the last loop, have to move it back
  return employeePtrArray; //return the array
}

/** Write an employee struct to an already open binary file
 * @param fd The file descriptor of the open file to write to
 * @param employee Pointer to the Employee struct to print
 */
void outputBinaryEmployee(int fd, Employee  *employee) {
  char outputBuffer[100]; //make a tempory buffer to hold the output
  //Ensure the fields are within the minimum lentgh
  if (strlen(employee->name)>30 || strlen(employee->department)>30) {
    fprintf(stderr,"Fields exceed 30 characters. Canceling write.\n");
    return;
  }
  sprintf(outputBuffer,"%-30s%-12d%-30s",employee->name,employee->salary,employee->department); //format the result
  write(fd,outputBuffer,strlen(outputBuffer)); //write the result to the file
}

/** Outputs all the Employee structures defined in an array of pointers of structures to the specified binary file
 * @param fd The open file descriptor to write to
 * @param employeePtrArray The array of pointers to structs to dereference and print
 * @param count Number of elements in the array
 *@author Steven Kordell
 */
void outputBinaryEmployeeArray(int fd, Employee** employeePtrArray, int count) {
  int i; //An iterator for looping through the array
   for(i = 0; i < count; i++) {                  //iterater over the array
    outputBinaryEmployee(fd,employeePtrArray[i]); //write the struct to the file
  }
}

/** Reads an Employee from an open binary file and returns a pointer to that employee structure
 * @param fd The open file descriptor to read from
 * @return A pointer to the new Employee stuct
 * @author Steven Kordell
 */
Employee* readEmployeeFromBinaryFile(int fd) {
  char name[30] = "";
  char salaryString[12] = "";
  char department[30] = "";
  //If we are at the end of the file, stop, else read the contents
  if (read(fd,name,30)+read(fd,salaryString,12)+read(fd,department,30) < 72) {
    return NULL;
  } 
  return createEmployee(name,atoi(salaryString),department);
}

/* Reads all the employees from the specified binary file, allocates them,  and returns a pointer to an array of  their locations in memory
 * @param fd An open file descriptor
 * @param count Will be filled with the number of employees read
 * @return A pointer to the array of pointers to Employees
 * @author Steven Kordell
 */
Employee** readAllEmployeesFromBinaryFile(int fd, int* count) {
  Employee* tempEmployeePtr;             //Temporarily hold the recently read employee
  Employee** employeePtrArray = NULL;   //Holds the array of Ptrs to Employees
  *count = 1;                            //an iterator
 //While we haven't reached the end of the file
  while ((tempEmployeePtr = readEmployeeFromBinaryFile(fd)) != NULL) {
    //Make room for the new pointer
    employeePtrArray= (Employee**)realloc(employeePtrArray,sizeof(Employee*)*(*count));
    //save the pointer in the array
    employeePtrArray[((*count)++)-1] = tempEmployeePtr;
  }
  (*count)--; //incremented it at the end of the last loop, have to move it back
  return employeePtrArray; //return the array
}
