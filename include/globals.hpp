#ifndef GLOBALS_HPP
#define GLOBALS_HPP

#include <string>
#include <mutex>

//global variables, they are neede for thread chatting
extern bool isExit;
extern unsigned char input;
extern bool mainLoopS, sfmlLoopS;//loop semaphors are needed for synchronization SFML loop and game loop
extern struct gameCoord {
    float x;
    float y;
} xyP;
extern float gameTime;
extern std::mutex inputMutex;
//const vars
const int AofT = 2;//AofT - amount of textures. The last element should be always null
const int AofS[(AofT - 1)] = { 24 };//AofS - amount of sprites
const std::string pathsOfT[(AofT - 1)] = { "data/player00_rgba.png" };

#endif
