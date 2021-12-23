#ifndef GAME_ENGINE_HPP
#define GAME_ENGINE_HPP

/*#ifdef _WIN32
#include "SFMLgraph.hpp"
#endif
#ifdef __linux__
#include "SFMLgraph.hpp"
#endif*/

/*the game has two stages: menu and levels.
Menu is menu... And score screen beetwen levels.
Levels are levels...*/
#include "levelEngine.hpp"
#include "menu.hpp"
#include <iostream>

class Game
{
public:
	bool start();//Maybe I will change bool to int which will be meaning a type of error.
	bool saveScore();//I think it don't need to be explained
	void exit();
	void gameLoop();
private:
	//unsigned char input;
};

void Game::gameLoop()
{
	Level level;
	while(!isExit)
	{
		level.levelLoop(&input);
	}
	//saveGame();
	isExit=false;
}

#endif