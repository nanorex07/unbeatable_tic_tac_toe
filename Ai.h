#pragma once
#include <Board.h>

class Ai{
private:
	char symbol;
	char oppSymbol;
public:
	Ai();
	void setSymbol(char);
	char getSymbol();
	void move(Board&);
	void setOpSymbol(char);
	int minimax(Board&, int, bool);
};