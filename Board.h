#pragma once
#include <array>
#include "Field.h"
class Board
{
public:
	Board();
	~Board();
	const int SizeX = 3, SizeY = 3;
	bool ChangeFieldState(int x, int y, Field::State state);
	Field GetField(int x, int y);
private:
	std::array<std::array<Field, 3>, 3> board;
};

