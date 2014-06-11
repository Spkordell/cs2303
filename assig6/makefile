all: cptest cptest2

cptest2: cptest2.o
	gcc -g cptest2.o -o cptest2

cptest2.o: cptest2.c
	gcc -c -g cptest2.c

cptest: cptest.o
	gcc -g cptest.o -o cptest

cptest.o: cptest.c
	gcc -c -g cptest.c

docs:
	doxygen
	chmod go+r ./html/*
	cp -p ./html/* ~/public_html/assig6

clean:
	rm -f *.o cptest cptest2


