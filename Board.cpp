#include "Board.h"



Board::Board()
{
}


Board::~Board()
{
}

bool Board::ChangeFieldState(int x, int y, Field::State state)
{
	if (Board::board[x][y].GetState() != Field::State::Empty) return false;
	Board::board[x][y].SetState(state);
	return true;
}

Field Board::GetField(int x, int y)
{
	return Board::board[x][y];
}
