#ifndef HW_02_BOARD_H_INCLUDED
#define HW_02_BOARD_H_INCLUDED


#include <stdint.h>
#include <iostream>

enum state{
    CONTINUE,
    DRAW,
    WIN
};


enum class Player{
    X = 'X',
    O = 'O'
};


enum class Field{
    NONE = '.',
    X = 'X',
    O = 'O'
};


class Board {
public:                                  
    bool canMove(int x, int y);
    void move(int x, int y);
    state is_victory(int x, int y, Field side);
    state getState(int x, int y);
    void change_side();
    Field return_side_field();
    Field return_last_side_field();
    Field field[10][10];
    void feel_field();
    Player return_side_player();
private: 
    int empty_cells = 100;
    bool side = false;
};



class BoardView {
public:
    void print_field(Board *engine);

    void print_game_line(Player side);
    void print_win(Field side);

    void print_draw();

    void print_error();
};



class StdioBoardView {
public:
    StdioBoardView(Board &board, bool &flag) : engine(board), silent(flag){};
    void runGame();
    void input_processing(int x, int y);
    //~StdioBoardView();
private:
    Board &engine;
    BoardView view;
    bool silent;
    int x;
    int y;
};


#endif