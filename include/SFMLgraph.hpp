#ifndef SFML_GRAPH_HPP
#define SFML_GRAPH_HPP

#include "globals.hpp"

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

bool createWindow();

void setTextures(sf::Texture* textures[]);

sf::Sprite* setSprites(sf::Texture* texture, int k1);

//function for displaying debug information
void debugInfo();

void windowDisplay(sf::Sprite* sprites[]/* *coordNeededToDisplay*/);

unsigned char getKeys();

void windowLoop(sf::Sprite* sprites[]/* void (Game::*exit)() *coordNeededToDisplay*/);

#endif
