/** Проверить ход на корректность, если бы он был следующим. */
bool canMove(int x, int y, XXX player) {
    return (field[x][y] == '.' && x < 10 && y < 10 && x >= 0 && y >= 0);   
}

/** Сделать ход. UB, если он некорректен. */
void move(int x, int y, XXX player) {
    field[x][y] = XXX.return_side();
    check_end_game(int x, int y, XXX player);
}

bool check_end_game(int x, int y, XXX player) {
    int i = x;
    int j = y;
    int k = -1;
    while (i >= 0)
        if (field[i][y] == XXX.return_side()) {k++; i--}
        else break;
    while (i < 10)
        if (field[i][y] == XXX.return_side()) {k++; i++}
        else break;
    if k >= 5 return 1;
    k = -1;
    while (j >= 0)
        if (field[x][j] == XXX.return_side()) {k++; j--}
        else break;
    while (j < 10)
        if (field[x][j] == XXX.return_side()) {k++; j++}
        else break;
    if k >= 5 return 1;
    return 0;
}

char return_size(){
    if (side == 1) return 'X';
    else return 'O';
}

/** Состояние игры: игра идёт, игра кончилась с одним из результатов: ничья, победа одной из сторон. */
bool getState(){
    if (end_game()) return 0;
    return 1;
}
    
// Можно добавлять методы при необходимости.

int end_game() {
    if (empty()) return 1;
}

StdioBoardView(Board &board);

/** Основной цикл игры, от начала до конца. */
void runGame(){
    print_field();
    player.print_game_line();
    cin >> x >> y;
    while (x != -1 && y != -1) {
        if (canMove(player)) print_field();
        else print_error();
        if (getState()) print_game_line();
        else {
            cout << game_result();
            return 0;
        }
        change_side();
        cin >> x >> y;
    }

}

// Можно добавлять методы при необходимости.
