#pragma once
#include "Board.h"
#include "Field.h"
#include <iostream>
#include <string>
class Renderer
{
public:
	Renderer();
	~Renderer();
	void Render(Board& board);
private:
	void clearConsole();
	void renderTitleBoard();
	std::string titleBoard = "------      Tic Tac Toe     ------ \n------ made by. Kamil Roszak ------ \n\n";
};

