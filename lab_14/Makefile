INC = -Iinclude
FLAGS = -std=c++17 -Wall -Wextra  
CC = g++ 

.PHONY: all clean

all: lab_14

lab_14: obj/matrix.o obj/main.o | obj
	$(CC) $(INC) -o lab_14 $(FLAGS) obj/matrix.o obj/main.o

obj/matrix.o: src/matrix.cpp include/matrix.h | obj
	$(CC) $(INC) -c $(FLAGS) src/matrix.cpp -o obj/matrix.o

obj/main.o: src/main.cpp include/matrix.h | obj
	$(CC) $(INC) -c $(FLAGS) src/main.cpp -o obj/main.o

obj:
	mkdir obj

clean:
	rm -rf obj lab_14