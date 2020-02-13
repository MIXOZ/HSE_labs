#include <sstream>
#include <iostream>
#include <Board.h>
#include <vector>


/**------------------Board-------------------*/

/** Проверить ход на корректность, если бы он был следующим. */
bool Board::can_move(int x, int y) {
    return (x < MAX_VALUE && y < MAX_VALUE && x >= MIN_VALUE && y >= MIN_VALUE && field[x][y] == Field::NONE);   
}

Field Board::get_cell(int x, int y) {
    return field[x][y];
}


/** Сделать ход. UB, если он некорректен. */
void Board::move(int x, int y) {
    field[x][y] = return_side_field();
    empty_cells--;
    change_side();
}

/** Проверка на окончание игры. */

State Board::is_victory(int x, int y, Field side) {
    int delta_x_arr[WIN_VALUE] = {-1, 0, 1, 1};
    int delta_y_arr[WIN_VALUE] = {1, 1, 0, 1};
    for (int itr = MIN_VALUE; itr < WIN_VALUE; ++itr) {
        int i = x;
        int j = y;
        int k = EXIT_VALUE;
        while (i >= MIN_VALUE && j >= MIN_VALUE && i < MAX_VALUE && j < MAX_VALUE)
            if (field[i][j] == side) {k++; i -= delta_x_arr[itr]; j -= delta_y_arr[itr];}
            else break;
        i = x;
        j = y;
        while (i < MAX_VALUE && j < MAX_VALUE && i >= MIN_VALUE && j >= MIN_VALUE)
            if (field[i][j] == side) {k++; i += delta_x_arr[itr]; j += delta_y_arr[itr];}
            else break;
        if (k > WIN_VALUE) return WIN;
    }
    return CONTINUE;
}

/** Состояние игры: игра идёт, игра кончилась с одним из результатов: ничья, победа одной из сторон. */
State Board::get_state(int x, int y){
    if (is_victory(x, y, return_last_side_field()) == CONTINUE)
        if (empty_cells == MIN_VALUE) return DRAW;
    return is_victory(x, y, return_last_side_field());
}

void Board::change_side() {
    if (side == Field::O) side = Field::X;
    else side = Field::O;
}


Field Board::return_side_field(){
    return side;
}


Field Board::return_last_side_field(){
    if (side == Field::O) return Field::X;
    else return Field::O;
}

Player Board::return_side_player(){
    if (side == Field::O) return Player::O;
    else return Player::X;
}

Board::Board() {
    field.resize(MAX_VALUE);
    for (size_t i = MIN_VALUE; i < MAX_VALUE; ++i) {
        field[i].resize(MAX_VALUE);
        for (size_t j = MIN_VALUE; j < MAX_VALUE; ++j ) 
            field[i][j] = Field::NONE;
    }
}


/**---------------StdioBoardView----------------*/

 bool StdioBoardView::get_coor(int &x, int &y) {
    std::string buf;
    std::getline (std::cin, buf);
    std::stringstream buffer(buf);
    x = ERROR_VALUE;
    y = ERROR_VALUE;
    buffer >> x;
    if (buffer.fail()) return false;
    buffer >> y;
    if (buffer.fail()) return false;
    char symbol = ' ';
    while (symbol == ' ') {
        if (buffer.eof()) return true;
        buffer >> symbol;
    }
    return false;
 }

/** Основной цикл игры, от начала до конца. */
void StdioBoardView::run_game() {
    int x = ERROR_VALUE;
    int y = ERROR_VALUE;
    if (silent)
        view.print_field(&engine);
    view.print_game_line(engine.return_side_player());
    while (!get_coor(x, y)) view.print_error();
    while (x != EXIT_VALUE && y != EXIT_VALUE) {
        input_processing(x, y);
        State current_state = engine.get_state(x, y);
        if (current_state == CONTINUE) view.print_game_line(engine.return_side_player());
        else {
            if (!silent) view.print_field(&engine);
            if (current_state == WIN) {
                view.print_win(engine.return_last_side_field());
                return;
            } else if (current_state == DRAW) {
                view.print_draw();
                return;
            }
        }
        while (!get_coor(x, y)) view.print_error();
    }
}

// Можно добавлять методы при необходимости.

void StdioBoardView::input_processing(int x, int y) {
    if (engine.can_move(x, y)) { 
        engine.move(x, y); 
        if (silent)
            view.print_field(&engine);
    } else {
        view.print_error();
    }
}

void BoardView::print_field(Board *engine) {
    std::cout << "\n";
    for (size_t i = MIN_VALUE; i < MAX_VALUE; ++i) {
        for (size_t j = MIN_VALUE; j < MAX_VALUE; ++j ) {
            std::cout << engine->get_cell(i, j);
        }
        std::cout << "\n";
    }
}

void BoardView::print_game_line(Player side) {
    std::cout << side << " move: \n";
}

void BoardView::print_win(Field side) {
    std::cout << side << " wins!\n";
}

void BoardView::print_draw() {
    std::cout << "Draw.\n";
}

void BoardView::print_error() {
    std::cout << "Bad move!\n";
}

std::ostream& operator <<(std::ostream &out, Field const side) {
    if (side == Field::X)
        std::cout << 'X';
    else if (side == Field::O)
        std::cout << 'O';
    else if (side == Field::NONE)
        std::cout << '.';
    return out;
}

std::ostream& operator <<(std::ostream &out, Player const side) {
    if (side == Player::X)
        std::cout << 'X';
    else if (side == Player::O)
        std::cout << 'O';
    return out;
}