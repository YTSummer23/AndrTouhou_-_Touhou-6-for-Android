#ifndef GAME_ENGINE_HPP
#define GAME_ENGINE_HPP

#include <globals.hpp>

/*#ifdef _WIN32
#include "SFMLgraph.hpp"
#endif
#ifdef __linux__
#include "SFMLgraph.hpp"
#endif*/

/*the game has two stages: menu and levels.
Menu is menu... And score screen beetwen levels.
Levels are levels... menu's header and level's one is included in cpp file*/

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

#endif
