#include "Game.h"
#include <iostream>

using namespace std;
//setup game
void Game::intro(){
	board.clear();
	cout << ":: Welcome to Tic Tac Toe ::" << endl;
	cout << ":: Do you want to be X ? (y/n): ";
	char ch;
	cin >> ch;
	if (ch == 'y' || ch == 'Y'){
		player.setSymbol('X');
		bot.setSymbol('O');
		bot.setOpSymbol('X');
	}
	else{
		player.setSymbol('O');
		bot.setSymbol('X');
		bot.setOpSymbol('O');
	}
	cout << ":: Do you want to go first? (y/n): ";
	cin >> ch;
	if (ch == 'y' || ch == 'Y'){
		player_turn = true;
	}
	else{
		player_turn = false;
	}
}

Game::Game(){
}
//Game Loop
void Game::play(){
	board.show();
	while(true){
		if (player_turn){
			player.move(board);
			if(board.check_win(player.getSymbol())){
				cout << ":: You Won !! " << endl;
				break;
			}
			player_turn = false;
		}
		else{
			bot.move(board);
			if(board.check_win(bot.getSymbol())){
				cout << ":: You Lost !! " << endl;
				break;
			}
			player_turn = true;
		}
		if(board.check_tie()){
			cout << ":: Tie !!" << endl;
			break;
		}
		board.show();
	}
	cout << ":: Final Board" << endl;
	board.show();
}