#include <stdint.h>
#include <iostream>
#include <Board.h>
#include <cstring>
#include <BoardTest.h>
#include <Board.h>
#include <cstring>


void Test::check(bool expr, const char *func, const char  *filename, size_t lineNum) {
    if (!expr) {
        std::cout << "Error in function: " << func 
                  << ", in file: " << filename << ", in line: " << lineNum << "\n";
        failedNum++;
    }
    totalNum++;
}


void BoardTest::testIsWin1() {
    Board b;
    b.move(0, 0);
    b.move(0, 1);
    b.move(1, 0);
    b.move(4, 5);
    b.move(5, 5);
    DO_CHECK(b.is_victory(4, 5, Field::O) == CONTINUE);
}
    

void BoardTest::testIsWin2() {
    Board b;
    b.move(0, 0);
    b.move(1, 0);
    b.move(0, 1);
    b.move(1, 1);
    b.move(0, 2);
    b.move(1, 2);
    b.move(0, 3);
    b.move(1, 3);
    b.move(0, 4);
    DO_CHECK(b.is_victory(0, 4, Field::O) == WIN);
}


void BoardTest::testIsWin3() {
    Board b;
    b.move(0, 0);
    b.move(0, 1);
    b.move(1, 0);
    b.move(1, 1);
    b.move(2, 0);
    b.move(2, 1);
    b.move(3, 0);
    b.move(3, 1);
    b.move(4, 0);
    DO_CHECK(b.is_victory(4, 0, Field::O) == WIN);
}


void BoardTest::testIsWin4() {
    Board b;
    b.move(0, 0);
    b.move(0, 1);
    b.move(1, 1);
    b.move(1, 2);
    b.move(2, 2);
    b.move(2, 3);
    b.move(3, 3);
    b.move(3, 1);
    b.move(4, 4);
    DO_CHECK(b.is_victory(4, 4, Field::O) == WIN);
}


void BoardTest::testIsWin5() {
    Board b;
    b.move(0, 0);
    b.move(9, 0);
    b.move(1, 1);
    b.move(8, 1);
    b.move(2, 2);
    b.move(7, 2);
    b.move(3, 3);
    b.move(6, 3);
    b.move(4, 4);
    b.move(5, 4);
    DO_CHECK(b.is_victory(5, 4, Field::X) == WIN);
}
    

void BoardTest::testIsDraw() {
    Board b;
    for (int i = 0; i < 4; ++i) {
        b.move(i, 0);
        b.move(i, 1);
        b.move(i, 2);
        b.move(i, 3);
        b.move(i, 4);
        b.move(i, 5);
        b.move(i, 6);
        b.move(i, 7);
        b.move(i, 8);
        b.move(i, 9);
    }
    for (int i = 4; i < 8; ++i) {
        b.move(i, 0);
        b.move(i, 1);
        b.move(i, 2);
        b.move(i, 3);
        b.move(i, 4);
        b.move(i, 5);
        b.move(i, 6);
        b.move(i, 7);
        b.move(i, 8);
        b.move(i, 9);
    }
    for (int i = 8; i < 10; ++i) {
        b.move(i, 0);
        b.move(i, 1);
        b.move(i, 2);
        b.move(i, 3);
        b.move(i, 4);
        b.move(i, 5);
        b.move(i, 6);
        b.move(i, 7);
        b.move(i, 8);
        b.move(i, 9);
    }
    DO_CHECK(b.getState(9, 9) == DRAW);
}


void BoardTest::testMove1() {
    Board b;
    b.move(0, 0);
    DO_CHECK(!b.canMove(0, 0));
}
    
void BoardTest::testMove2() {
    Board m;
    m.move(0, 0);
    DO_CHECK(m.canMove(9, 9));
}


void BoardTest::testMove3() {
    Board m;
    m.move(0, 1);
    m.move(1, 0);
    m.move(3, 5);
    m.move(4, 4);
    DO_CHECK(m.canMove(5, 3));
}


void BoardTest::runAllTests() {
    testIsWin1();
    testIsWin2();
    testIsWin3();
    testIsWin4();
    testIsWin5();
    testIsDraw();
    testMove1();
    testMove2();
    testMove3();
}


bool BoardTest::showFinalResult() {
    if (failedNum == 1) {
        std::cout << failedNum << " test failed from " << totalNum << "\n";
        return false;   
    }
    std::cout << failedNum << " tests failed from " << totalNum << "\n";
    if (!failedNum) return false;
    return true;
}
