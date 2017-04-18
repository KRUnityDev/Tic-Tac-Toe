#pragma once
#include <array>
#include "Field.h"
class Board
{
public:
	Board();
	~Board();

	//Board size
	const int SizeX = 3, SizeY = 3;
	//Changing state of one field on board
	bool ChangeFieldState(int x, int y, Field::State state);

	Field GetField(int x, int y);
private:
	//Two-dimensional array containing fields
	std::array<std::array<Field, 3>, 3> board;
};

