#pragma once
#include <Board.h>
class Player {
	
private:
	char symbol;
public:
	Player();
	void setSymbol(char);
	char getSymbol();
	void move(Board&);
};