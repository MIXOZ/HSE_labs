#ifndef HW_02_BOARD_TEST_H_INCLUDED
#define HW_02_BOARD_TEST_H_INCLUDED


#include <Test.h>
#include <Board.h>



class BoardTest : public Test {
private:
    void test_is_win1();
    void test_is_win2();
    void test_is_win3();
    void test_is_win4();
    void test_is_win5();
    void test_is_win6();
    void test_is_draw();
    void test_move1();
    void test_move2();
    void test_move3();
public:
    void run_all_tests();
};


#endif