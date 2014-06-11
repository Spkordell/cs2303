#include <stdio.h>
#include "statPrinter.h"

/*function to calculate the maximum, minimum, and average of the data*/
void printGradeStats(int grades[MAX_GRADES],int size) {
  int max=-1;                          /*Variable to hold the maximum*/
  int min=101;                         /*variable to hold the minimum*/
  int sum=0;                           /*variable to hold the sum of the grades*/
  int i;
  for (i = 0; i<size; i++) {          /*Iterate over data computing stats*/
    if (grades[i] > max) {/*Is the selected element the largest encountered?*/
      max = grades[i];                 /*If true, save it*/
    }
    if (grades[i] < min) {  /*Is the selected element the smallest encountered?*/
      min = grades[i];                 /*If ture, save it.*/
    }
    sum+=grades[i];                    /*Sum data for average calculation later*/
  }
  printf("Maximum Grade: %d\n",max);   /*print maximum value*/
  printf("Minimum Grade: %d\n",min);   /*print minimum value*/
  printf("Average Grade: %d\n",sum/size);       /*Calculate and print average*/
}
