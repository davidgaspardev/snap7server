CC = g++
CINCLUDE = -Ilib/snap7

lib/snap7/snap7.o: lib/snap7/snap7.cpp
	$(CC) -c $< -o $@

bin/snap7server: src/snap7server.cpp lib/snap7/snap7.o
	$(CC) $(CINCLUDE) src/snap7server.cpp lib/snap7/snap7.o -o $@ -L/usr/lib -lsnap7

build: bin/snap7server

all:
	./snap7server

clear:
	rm */**/*.o
	rm snap7server

.PHONY: all build clear