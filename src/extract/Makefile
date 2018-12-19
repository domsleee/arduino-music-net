GCC=g++
CPPFLAGS=-std=c++11 -O2 -Wall

extract: extract.o Out.o io.o tests.o main.o
	$(GCC) $(CPPFLAGS) extract.o Out.o tests.o io.o main.o -o extract

clean:
	rm -f *.o extract
