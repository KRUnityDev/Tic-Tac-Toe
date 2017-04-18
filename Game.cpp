#include "Game.h"



Game::Game()
{
	firstPlayer.type = Field::State::Circle;
	secondPlayer.type = Field::State::Cross;
	currentRound = Round::firstPlayerRound;
}


Game::~Game()
{
}

bool Game::Loop()
{
	renderer.Render(gameBoard);
	Field::State currentPlayerType;
	switch(currentRound)
	{
	case Round::firstPlayerRound:
		std::cout << "First Player "<<"[0] ";
		currentPlayerType = firstPlayer.type;
		break;
	case Round::secondPlayerRound:
		std::cout << "Second Player " << "[X] ";
		currentPlayerType = secondPlayer.type;
		break;
	}
	while(true)
	{
		std::cout << "Round | Where you wanna place your marker? [x y]: ";
		int newMarkerX, newMarkerY;
		std::cin >> newMarkerX >> newMarkerY;
		if(newMarkerX<gameBoard.SizeX || newMarkerY<gameBoard.SizeY || newMarkerX>0 || newMarkerY>0)
		{
			if (gameBoard.ChangeFieldState(newMarkerX, newMarkerY, currentPlayerType))
			{
				break;
			}
			else
			{
				std::cout << "\nYou wanted place the marker on occupied field. Click [Enter] and try again";
				std::cin.get();
			}
		}
		else
		{
			std::cout << "\nYou wanted place the marker on not available field. Please place marker on board. Click [Enter] and try again";
			std::cin.get();
		}
		
		
	}

	if (findWinner())
	{
		gameEnd();
		return false;
	}

	switch (currentRound)
	{
	case Round::firstPlayerRound:
		currentRound = secondPlayerRound;
		break;
	case Round::secondPlayerRound:
		currentRound = firstPlayerRound;
		break;
	}
	return true;
	
}

bool Game::findWinner()
{
	//Checking rows
	if (gameBoard.GetField(0, 0).GetState() == gameBoard.GetField(1, 0).GetState() == gameBoard.GetField(2, 0).GetState()
		&& gameBoard.GetField(0,0).GetState() != Field::State::Empty && gameBoard.GetField(1, 0).GetState() != Field::State::Empty && gameBoard.GetField(2, 0).GetState() != Field::State::Empty)
		return true;
	if (gameBoard.GetField(0, 1).GetState() == gameBoard.GetField(1, 1).GetState() == gameBoard.GetField(2, 1).GetState()
		&& gameBoard.GetField(0, 1).GetState() != Field::State::Empty && gameBoard.GetField(1, 1).GetState() != Field::State::Empty && gameBoard.GetField(2, 1).GetState() != Field::State::Empty)
		return true;
	if (gameBoard.GetField(0, 2).GetState() == gameBoard.GetField(1, 2).GetState() == gameBoard.GetField(2, 2).GetState()
		&& gameBoard.GetField(0, 2).GetState() != Field::State::Empty && gameBoard.GetField(1, 2).GetState() != Field::State::Empty && gameBoard.GetField(2, 2).GetState() != Field::State::Empty)
		return true;

	//Checking colums

	if (gameBoard.GetField(0, 0).GetState() == gameBoard.GetField(0, 1).GetState() == gameBoard.GetField(0, 2).GetState()
		&& gameBoard.GetField(0, 0).GetState() != Field::State::Empty && gameBoard.GetField(0, 1).GetState() != Field::State::Empty && gameBoard.GetField(0, 2).GetState() != Field::State::Empty)
		return true;
	if (gameBoard.GetField(1, 0).GetState() == gameBoard.GetField(1, 1).GetState() == gameBoard.GetField(1, 2).GetState()
		&& gameBoard.GetField(1, 0).GetState() != Field::State::Empty && gameBoard.GetField(1, 1).GetState() != Field::State::Empty && gameBoard.GetField(1, 2).GetState() != Field::State::Empty)
		return true;
	if (gameBoard.GetField(2, 0).GetState() == gameBoard.GetField(2, 1).GetState() == gameBoard.GetField(2, 2).GetState()
		&& gameBoard.GetField(2, 0).GetState() != Field::State::Empty && gameBoard.GetField(2, 1).GetState() != Field::State::Empty && gameBoard.GetField(2, 2).GetState() != Field::State::Empty)
		return true;

	//Checking intersections

	if (gameBoard.GetField(0, 0).GetState() == gameBoard.GetField(1, 1).GetState() == gameBoard.GetField(2, 2).GetState()
		&& gameBoard.GetField(0, 0).GetState() != Field::State::Empty && gameBoard.GetField(1, 1).GetState() != Field::State::Empty && gameBoard.GetField(2, 2).GetState() != Field::State::Empty)
		return true;
	if (gameBoard.GetField(2, 0).GetState() == gameBoard.GetField(1, 1).GetState() == gameBoard.GetField(0, 2).GetState()
		&& gameBoard.GetField(2, 0).GetState() != Field::State::Empty && gameBoard.GetField(1, 1).GetState() != Field::State::Empty && gameBoard.GetField(0, 2).GetState() != Field::State::Empty)
		return true;

	//Checking if is empty field on board
	for(int y = 0; y<gameBoard.SizeY; y++)
	{
		for(int x = 0; x<gameBoard.SizeX; x++)
		{
			if (gameBoard.GetField(x, y).GetState() == Field::State::Empty)
			{
				return false;
			}
		}
	}
	draw = true;
	return true;
}

void Game::gameEnd()
{
	std::string message = "GAME OVER | ";
	if(draw)
	{
		switch (currentRound)
		{
		case Round::firstPlayerRound:
			message += "First Player Wins!";
			break;
		case Round::secondPlayerRound:
			message += "Second Player Wins!";
			break;
		}
	}
	else
	{
		message += "There is a draw!";
	}
	renderer.RenderGameOverBoard(message);
	std::cin.get();
	//exit(0);
}
