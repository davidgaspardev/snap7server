CC = g++
CINCLUDE = -Ilib/snap7 -Ilib/logs

lib/snap7/snap7.o: lib/snap7/snap7.cpp
	$(CC) -c $< -o $@

lib/logs/logs.o: lib/logs/logs.c
	$(CC) -c $< -o $@

bin/snap7server: src/snap7server.cpp lib/snap7/snap7.o lib/logs/logs.o
	$(CC) $(CINCLUDE) $^ -o $@ -lsnap7

build: bin/snap7server

run:
	@./bin/snap7server

clear:
	rm -r */**/*.o
	rm -r bin/snap7server

.PHONY: run build clear run