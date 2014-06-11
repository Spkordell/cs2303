ctest: ctest.o mystring.o
	gcc ctest.o mystring.o -o ctest

ctest.o: ctest.c mystring.h
	gcc -c ctest.c

mystring.o: mystring.c mystring.h
	gcc -c mystring.c

clean: 
	rm -f mystring.o ctest.o ctest

docs:
	doxygen
	chmod go+r ./html/*
	cp -p ./html/* ~/public_html/assig3
