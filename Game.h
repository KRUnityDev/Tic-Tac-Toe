#pragma once
#include "Board.h"
#include "Renderer.h"
#include "Player.h";
class Game
{
public:
	Game();
	~Game();
	//Game Board
	Board gameBoard;
	//Renderer
	Renderer renderer;
	//Players
	Player firstPlayer, secondPlayer;
	//Game Loop
	bool Loop();
private:
	bool draw = false;
	//Method checking if any player wins
	bool findWinner();
	//Method get called when game is over
	void gameEnd();
	enum Round
	{
		firstPlayerRound,
		secondPlayerRound
	};
	//Means round of current player
	Round currentRound;
};

