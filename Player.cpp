#include "Player.h"
#include <iostream>
using namespace std;

Player::Player(){
	
}
//process user moves
void Player::move(Board &board){
	while(1){
		cout << ":: Enter row and column : ";
		int i,j;
		cin >> i >> j;
		if(board.can_move(i,j)){
			board.move(i,j,getSymbol());
			return;
		}
		cout << ":: -Invalid Spot! try again\n";
	}
}

void Player::setSymbol(char x){
	symbol = x;
}

char Player::getSymbol(){
	return symbol;
}