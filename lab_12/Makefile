INC = -Iinclude
FLAGS = -std=c++17 -Wall -Wextra -Werror
CC = g++ 

.PHONY: all clean

all: lab_12

lab_12: obj/main.o | obj
	$(CC) $(INC) -o lab_12 $(FLAGS) obj/main.o

obj/main.o: src/main.cpp include/my_vector_impl.h include/my_vector.h | obj
	$(CC) $(INC) -c $(FLAGS) src/main.cpp -o obj/main.o

obj:
	mkdir obj

clean:
	rm -rf obj lab_12