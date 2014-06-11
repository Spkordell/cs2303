/* assig1.c
   Class average program 
   modified by Steven Kordell*/
#include <stdio.h>

/*constants*/
#define MAX_GRADES (20)

void printGradeStats(int grades[MAX_GRADES],int size);

/* function main begins program execution */
int main( void )
{
   int counter;      /* number of grade to be entered next */
   int grade;        /* grade value */
   int total;        /* sum of grades input by user */
   int average;      /* average of grades */
   int grades[MAX_GRADES]; /*array to store the grades as they are entered*/
   
   /* initialization phase */
   total = 0;        /* initialize total */
   counter = 1;      /* initialize loop counter */
   grade = 0;        /* initialize grade */

   printf("Enter the grades to be averaged.\n");
   printf("When finished, enter any negative number to stop data collection");
   printf(" and compute result.\n"); /*Print user instructions*/
   
   /* processing phase */
   while (grade >= 0 && counter<(MAX_GRADES+1)) {           /* if grade is non-negative */
      printf( "Enter grade: " );  /* prompt for input */
      scanf( "%d", &grade );      /* read grade from user */
      if (grade >= 0){            /* if grade is non-negative */
	if (grade <=  100) {      /*Ensure grade is less than maximum value*/
	   grades[counter]=grade; /*Add grade to array of grades*/
	   total = total + grade; /* add grade to total */
	   counter++;             /* increment counter */ 
	} else {
	  printf("Grade exceeds maximum value. Grades must be less than 100\n"); /*Warning to user*/
	}
      } /*end if */
   } /* end while */
   if (counter>=MAX_GRADES) {
     printf("Maximum amount of grades have been entered. You cannot enter anymore.\n");
   }

   /* termination phase */
   if (counter > 1){                     /* Ensure the user entered grades */
     printGradeStats(grades,counter-1);  /*calculate and print the maximum, minimum, and average of the data*/
   } else {                              /* If the user didn't enter any grades */
     printf("No grades entered.\n");     /*Warn user*/
   }

   return 0; /* indicate program ended successfully */
} /* end function main */

void printGradeStats(int grades[MAX_GRADES],int size) { /*function to calculate the maximum, minimum, and average of the data*/
  int max=-1;                                           /*Variable to hold the maximum*/
  int min=101;                                          /*variable to hold the minimum*/
  int sum=0;                                            /*variable to hold the sum of the grades*/
  int i;
  for (i = 0; i<=size; i++) {                           /*Iterate over data computing stats*/
    if (grades[i] > max) {                              /*Is the selected element the largest encountered?*/
      max = grades[i];                                  /*If true, save it*/
    }
    if (grades[i] < min) {                              /*Is the selected element the smallest encountered?*/
      min = grades[i];                                  /*If ture, save it.*/
    }
    sum+=grades[i];                                     /*Sum data for average calculation later*/
  }
  printf("Maximum Grade: %d\n",max);                    /*print maximum value*/
  printf("Minimum Grade: %d\n",min);                    /*print minimum value*/
  printf("Average Grade: %d\n",sum/size);               /*Calculate and print average*/
}

/**************************************************************************
 * (C) Copyright 1992-2010 by Deitel & Associates, Inc. and               *
 * Pearson Education, Inc. All Rights Reserved.                           *
 *                                                                        *
 * DISCLAIMER: The authors and publisher of this book have used their     *
 * best efforts in preparing the book. These efforts include the          *
 * development, research, and testing of the theories and programs        *
 * to determine their effectiveness. The authors and publisher make       *
 * no warranty of any kind, expressed or implied, with regard to these    *
 * programs or to the documentation contained in these books. The authors *
 * and publisher shall not be liable in any event for incidental or       *
 * consequential damages in connection with, or arising out of, the       *
 * furnishing, performance, or use of these programs.                     *
 *************************************************************************/

