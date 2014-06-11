/* Fig. 3.6: fig03_06.c
   Class average program 
   modified by Steven Kordell*/
#include <stdio.h>

/* function main begins program execution */
int main( void )
{
   int counter;      /* number of grade to be entered next */
   int grade;        /* grade value */
   int total;        /* sum of grades input by user */
   int average;      /* average of grades */
   
   /* initialization phase */
   total = 0;        /* initialize total */
   counter = 1;      /* initialize loop counter */
   grade = 0;        /* initialize grade */

   printf("Enter the grades to be averaged.\n");
   printf("When finished, enter any negative number to stop data collection");
   printf(" and compute result.\n"); /*Print user instructions*/
   
   /* processing phase */
   while (grade >= 0) {           /* if grade is non-negative */
      printf( "Enter grade: " );  /* prompt for input */
      scanf( "%d", &grade );      /* read grade from user */
      if (grade >= 0){            /* if grade is non-negative */
	if (grade <=  100) {      /*Ensure grade is less than maximum value*/
	  total = total + grade;  /* add grade to total */
	  counter = counter + 1;  /* increment counter */
	} else {
	  printf("Grade exceeds maximum value. Grades must be less than 100\n"); /*Warning to user*/
	}
      } /*end if */
   } /* end while */
   
   /* termination phase */
   if (counter > 1){                     /* Ensure the user entered grades */
     average = total / (counter-1);      /* integer division */
   } else {                              /* If the user didn't enter any grades */
     average = 0;                        /*Set Average to zero*/
     printf("No grades entered.\n");     /*Warn user*/
   }

   printf( "Class average is %d\n", average ); /* display result */
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

