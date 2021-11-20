#pragma once

class Board{
private:
	char board[3][3];
public:
	Board();
	void clear();
	void show();
	bool can_move(int,int);
	void move(int,int,char);
	bool check_win(char);
	bool check_tie();
	void reset_move(int, int);
};