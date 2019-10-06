.PHONY: all clean

CFLAGS=-Wall -Wextra -Werror -fsanitize=address -g -I include
CXXFLAGS=-fsanitize=address
LDFLAGS=-fsanitize=address

all: lab_03
obj: 
	mkdir obj
obj/clist.o:  src/clist.c | obj
	gcc $(CFLAGS) $(CXXLAGS) $(LDFLAGS) -c src/clist.c -o obj/clist.o
obj/main.o:  src/main.c | obj
	gcc $(CFLAGS) $(CXXLAGS) $(LDFLAGS) -c src/main.c -o obj/main.o
lab_03: obj/main.o obj/clist.o
	gcc $(CFLAGS) $(CXXLAGS) $(LDFLAGS) obj/main.o obj/clist.o -o lab_03
clean:
	rm -rf obj lab_03
