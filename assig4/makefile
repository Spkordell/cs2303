all: stest stest2 stest3 stest4 stest5

debug:
	gcc -g -c employeef.c
	gcc -g -c stest.c
	gcc -g -c stest2.c
	gcc -g -c stest3.c
	gcc -g -c stest4.c
	gcc -g -c stest5.c
	gcc -g stest.o employeef.o -lreadline -lncurses -o stest
	gcc -g stest2.o employeef.o -lreadline -lncurses -o stest2
	gcc -g stest3.o employeef.o -lreadline -lncurses -o stest3
	gcc -g stest4.o employeef.o -lreadline -lncurses -o stest4
	gcc -g stest5.o employeef.o -lreadline -lncurses -o stest5

debugplus:
	gcc -g -c employeef.c
	gcc -g -c -DDEBUG stest.c
	gcc -g -c -DDEBUG stest2.c
	gcc -g -c -DDEBUG stest3.c
	gcc -g -c -DDEBUG stest4.c
	gcc -g -c -DDEBUG stest5.c
	gcc -g stest.o employeef.o -lreadline -lncurses -o stest
	gcc -g stest2.o employeef.o -lreadline -lncurses -o stest2
	gcc -g stest3.o employeef.o -lreadline -lncurses -o stest3
	gcc -g stest4.o employeef.o -lreadline -lncurses -o stest4
	gcc -g stest5.o employeef.o -lreadline -lncurses -o stest5

stest5: stest5.o employeef.o
	gcc stest5.o employeef.o -lreadline -lncurses -o stest5

stest5.o: stest5.c employeef.h
	gcc -c stest5.c

stest4: stest4.o employeef.o
	gcc stest4.o employeef.o -lreadline -lncurses -o stest4

stest4.o: stest4.c employeef.h
	gcc -c stest4.c

stest3: stest3.o employeef.o
	gcc stest3.o employeef.o -lreadline -lncurses -o stest3

stest3.o: stest3.c employeef.h
	gcc -c stest3.c

stest2: stest2.o employeef.o
	gcc stest2.o employeef.o -lreadline -lncurses -o stest2

stest2.o: stest2.c employeef.h
	gcc -c stest2.c

stest: stest.o employeef.o
	gcc stest.o employeef.o -lreadline -lncurses -o stest

stest.o: stest.c employeef.h
	gcc -c stest.c

employeef.o: employeef.c employeef.h
	gcc -c employeef.c

clean: 
	rm -f *.o stest stest2 stest3 stest4 stest5

docs:
	doxygen
	chmod go+r ./html/*
	cp -p ./html/* ~/public_html/assig4
