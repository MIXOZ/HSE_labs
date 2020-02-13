#include <iostream>
#include <cstring>
#include <Board.h>


int main(int argc, char* argv[]) {
	bool flag = true;
	Board q;
	if (argc > 1)
		flag = strcmp(argv[1], "silent");
	StdioBoardView a(q, flag);
	a.run_game();
    return 0;
}
