#include "Board.h"
#include <iostream>

using namespace std;

Board::Board(){
	clear();
}
//reset a given spot on board 
void Board::reset_move(int i, int j){
	board[i-1][j-1] = '-';
}

//clear the board
void Board::clear(){
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			board[i][j] = '-';
		}
	}
}

//display board
void Board::show(){
	cout << "  1 2 3 " << endl;
	for(int i = 0; i < 3; i++){
		cout << i+1 <<" ";
		for(int j = 0; j < 3; j++){
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
}

//Check if a particular spot is empty 
bool Board::can_move(int i, int j){
	return board[i-1][j-1] == '-';
}

//make a move on the board
void Board::move(int i, int j, char symbol){
	board[i-1][j-1] = symbol;
}

//check for a tie
bool Board::check_tie(){
	for(int i = 0; i < 3; i++)
		for(int j = 0; j < 3; j++)
			if(board[i][j]=='-')
				return false;
	return true;
}

//check for win
bool Board::check_win(char symbol){
	for(int i = 0; i < 3; i++)
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] == symbol)
			return true;
	for(int j = 0; j < 3; j++)
		if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[1][j] == symbol)
			return true;
	if(board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[2][2] == symbol)
		return true;
	if(board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] == symbol)
		return true;
	return false;
}