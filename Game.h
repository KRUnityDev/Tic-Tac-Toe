#pragma once
#include "Board.h"
#include "Renderer.h"
#include "Player.h";
class Game
{
public:
	Game();
	~Game();
	Board gameBoard;
	Renderer renderer;
	Player firstPlayer, secondPlayer;
	bool Loop();
private:
	bool findWinner();
	void gameEnd();
	enum Round
	{
		firstPlayerRound,
		secondPlayerRound
	};
	Round currentRound;
};

