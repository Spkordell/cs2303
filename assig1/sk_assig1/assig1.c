/* assig1.c
   Class average program 
   modified by Steven Kordell*/

#include <stdio.h>
#include "statPrinter.h"

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
	   grades[counter-1]=grade; /*Add grade to array of grades*/
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

