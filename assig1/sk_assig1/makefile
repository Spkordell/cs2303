all: assig1

assig1: assig1.o statPrinter.o
	gcc assig1.o statPrinter.o -o assig1
assig1.o: assig1.c statPrinter.h /usr/include/stdio.h
	gcc -c assig1.c
statPrinter.o: statPrinter.c statPrinter.h /usr/include/stdio.h
	gcc -c statPrinter.c
