GCC=g++
CPPFLAGS=-std=c++11 -O2 -Wall

extract: extract.o Out.o io.o
	$(GCC) $(CPPFLAGS) extract.o Out.o io.o -o extract 

extract.o: Out.hpp
Out.o: Out.hpp
io.o: io.hpp

clean:
	rm -f *.o extract
