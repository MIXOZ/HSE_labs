INC = -Iinclude
FLAGS = -std=c++17 -Wall -Wextra  
CC = g++ 

.PHONY: all clean

all: lab_13

lab_13: obj/main.o | obj
	$(CC) $(INC) -o lab_13 $(FLAGS) obj/main.o

obj/main.o: src/main.cpp include/my_array.h | obj
	$(CC) $(INC) -c $(FLAGS) src/main.cpp -o obj/main.o

obj:
	mkdir obj

clean:
	rm -rf obj lab_13