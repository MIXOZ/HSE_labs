.PHONY: all clean

CFLAGS=-Wall -Wextra -Werror -fsanitize=address -g -I include
LDFLAGS=-fsanitize=address

all: lab_05
obj: 
	mkdir obj
obj/clist.o:  src/clist.c include/clist.h | obj
	gcc $(CFLAGS) $(LDFLAGS) -c src/clist.c -o obj/clist.o
obj/point_list.o:  src/point_list.c include/point_list.h | obj
	gcc $(CFLAGS) $(LDFLAGS) -c src/point_list.c -o obj/point_list.o
obj/main.o:  src/main.c | obj
	gcc $(CFLAGS) $(LDFLAGS) -c src/main.c -o obj/main.o
lab_05: obj/main.o obj/clist.o obj/point_list.o
	gcc $(CFLAGS) $(LDFLAGS) obj/main.o obj/clist.o obj/point_list.o -o lab_05
clean:
	rm -rf obj lab_05
