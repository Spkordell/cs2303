all: stacktest queuetest treetest randomtreetest

randomtreetest: randomtreetest.o tree.o
	gcc -g randomtreetest.o tree.o -o randomtreetest

randomtreetest.o: randomtreetest.c tree.h
	gcc -g -c randomtreetest.c 

treetest: treetest.o tree.o
	gcc -g treetest.o tree.o -o treetest

tree.o: tree.c tree.h
	gcc -g -c tree.c

treetest.o: treetest.c tree.h
	gcc -g -c treetest.c

queuetest: queuetest.o queue.o
	gcc -g queuetest.o queue.o -o queuetest

queue.o: queue.c queue.h
	gcc -g -c queue.c

queuetest.o: queuetest.c queue.h
	gcc -g -c queuetest.c

stacktest: stacktest.o stack.o
	gcc -g stacktest.o stack.o -o stacktest

stack.o: stack.c stack.h
	gcc -g -c stack.c

stacktest.o: stacktest.c stack.h
	gcc -g -c stacktest.c

clean:
	rm -f *.o
	rm -f stacktest
	rm -f queuetest
	rm -f treetest

docs:
	doxygen
	chmod go+r ./html/*
	cp -p ./html/* ~/public_html/assig5
