#include <globals.hpp>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include <mutex>
#include <string>
#include <sstream>

#include <SFMLgraph.hpp>

sf::RenderWindow window;
sf::Font font;
sf::Text text, textInfo;

std::ostringstream ss;

bool createWindow()
{
    window.create(sf::VideoMode(800, 600), "Touhou 6");
    window.setVerticalSyncEnabled(1);
    font.loadFromFile("fonts/Miratrix.ttf");
    text.setFont(font);textInfo.setFont(font);
    textInfo.setPosition(500, 0);
    text.setString("input:\nxyP:\ngameTime:\n");
    return window.isOpen();
}


void setTextures(sf::Texture* textures[])
{
    for(int k = 0; textures[k] != NULL; ++k)//I don't know what i made here NULL for  \/(0-0)\/
    {
        textures[k] = new sf::Texture;
        (textures[k])->loadFromFile(pathsOfT[k]);
    }
}

sf::Sprite* setSprites(sf::Texture* texture, int k1)
{
    sf::Sprite* sprite = new sf::Sprite [AofS[k1]];
    for(int k=0; k < (AofS[k1]-1); ++k)
    {
        sprite[k].setTexture((*texture));
    }
    //sprite[AofS - 1] = NULL;
    return sprite;
}

void debugInfo()
{
    ss.str("");
    ss << unsigned(input) << "\n" << *xyP << "\t" << *(xyP +1) << "\n" << *gameTime;
    textInfo.setString(ss.str());
    window.draw(text); window.draw(textInfo);
}


void windowDisplay(sf::Sprite* sprites[]/* *coordNeededToDisplay*/)
{
        window.clear(sf::Color::Blue);
    /*for(int k = 0; sprites[k] != NULL; ++k)
    {
        for(int j = 0; sprites[k][j] != NULL; ++j)
        {
            window.draw(sprites[k][j]);
        }
    }*/
    debugInfo();
    window.draw(sprites[0][0]);
    window.display();
}


unsigned char getKeys()
{
    unsigned char input = 0;
    input += sf::Keyboard::isKeyPressed(sf::Keyboard::Up);
    input += (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) << 1);
    input += (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) << 2);
    input += (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) << 3);
    input += (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) << 4);
    input += (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl) << 5);
    input += (sf::Keyboard::isKeyPressed(sf::Keyboard::X) << 6);
    input += (sf::Keyboard::isKeyPressed(sf::Keyboard::Z) << 7);
    return input;
}


void windowLoop(sf::Sprite* sprites[]/* void (Game::*exit)() *coordNeededToDisplay*/)
{
    //sf::Clock clock;
    while (window.isOpen())
    {
        //*gameTime = (clock.restart()).asSeconds();
        sf::Event event;
        while (window.pollEvent(event))
        {
                if (event.type == sf::Event::Closed)
            {
                isExit = true;
                while(isExit)
                { }
                window.close();
            }
        }
        inputMutex.lock();
        input = getKeys();
        inputMutex.unlock();
        sprites[0][0].setPosition(xyP[0], xyP[1]);
        windowDisplay(sprites);
    }
}

