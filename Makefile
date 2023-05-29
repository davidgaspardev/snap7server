CC = g++

lib/snap7/snap7.o: lib/snap7/snap7.cpp
	$(CC) -c $< -o $@

snap7server: snap7server.cpp lib/snap7/snap7.o
	$(CC) snap7server.cpp lib/snap7/snap7.o -o $@ -L/usr/lib -lsnap7

build: snap7server

all:
	./snap7server

clear:
	rm */**/*.o

.PHONY: all build clear