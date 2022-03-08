#ifndef LEVEL_ENGINE_HPP
#define LEVEL_ENGINE_HPP

#include "bulletEngine.hpp"
#include "enemyEngine.hpp"
#include "playerEngine.hpp"

class Level
{
public:
	Level();
	void levelLoop(unsigned char*);// like game loop, but level loop.
private:
	unsigned char numberOfLevel;
	Player* player = NULL;
};

#endif
