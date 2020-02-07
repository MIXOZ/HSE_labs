INC = -Iinclude
FLAGS = -std=c++17 -Wall -Wextra
CC = g++ 

.PHONY: all clean

all: test_HW_02 HW_02

HW_02: obj/Board.o obj/main.o | obj
	$(CC) $(INC) -o HW_02 $(FLAGS) obj/Board.o obj/main.o

test_HW_02: obj/Board.o obj/Test.o obj/BoardTest.o | obj
	$(CC) $(INC) -o test_HW_02 $(FLAGS) obj/Board.o obj/BoardTest.o obj/Test.o

obj/BoardTest.o: test/BoardTest.cpp include/BoardTest.h | obj
	$(CC) $(INC) -c $(FLAGS) test/BoardTest.cpp -o obj/BoardTest.o

obj/Test.o: test/Test.cpp include/Test.h| obj
	$(CC) $(INC) -c $(FLAGS) test/Test.cpp -o obj/Test.o

obj/Board.o: src/Board.cpp include/Board.h | obj
	$(CC) $(INC) -c $(FLAGS) src/Board.cpp -o obj/Board.o

obj/main.o: src/main.cpp | obj
	$(CC) $(INC) -c $(FLAGS) src/main.cpp -o obj/main.o

obj:
	mkdir obj

clean:
	rm -rf obj HW_02 test_HW_02 