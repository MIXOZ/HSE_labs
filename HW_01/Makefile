.PHONY: all clean

CFLAGS=-Wall -Wextra -Werror -fsanitize=address -g -I include
LDFLAGS=-fsanitize=address 

all: HW_01
obj: 
	mkdir obj
obj/bmp.o:  src/bmp.c include/bmp.h | obj
	gcc $(CFLAGS) $(LDFLAGS) -c src/bmp.c -o obj/bmp.o
obj/main.o:  src/main.c include/bmp.h | obj
	gcc $(CFLAGS) $(LDFLAGS) -c src/main.c -o obj/main.o
HW_01: obj/main.o obj/bmp.o
	gcc $(CFLAGS) $(LDFLAGS) obj/main.o obj/bmp.o -o HW_01
clean:
	rm -rf obj HW_01
