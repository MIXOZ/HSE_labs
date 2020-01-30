#include <stdint.h>
#include <iostream>
#include <Board.h>


/**------------------Board-------------------*/

/** Проверить ход на корректность, если бы он был следующим. */
bool Board::canMove(int x, int y) {
    return (field[x][y] == Field::NONE && x < 10 && y < 10 && x >= 0 && y >= 0);   
}

/** Сделать ход. UB, если он некорректен. */
void Board::move(int x, int y) {
    field[x][y] = return_side_field();
    empty_cells--;
    change_side();
}

/** Проверка на окончание игры. */

state Board::is_victory(int x, int y, Field side) {
    int delta_x_arr[4] = {-1, 0, 1, 1};
    int delta_y_arr[4] = {1, 1, 0, 1};
    for (int itr = 0; itr < 4; ++itr) {
        int i = x;
        int j = y;
        int k = -1;
        while (i >= 0 && j >= 0 && i < 10 && j < 10)
            if (field[i][j] == side) {k++; i -= delta_x_arr[itr]; j -= delta_y_arr[itr];}
            else break;
        i = x;
        j = y;
        while (i < 10 && j < 10 && i >= 0 && j >= 0)
            if (field[i][j] == side) {k++; i += delta_x_arr[itr]; j += delta_y_arr[itr];}
            else break;
        if (k >= 5) return WIN;
    }
    return CONTINUE;
}

/** Состояние игры: игра идёт, игра кончилась с одним из результатов: ничья, победа одной из сторон. */
state Board::getState(int x, int y){
    if (is_victory(x, y, return_last_side_field()) == WIN) return WIN;
    if (empty_cells == 0) return DRAW;
    return CONTINUE;
}

void Board::change_side() {
    side = !side;
}

Field Board::return_side_field(){
    if (side) return Field::O;
    else return Field::X;
}


Field Board::return_last_side_field(){
    if (side) return Field::X;
    else return Field::O;
}

Player Board::return_side_player(){
    if (side) return Player::O;
    else return Player::X;
}

void Board::feel_field() {
    for (size_t i = 0; i < 10; ++i) 
        for (size_t j = 0; j < 10; ++j ) 
            field[i][j] = Field::NONE;
}


/**---------------StdioBoardView----------------*/


/** Основной цикл игры, от начала до конца. */
void StdioBoardView::runGame() {
    engine.feel_field();
    if (silent)
        view.print_field(&engine);
    
    view.print_game_line(engine.return_side_player());
    //engine.change_side();
    std::cin >> x >> y;

    while (x != -1 && y != -1) {
        input_processing(x, y);
        state current_state = engine.getState(x, y);
        if (current_state == CONTINUE) view.print_game_line(engine.return_side_player());
        else if (current_state == WIN) {
            view.print_win(engine.return_side_field());
            return;
        } else if (current_state == DRAW) {
            view.print_draw();
            return;
        }
        std::cin >> x >> y;
    }
}

// Можно добавлять методы при необходимости.

void StdioBoardView::input_processing(int x, int y) {
    if (engine.canMove(x, y)) { 
        engine.move(x, y); 
        if (silent)
            view.print_field(&engine);
    } else {
        view.print_error();
    }
}

void BoardView::print_field(Board *engine) {
    for (size_t i = 0; i < 10; ++i) {
        for (size_t j = 0; j < 10; ++j ) {
            if (engine->field[i][j] == Field::X)
                std::cout << 'X';
            else if (engine->field[i][j] == Field::O)
                std::cout << 'O';
            else if (engine->field[i][j] == Field::NONE)
                std::cout << '.';
        }
        std::cout << "\n";
    }
}

void BoardView::print_game_line(Player side) {
    if (side == Player::X)
        std::cout << 'X' << " move:\n";
    else if (side == Player::O)
        std::cout << 'O' << " move:\n";
}

void BoardView::print_win(Field side) {
    if (side == Field::X)
        std::cout << 'X' << " wins!\n";
    else if (side == Field::O)
        std::cout << 'O' << " wins!\n";
}

void BoardView::print_draw() {
    std::cout << "Draw.\n";
}

void BoardView::print_error() {
    std::cout << "Bad move!\n";
}