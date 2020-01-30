#include <stdint.h>
#include <iostream>
#include <Board.h>


int main(/*int argc, char* argv[]*/) {
    /*test_map tests;
    init_test_map(tests);

    if (argc < 2 || 
        tests.find(argv[1]) == tests.end()) {
        run_all(tests);
    }
    else {
        tests[argv[1]]();
    }

    std::cout << "OK" << std::endl;
	*/
	Board q;
	StdioBoardView a(q);
	a.runGame();
	

    return 0;
}
