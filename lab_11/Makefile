INC = -Iinclude
FLAGS = -std=c++17 -Wall -Wextra 
CC = g++

.PHONY: all clean

all: lab_11

lab_11: obj/bin_manip.o obj/employees.o obj/main.o | obj
	$(CC) $(INC) -o lab_11 $(FLAGS) obj/bin_manip.o obj/employees.o obj/main.o

obj/bin_manip.o: src/bin_manip.cpp | obj
	$(CC) $(INC) -c $(FLAGS) src/bin_manip.cpp -o obj/bin_manip.o

obj/main.o: src/main.cpp | obj
	$(CC) $(INC) -c $(FLAGS) src/main.cpp -o obj/main.o

obj/employees.o: src/employees.cpp | obj
	$(CC) $(INC) -c $(FLAGS) src/employees.cpp -o obj/employees.o

obj:
	mkdir obj

clean:
	rm -rf obj lab_11