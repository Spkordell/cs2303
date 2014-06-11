#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// string.h covers the C-style string functions.
#include "mystring.h"

/** ctest.c
 * Program to demonstrate character arrays and
 * dynamically-allocated memory.
 * @author Mike Ciaraldi
 * @author Steven Kordell
 */

//Function prototypes
struct Employee* make_employee(char* name, int birth_year, int start_year);
void print_employee(struct Employee* a);
struct Employee* random_employee();
struct Employee** random_employees(int count);
void printAllEmployees(struct Employee** eArray, int num_elts);
struct Employee** shallowCopyEmployees(struct Employee** src, int n);
void freeAllEmplyees(struct Employee** src,int n);
struct Employee** deepCopyEmployees(struct Employee** src, int n);

//define a struct
struct Employee {
  char name[100];
  int birth_year;
  int start_year;
};

const int MAX_CHARS = 20; // Maximum number of characters in array

int main()
{
  ////////////////// OLD CODE WITH BUILT IN FUNCTIONS ///////////////////////

  printf("\n\n--------OLD FUNCTIONS--------\n");

  char a1[MAX_CHARS + 1]; // Character array--initially empty
  char a2[] = "Hello"; // Character array--unsized but initialized
  char a3[MAX_CHARS + 1]; // Character array--we will underfill it
  char* p1 = "Hello"; // Pointer to constant string
  char* p2;           // Will be a pointer to dynamically-allocated string
  int copy_limit;     // Maximum characters to copy.

  strcpy(a3, "Hello, also"); // Initialize uinderfilled character array

  /* Print the pointers.
     Note: this example prints
     the values of the pointers themselves, not the targets.
  */
  printf("Pointers: a1 = %p, a2 = %p, a3 = %p\n", a1, a2, a3);
  printf("          p1 = %p p2 = %p\n", p1, p2);

  strcpy(a1, "Hi"); // Initialize character array

  printf("a1 = %s\n", a1);
  printf("a2 = %s\n", a2);
  printf("a3 = %s\n", a3);

  // Concatenate two character arrays, then print.
  strcat(a1, a2);
  printf("a1 = %s\n", a1);

  // Concatenate two character arrays safely, then print.
  copy_limit = MAX_CHARS - strlen(a1); // How much space is left?
  if (copy_limit > 0) strncat(a1, a2, copy_limit);
  printf("a1 = %s\n", a1);

  // Concatenate two character arrays safely, then print.
  copy_limit = MAX_CHARS - strlen(a1); // How much space is left?
  if (copy_limit > 0) strncat(a1, a3, copy_limit);
  printf("a1 = %s\n", a1);

  // Duplicate a string, using my function, then print
  printf("Before dup, pointer a2 = %p, contents = %s\n", a2, a2);
  p2 = mystrdup(a2);
  printf("Pointer p2 = %p, contents = %s\n", p2, p2);

  //////////////////// NEW CODE WITH CUSTUM FUNCTIONS ////////////////////

  printf("\n\n--------NEW FUNCTIONS--------\n");

  char ac1[MAX_CHARS + 1]; // Character array--initially empty
  char ac2[] = "Hello"; // Character array--unsized but initialized
  char ac3[MAX_CHARS + 1]; // Character array--we will underfill it
  char ac4[MAX_CHARS + 1]; //Character array--will be underfilled
  char ac5[] = "Goodbye"; //Character array-unsized but initialized
  char* pc1 = "Hello"; // Pointer to constant string
  char* pc2;           // Will be a pointer to dynamically-allocated string
  char* pc3;           // WIll point to dynamically-allocated string
  int copy_limit_c;    // Maximum characters to copy.




  mystrcpy(ac3, "Hello, also"); // Initialize uinderfilled character array

  /* Print the pointers.
     Note: this example prints
     the values of the pointers themselves, not the targets.
  */
  printf("Pointers: ac1 = %p, ac2 = %p, ac3 = %p\n", ac1, ac2, ac3);
  printf("          pc1 = %p pc2 = %p\n", pc1, pc2);

  mystrcpy(ac1, "Hi"); // Initialize character array

  printf("ac1 = %s\n", ac1);
  printf("ac2 = %s\n", ac2);
  printf("ac3 = %s\n", ac3);

  // Concatenate two character arrays, then print.
  mystrcat(ac1, ac2);
  printf("ac1 = %s\n", ac1);

  // Concatenate two character arrays safely, then print.
  copy_limit_c= MAX_CHARS - mystrlen(ac1); // How much space is left?
  if (copy_limit_c > 0) mystrncat(ac1, ac2, copy_limit_c);
  printf("ac1 = %s\n", ac1);

  // Concatenate two character arrays safely, then print.
  copy_limit_c = MAX_CHARS - mystrlen(ac1); // How much space is left?
  if (copy_limit_c > 0) mystrncat(ac1, ac3, copy_limit_c);
  printf("ac1 = %s\n", ac1);

  // Duplicate a string, using my function, then print
  printf("Before dup, pointer ac2 = %p, contents = %s\n", ac2, ac2);
  pc2 = mystrdup(ac2);

  printf("Pointer pc2 = %p, contents = %s\n", pc2, pc2);

  mystrncpy(ac4,ac5,4);
  printf("ac4 = %s\n",ac4);

  printf("Before dup, pointer ac5 = %p, contents = %s\n", ac5, ac5);
  pc3 = mystrndup(ac5,4);
  printf("After partial dup, Pointer pc3 = %p, contents = %s\n", pc3, pc3);


  printf("\n\n--------FUN WITH STRUCTURES--------\n");

#define RAND_EMPLOYEE_COUNT 4

  //Make some Emplyees
  struct Employee* Bob = make_employee("Bob",1970,2000);
  struct Employee* Jeff = make_employee("Jeff",1993,2011);
  struct Employee* BigBossMan = make_employee("BigBossMan",1920,1940);

  //Print the Employees
  print_employee(Bob);
  print_employee(Jeff);
  print_employee(BigBossMan);

  printf("\n--------RANDOM STRUCTURES--------\n");
  struct Employee** arrayEmployeePtr = random_employees(RAND_EMPLOYEE_COUNT);
  printAllEmployees(arrayEmployeePtr,RAND_EMPLOYEE_COUNT);

  printf("\n--------SHALLOW COPY STRUCTURES--------\n");
  printAllEmployees(shallowCopyEmployees(arrayEmployeePtr,RAND_EMPLOYEE_COUNT),RAND_EMPLOYEE_COUNT);

  printf("\n--------DEEP COPY STRUCTURES--------\n");
 printAllEmployees(deepCopyEmployees(arrayEmployeePtr,RAND_EMPLOYEE_COUNT),RAND_EMPLOYEE_COUNT);

  freeAllEmplyees(arrayEmployeePtr,RAND_EMPLOYEE_COUNT);

  return 0;
}

/**Allocates an Employee struct and fills its fields
@param name Employee's name (max 99 characters)
@param birth_year Employee's birth year
@param start_year Employee's starting year
@return Pointer to the new struct
@author Steven Kordell
*/
struct Employee* make_employee(char* name, int birth_year, int start_year) {
  struct Employee* a = (struct Employee*) malloc(sizeof(struct Employee));
  mystrcpy(a->name, name);
  a->birth_year = birth_year;
  a->start_year = start_year;
  return a;
}

/**Prints an Employee struct
@param a Pointer to an Emplyee Structure
@author Steven Kordell
*/
void print_employee(struct Employee* a) {
  printf("Employee:\tname = %-29s\t birth_year = %d\t start_year = %d\n",a->name,a->birth_year,a->start_year);
}

/** makes a random employee struct
 *  @Return An Employee Struct with randomized fields
 *  @author Steven Kordell
*/
struct Employee* random_employee() {
  static char seedSet=0;
  if (!seedSet) {               //If the seed hasn't been set
    srand(time(NULL));          //Set the seed
    seedSet = 1;
  }
  int aRandInt1 = 1;            //temporary variable
  int aRandInt2 = 0;            //temproary variable
  while (aRandInt1 > aRandInt2) { //ensure starting year is after birth year
    aRandInt1 = genRandInt(200) + 1800;
    aRandInt2 = genRandInt(200) + 1800;
  }
  return make_employee(genRandString(genRandInt(29)),aRandInt1, aRandInt2); //make and return the stuct
}


/** Creates an array of pointers to randomized employee structs
 *  @param count Number of random structs to put in the array
 *  @return An array of randomized structs
 *  @author Steven Kordell
 */
struct Employee** random_employees(int count){
   int i;  //make a counter variable
   struct Employee** eArray = (struct Employee**) malloc(sizeof(struct Employee*) * count);   //Allocate space for the array of pointers
   //struct Employee** eArrayWork = eArray;
   while(i++ < count){     //Until we reached the count
     *(eArray++) = random_employee();  //generate a random emplyee and save the pointer to it.
   }
   return eArray-count; //Move the pointer back to the start and return it
}

/**Prints all the emplyee structures referenced by an array of pointers to those structures
 *  param eArray Array of pointers to structs
 *  num_elts Number of Elements in the array
 *  @author Steven Kordell
 */
void printAllEmployees(struct Employee** eArray, int num_elts) {
  int i = num_elts;  //make a counting variable
  while(i--) {
    print_employee(*(eArray++)); //print each array
  }
}

/**Duplicates an array of pointers to Emplyee structs, creates a "shallow copy"
 *@param src Array to shallow copy
 *@param n Number of elements in array
 *@retrun the duplicated array
 *@author Steven Kordell
 */
struct Employee** shallowCopyEmployees(struct Employee** src, int n) {
  int i;              //make an iterator
  struct Employee** duplicate = (struct Employee**) malloc(sizeof(struct Employee*) * n);               //allocate the necessary memory
  while(i++ < n) {   //copy the values
    *(duplicate++) = *(src++);
  }
  src-=n;            //reset the src pointer to the start of the array
  return duplicate-n; //return the start of the duplicate array
}

/**Takes an array of pointers to Employee structures and frees all the stucts pointed to
 *  @param src The array of pointers of structs to free
 *  @param n Number of pointers to structs in the array
 *  @author Steven Kordell
 */
void freeAllEmplyees(struct Employee** src,int n){
  int i=0;
  while (i++ < n) {
    free(*(src++));
   }
   free(src-n);
}

/**Duplicates all the structs in an array of pointers to Emplyee structs, and creates an array of pointers to these new stucts
 *@param src Array to deep copy
 *@param n Number of elements in array
 *@retrun the duplicated array
 *@author Steven Kordell
 */
struct Employee** deepCopyEmployees(struct Employee** src, int n) {
  int i = 0;
  struct Employee** duplicate = (struct Employee**) malloc(sizeof(struct Employee*) * n)
  while (i++ < n) {
    *duplicate = make_employee((*src)->name, (*src)->birth_year, (*src)->start_year);
  }

  return duplicate;
  // remember to reset pointers

}
