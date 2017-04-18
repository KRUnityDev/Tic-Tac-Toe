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

void Renderer::RenderGameOverBoard(std::string message)
{
	std::cout << message;
}

void Renderer::clearConsole()
{
#if defined(_WIN32)
	system("cls");
#elif defined(_WIN64)
	system("cls");
#elif defined(__linux__)
	system("clear");
#endif
}
