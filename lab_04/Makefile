.PHONY: all clean

CFLAGS=-Wall -Wextra -Werror -g -I include


all: lab_04
obj: 
	mkdir obj
obj/mergesort.o:  src/mergesort.c include/mergesort.h | obj
	gcc $(CFLAGS) $(LDFLAGS) -c src/mergesort.c -o obj/mergesort.o
obj/main.o:  src/main.c | obj
	gcc $(CFLAGS) $(LDFLAGS) -c src/main.c -o obj/main.o
lab_04: obj/main.o obj/mergesort.o
	gcc $(CFLAGS) $(LDFLAGS) obj/main.o obj/mergesort.o -o lab_04
clean:
	rm -rf obj lab_04
