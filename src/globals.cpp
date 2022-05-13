#include <globals.hpp>

bool isExit = false;
gameCoord xyP;
float gameTime = 0;
unsigned char input = 0;
std::mutex inputMutex;
bool mainLoopS, sfmlLoopS;
