Name: Steven Kordell
Class: CS2303
Section: C04
Assignment: 3
Date Due: 02/04/2013


File List:
readme.txt
ctest.c
mystring.c
mystring.h
makefile
Doxyfile


Program description:
The program demonstrates various funcions involving pointers and structures. First it makes some strings and performs serveral operations on those strings such as copying, concatination, and dynamic memory allocation for duplication. The program does this twice, once using the standared string functions, and once using custom written string functions that duplicate the functionality of the standared functions. The program also makes several employee structs. It creates an array of pointers to random structs, prints these structs to the terminal, then performs both a shallow and deep copy on the array of pointers to structs. All the functions are pointer intensive.


Compilation instructions:
Unzip the contents of this zip file with the unzip command. Cd to the correct directory and run "make", without quotes. An executable file ctest will be produced.
Running "make docs", will generate the Doxygen output file and copy the files (with the correct access permissions) to the assig3 folder of the users public_html directory.
Running "make clean" will remove all object files and the executable from the directory.


Execution instructions:
To execute, cd to the correct directory and enter  "./ctest" into the command line, without the quotes.
