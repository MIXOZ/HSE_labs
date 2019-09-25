.PHONY: all clean

CFLAGS=-Wall -Wextra -Werror -g -I include

all: lab2
obj: 
	mkdir obj
test.o: src/test.c obj
	gcc $(CFLAGS) -c src/test.c -o obj/test.o
str.o:  src/str.c obj
	gcc $(CFLAGS) -c src/str.c -o obj/str.o
test_str.o:  src/test_str.c obj
	gcc $(CFLAGS) -c src/test_str.c -o obj/test_str.o
lab2: src/test.o str.o test_str.o
	gcc obj/test.o obj/str.o obj/test_str.o -o lab2
clean:
	rm -rf obj lab2
