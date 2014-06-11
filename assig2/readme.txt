Name: Steven Kordell

Class: CS2303

Section: C04

Assignment: 2

Date Due: 01/28/2013


File List:
readme.txt
at.c
at2.c
at3.c
print_array.c
sort_arrays.c
print_arrays.h
sort_arrays.h
makefile
Doxyfile


Program description:
at:
Fills an array with consecutive integers between 0 and 9 inclusive. Prints the array placeing each element on a new line.

at2:
Prompts the user to enter integers.The program will accept data until the user either enters a negative number or the array reaches its maximum size (currently 10). The program ignores inputs over a maximum value (currently 100).  Each integer value is stored in an array and the array is printed with each elelement placed on a new line. The array is then sorted in ascending order and printed again. The program also fills an array with consecutive doubles and prints this array.

at3:
The program fills an array of a hardcoded size (currently 10) with random values between zero and a hardcoded maximum value inclusive (currently 100).The program prints the array with different elements on different lines. The program then sorts the data in ascending order and prints the modified array.The seed valuefor the random number generator is taken from the current time, resulting in a different array of values on each execution.


Compilation instructions:
Unzip the contents of this zip file with the unzip command. Cd to the correct directory and run "make", without quotes. Three executable files will be produced, at, at2,and at3.
Running "make docs", will generate the Doxygen output file and copy the files (with the correct access permissions) to the assig2 folder of the users public_html directory.
Running "make clean" will remove all object files and the three exectuables (at, at2, and at3) from the directory.


Execution instructions:
To execute at, cd to the correct directory and enter  "./at" into the command line, without the quotes.
To execute at2, cd to the correct directory and enter "./at2" into the command line, without the quotes.
To execute at3, cd to the correct directory and enter "./at3" into the command line, without the quotes.
