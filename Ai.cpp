#include "Ai.h"
#include <iostream>

Ai::Ai(){
	
}

void Ai::setOpSymbol(char x){
	oppSymbol = x;
}
//Minimax function which backtracks and evalutes a given move
int Ai::minimax(Board &board, int depth, bool isMax){
	if (board.check_win(getSymbol()))
		return 10;
	else if(board.check_win(oppSymbol))
		return -10;
	else if(board.check_tie())
		return 0;
	if(isMax){
		int best = -1000;
		for(int i = 1; i < 4; i++){
			for(int j = 1; j < 4; j++){
				if(board.can_move(i,j)){
					board.move(i, j, getSymbol());
					best = std::max(best, minimax(board, depth+1, !isMax) - depth);
					board.reset_move(i, j);
				}
			}
		}
		return best;
	}else{
		int best = 1000;
		for(int i = 1; i < 4; i++){
			for(int j = 1; j < 4; j++){
				if(board.can_move(i,j)){
					board.move(i, j, oppSymbol);
					best = std::min(best, minimax(board, depth+1, !isMax) + depth);
					board.reset_move(i, j);
				}
			}
		}
		return best;
	}
	
}
//Try all availible spots and choose the best one
void Ai::move(Board &board){
	int bestVal = -10000;
	int si = -1, sj = -1;
	for(int i = 1; i < 4; i++){
		for(int j = 1; j < 4; j++){
			if(board.can_move(i,j)){
				board.move(i, j, getSymbol());
				int val = minimax(board, 0, false);
				board.reset_move(i, j);
				if(val > bestVal){
					si = i;
					sj = j;
					bestVal = val;
				}
			}
		}
	}
	board.move(si, sj, getSymbol());
}

void Ai::setSymbol(char x){
	symbol = x;
}

char Ai::getSymbol(){
	return symbol;
}