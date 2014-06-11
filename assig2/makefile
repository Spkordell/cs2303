all: at at2 at3

at: at.o print_arrays.o
	gcc -g at.o print_arrays.o -o at

at.o: at.c print_arrays.h /usr/include/stdio.h
	gcc -g -c at.c

at2: at2.o print_arrays.o sort_arrays.o
	gcc -g at2.o print_arrays.o sort_arrays.o -o at2

at2.o: at2.c print_arrays.h sort_arrays.h  /usr/include/stdio.h
	gcc -g -c at2.c

at3: at3.o print_arrays.o sort_arrays.o
	gcc -g at3.o print_arrays.o sort_arrays.o -o at3

at3.o: at3.c print_arrays.h sort_arrays.h /usr/include/stdio.h
	gcc -g -c at3.c 

print_arrays.o: print_arrays.c print_arrays.h
	gcc -g -c print_arrays.c

sort_arrays.o: sort_arrays.c sort_arrays.h
	gcc -g -c sort_arrays.c

clean:
	rm -f *.o
	rm -f at
	rm -f at2
	rm -f at3

docs:
	doxygen
	chmod go+r ./html/*
	cp -p ./html/* ~/public_html/assig2
