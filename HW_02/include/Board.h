#ifndef HW_02_BOARD_H_INCLUDED
#define HW_02_BOARD_H_INCLUDED


#include <stdint.h>
#include <iostream>

enum state{
    CONTINUE,
    DRAW,
    WIN
};


class Board {
public:                                  
    bool canMove(int x, int y);
    void move(int x, int y);
    bool is_victory(int x, int y, char side);
    state getState(int x, int y);
    void change_side();
    char return_side();
    char field[10][10];
    void feel_field();
    char return_other_side();
private: 
    int empty_cells = 100;
    bool side = false;
};



class BoardView {
public:
    void print_field(Board *engine);

    void print_game_line(char side);
    void print_win(char side);

    void print_draw();

    void print_error();
};



class StdioBoardView {
public:
    StdioBoardView(Board &board) : engine(board){};
    void runGame();
    void input_processing(int x, int y);
    //~StdioBoardView();
private:
    Board &engine;
    BoardView view;
    int x;
    int y;
};


#endif