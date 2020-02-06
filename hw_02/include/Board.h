#ifndef HW_02_BOARD_H_INCLUDED
#define HW_02_BOARD_H_INCLUDED

#include <cstdint>
#include <vector>



enum state {
    CONTINUE,
    DRAW,
    WIN
};


enum class Player {
    X = 'X',
    O = 'O'
};


enum class Field {
    NONE = '.',
    X = 'X',
    O = 'O'
};


class Board {
public:              
    Board();                    
    bool canMove(int x, int y);
    void move(int x, int y);
    state getState(int x, int y);
    Field return_side_field();
    Field return_last_side_field();
    Player return_side_player();
    std::vector<std::vector<Field>> get_field();
private: 
    int empty_cells = 100;
    bool side = true;
    state is_victory(int x, int y, Field side);
    std::vector<std::vector<Field>> field;
    void change_side();
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
    bool get_coor();
    void runGame();
    void input_processing(int x, int y);
private:
    Board &engine;
    BoardView view;
    bool silent;
    int x;
    int y;
};


#endif