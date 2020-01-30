#include <stdint.h>
#include <iostream>
#include <Board.h>
#include <cstring>


int main(int argc, char* argv[]) {
	bool flag = true;
	Board q;
	if (argc > 1)
		flag = strcmp(argv[1], "silent");
	StdioBoardView a(q, flag);
	a.runGame();
	

    return 0;
}
