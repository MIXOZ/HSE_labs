#include <stdint.h>
#include <iostream>
#include <Board.h>
#include <cstring>
#include "BoardTest.h"


int main() {
    BoardTest bt;
    bt.runAllTests();
   	bt.showFinalResult();
    return 0;
}