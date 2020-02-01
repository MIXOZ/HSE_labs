#ifndef HW_02_BOARD_TEST_H_INCLUDED
#define HW_02_BOARD_TEST_H_INCLUDED
#define  DO_CHECK(EXPR) check(EXPR, __func__, __FILE__, __LINE__);


#include <stdint.h>
#include <iostream>
#include <Board.h>
#include <Board.h>
#include <cstring>


class Test {
protected:
    int failedNum = 0; // количество тестов, которые сломались
    int totalNum = 0;  // общее количество тестов
    /** Проверяет условие (expr) на верность в конце теста.
        В одном тесте может быть не более одного `check`.
        Сообщает об результате пользователю, в случае неудачи подробно сообщает об источнике. */
    void check(bool expr, const char *func, const char  *filename, size_t lineNum);
public:
    /** Вызывается один раз в конце автотестов, выводит общую статистику по
        пройденным тестам на экран. Возвращает `true` если и только если
        все тесты успешно пройдены. */
    virtual bool showFinalResult() = 0;
    /** Запускает все тесты в конкретном наборе тестов */
    virtual void runAllTests() = 0;

    // Можно добавлять методы при необходимости 
};


class BoardTest : public Test {
private:
    void testIsWin1();
    void testIsWin2();
    void testIsWin3();
    void testIsWin4();
    void testIsWin5();
    void testIsDraw();
    void testMove1();
    void testMove2();
    void testMove3();
public:
    void runAllTests();
    bool showFinalResult();
};


#endif