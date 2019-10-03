.PHONY: all clean

CFLAGS=-Wall -Wextra -Werror -fsanitize=address -g -I include
CXXFLAGS=-fsanitize=address
LDFLAGS=-fsanitize=address

all: lab2
obj: 
	mkdir obj
obj/str.o:  src/str.c | obj
	gcc $(CFLAGS) $(CXXLAGS) $(LDFLAGS) -c src/str.c -o obj/str.o
obj/test_str.o:  src/test_str.c | obj
	gcc $(CFLAGS) $(CXXLAGS) $(LDFLAGS) -c src/test_str.c -o obj/test_str.o
obj/test.o:  src/test.c | obj
	gcc $(CFLAGS) $(CXXLAGS) $(LDFLAGS) -c src/test.c -o obj/test.o
lab2: obj/test.o obj/str.o obj/test_str.o
	gcc $(CFLAGS) $(CXXLAGS) $(LDFLAGS) obj/test.o obj/str.o obj/test_str.o -o lab2
clean:
	rm -rf obj lab2
