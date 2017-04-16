#include "Game.h"
#include <iostream>
int main()
{
	Game game;
	while(true)
	{
		if (!game.Loop()) break;
	}
	std::cin.get();
	return 0;
}