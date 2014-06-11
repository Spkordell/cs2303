Name: Steven Kordell
Class: CS2303
Section: C04
Assignment: 5
Date Due: 02/16/2013

File List:
readme.txt
stacktest.c
queuetest.c
treetest.c
randomtreetest.c
stack.c
queue.c
tree.c
stack.h
queue.h
tree.h
makefile
Doxyfile


Program descriptions:

stacktest:
This program creates a stack with room for 5 things. It thoroughly tests various stack operations.

queuetest:
This program creates a queue with room for 5 things.It thoroughly tests various queue operations.

treetest:
This program creates a tree with predefined strings that are organized into the branches  in alphabetical order. In traverses the tree to print the values of the tree in descending order. It then deallocates the memory used by the tree.

randomtreetest:
This program creates random strings of characters and places them in a tree with the branches organized in alphabetical order. It traverses the tree to print the values of the tree in descending tree. It then dealocates the memory used by the tree.


Compilation instructions:
Unzip the contents of this zip file with the unzip command. Cd to the correct directory and run "make", without quotes. Four  executable files (stacktest, queuetest, treetest, and randomtreetest) will be produced.
Running "make docs", will generate the Doxygen output file and copy the files (with the correct access permissions) to the assig5 folder of the user's public_html directory.
Running "make clean" will remove all object files and the executables from the directory.


Execution instructions:
To execute, cd to the correct directory and enter  "./stacktest", "./queuetest", "./treetest", or "./randomtreetest"  into the command line, without the quotes.
