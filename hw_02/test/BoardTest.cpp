#include <stdint.h>
#include <iostream>
#include <Board.h>
#include <cstring>
#include <BoardTest.h>
#include <Board.h>
#include <Test.h>

void BoardTest::test_is_win1() {
    Board b;
    b.move(0, 0);
    b.move(0, 1);
    b.move(1, 0);
    b.move(4, 5);
    b.move(5, 5);
    DO_CHECK(b.is_victory(4, 5, Field::O) == CONTINUE);
}
    

void BoardTest::test_is_win2() {
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


void BoardTest::test_is_win3() {
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


void BoardTest::test_is_win4() {
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


void BoardTest::test_is_win5() {
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
    

void BoardTest::test_is_draw() {
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
    DO_CHECK(b.get_state(9, 9) == DRAW);
}


void BoardTest::test_move1() {
    Board b;
    b.move(0, 0);
    DO_CHECK(!b.can_move(0, 0));
}
    
void BoardTest::test_move2() {
    Board m;
    m.move(0, 0);
    DO_CHECK(m.can_move(9, 9));
}


void BoardTest::test_move3() {
    Board m;
    m.move(0, 1);
    m.move(1, 0);
    m.move(3, 5);
    m.move(4, 4);
    DO_CHECK(m.can_move(5, 3));
}


void BoardTest::run_all_tests() {
    test_is_win1();
    test_is_win2();
    test_is_win3();
    test_is_win4();
    test_is_win5();
    test_is_draw();
    test_move1();
    test_move2();
    test_move3();
}

