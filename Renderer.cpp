#include "Renderer.h"



Renderer::Renderer()
{
}


Renderer::~Renderer()
{
}

void Renderer::Render(Board& board)
{
	clearConsole();
	renderTitleBoard();
	std::cout << std::endl;
	std::cout << "  ";
	for (int x = 0; x<board.SizeX; x++)
	{
		std::cout << x << " ";
	}
	std::cout << std::endl;

	for(int y = 0; y<board.SizeY; y++)
	{
		std::cout << y;
		std::cout << "|";
		for (int x = 0; x<board.SizeX; x++)
		{
			std::cout << board.GetField(x, y) << "|";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void Renderer::renderTitleBoard()
{
	std::cout << titleBoard;
}

void Renderer::clearConsole()
{
	system("cls");
}
