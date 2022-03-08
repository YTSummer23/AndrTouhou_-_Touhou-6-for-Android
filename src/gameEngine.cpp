#include <gameEngine.hpp>
#include <globals.hpp>

#include <levelEngine.hpp>
#include <menu.hpp>

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

