#ifndef HW_02_TEST_H_INCLUDED
#define HW_02_TEST_H_INCLUDED

#define  DO_CHECK(EXPR) check(EXPR, __func__, __FILE__, __LINE__);

#include <stdint.h>
#include <iostream>
#include <Board.h>
#include <Board.h>
#include <cstring>

class Test {
protected:
    int failed_num = 0; // количество тестов, которые сломались
    int total_num = 0;  // общее количество тестов
    /** Проверяет условие (expr) на верность в конце теста.
        В одном тесте может быть не более одного `check`.
        Сообщает об результате пользователю, в случае неудачи подробно сообщает об источнике. */
    void check(bool expr, const char *func, const char  *filename, size_t line_num);
public:
    /** Вызывается один раз в конце автотестов, выводит общую статистику по
        пройденным тестам на экран. Возвращает `true` если и только если
        все тесты успешно пройдены. */
    bool show_final_result();
    /** Запускает все тесты в конкретном наборе тестов */
    virtual void run_all_tests() = 0;

    // Можно добавлять методы при необходимости 
};


#endif