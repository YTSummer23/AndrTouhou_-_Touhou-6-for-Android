#include <globals.hpp>

#include <mutex>

#include <SFML/System.hpp>

#include <levelEngine.hpp>

Level::Level()
{
    player = new Player(0, 0, 0);
}
void Level::levelLoop(unsigned char *direction)
{
    sf::Clock clock;
    while(!isExit)
    {
        *gameTime = (clock.restart()).asSeconds();
        inputMutex.lock();
        xyP = player->move(*direction);//change xyP later to array of sprite's coords
        inputMutex.unlock();
    }
}

