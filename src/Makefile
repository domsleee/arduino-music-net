all: Sync_const.o Sync_init.o

Sync_const.o: Sync.hpp
	g++ -c Sync_const.cpp -o Sync_const.o

Sync_init.o: Sync.hpp
	g++ -c Sync_init.cpp -o Sync_init.o

clean:
	rm *.o