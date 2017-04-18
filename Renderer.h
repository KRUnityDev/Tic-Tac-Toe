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
	//Show board and other stuff in console
	void Render(Board& board);
	//Show GameOver message and other stuff in console
	void RenderGameOverBoard(std::string message);
private:
	//Clear console
	void clearConsole();
	//Show title board in console
	void renderTitleBoard();
	std::string titleBoard = "------      Tic Tac Toe     ------ \n------ made by. Kamil Roszak ------ \n\n";
};

