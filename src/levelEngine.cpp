#include <globals.hpp>

#include <mutex>

#include <SFML/System.hpp>

#include <levelEngine.hpp>

struct coord {
    float x;
    float y;
} returned_xy;

Level::Level()
{
    player = new Player(0, 0, 0);
}
void Level::levelLoop()
{
    sf::Clock clock;
    while(!isExit)
    {
	//mainLoopS = true;
        gameTime = (clock.restart()).asSeconds();
        //inputMutex.lock();
        xyP = player->move();//change xyP later to array of sprite's coords
        //inputMutex.unlock();
	//mainLoopS= false;
	//while(sfmlLoopS){}
	//mainLoopS = false;
    }
    //mainLoopS = false;
}

