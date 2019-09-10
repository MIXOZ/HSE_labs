.PHONY: all clean

CFLAGS=-Wall -Wextra -Werror -g -I include

all: lab1
bin: 
	mkdir bin
main.o: src/main.c bin
	gcc $(CFLAGS) -c src/main.c -o bin/main.o
max.o: src/max.c bin
	gcc $(CFLAGS) -c src/max.c -o bin/max.o
doComputation.o: src/doComputation.c bin
	gcc $(CFLAGS) -c src/doComputation.c -o bin/doComputation.o
logDebug.o: src/logDebug.c bin
	gcc $(CFLAGS) -c src/logDebug.c -o bin/logDebug.o
lab1: main.o max.o doComputation.o logDebug.o 
	gcc bin/main.o bin/max.o bin/doComputation.o bin/logDebug.o -o lab1
clean:
	rm -rf bin lab1
