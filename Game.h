#pragma once
#include <Board.h>
#include <Player.h>
#include <Ai.h>

class Game {
	
private:
	Board board;
	Player player;
	Ai bot;
	bool player_turn;
public:
	Game();
	void intro();
	void play();
};