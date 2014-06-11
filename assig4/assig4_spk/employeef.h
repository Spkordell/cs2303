/** File employeef.h
 * @author Steven Kordell
 *
 * Header file for functions that involving workign with the Employee struct
 */


#ifndef EMPLOYEEF_H
#define EMPLOYEEF_H

//Structure definition
struct _Employee {
  int salary; // Monthly salary in UK pounds sterling
  char *name; // Pointer to character string holding name of employee.
  char *department; //Pointer to a character string holding the department of employee
};

typedef struct _Employee Employee;

//function prototypes
void printEmployee(Employee *employee);
void outputEmployee(FILE *stream, Employee *employee);
Employee* createEmployee(const char* name, int salary, const char* department);
Employee* scanEmployee();
Employee** scanEmployeeArray(int count);
void printEmployeeArray(Employee** employeePtrArray, int count);
void outputEmployeeArray(FILE* stream, Employee** employeePtrArray, int count);
void freeEmployeeArray(Employee** employeePtrArray, int count);
Employee* readEmployeeFromFi(FILE *stream);
Employee** readAllEmployeesFromFile(FILE *stream, int* count);
void outputBinaryEmployee(int fd, Employee  *employee);
void outputBinaryEmployeeArray(int fd, Employee** employeePtrArray, int count);
Employee* readEmployeeFromBinaryFile(int fd);
Employee** readAllEmployeesFromBinaryFile(int fd, int* count);

#endif
