#ifndef LEVEL_ENGINE_HPP
#define LEVEL_ENGINE_HPP

#include <mutex>
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

Level::Level()
{
	player = new Player(0, 0, 0);
}
void Level::levelLoop(unsigned char *direction)
{
	float *local_xyP;
	while(!isExit)
	{		
		#ifdef DEBUG
		std::cout << unsigned(input) << std::flush << "\b\b\b   \b\b\b";
		#endif
		inputMutex.lock();
		local_xyP = player->move(*direction);//change xyP later to array of sprite's coords
		inputMutex.unlock();
		aMutex.lock();
		xyP = local_xyP;
//		std::cout << xyP[0] << ' ' << xyP[1] << std::endl;
		aMutex.unlock();
	}
}

#endif
