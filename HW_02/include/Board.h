class Board {
public:                                  
    /** Проверить ход на корректность, если бы он был следующим. */
    bool canMove(int x, int y, XXX player);

    /** Сделать ход. UB, если он некорректен. */
    void move(int x, int y, XXX player);

    /** Состояние игры: игра идёт, игра кончилась с одним из результатов: ничья, победа одной из сторон. */
    YYY getState();
    
    // Можно добавлять методы при необходимости.
private:
	char **field = new char;
};

class YYY
{
public:
	
};

class player {
public:
	char return_side();
private:
	int side;
};

class StdioBoardView {
public:
    StdioBoardView(Board &board);

    /** Основной цикл игры, от начала до конца. */
    void runGame();

    // Можно добавлять методы при необходимости.
};