mytest:hello.o test.o
	g++ hello.o test.o -o mytest
test.o:test.cpp
	g++ -c test.cpp -o test.o
hello.o:hello.cpp
	g++ -c hello.cpp -o hello.o

.PHONY:clean
clean:
	rm -f mytest *.o
