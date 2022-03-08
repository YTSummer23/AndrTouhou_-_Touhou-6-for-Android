#include <mutex>
std::mutex aMutex;
std::mutex inputMutex;

#include <globals.hpp>

#ifdef _WIN32
#include "include/SFMLgraph.hpp"
#endif
#ifdef __linux__
#include "include/SFMLgraph.hpp"
#endif

#include <iostream>
#include "include/gameEngine.hpp"
#include <thread>


void theGame()
{
	Game game;
	game.gameLoop();
}

int main()
{
	using std::cout;
	using std::cin;
	using std::thread;
	using std::endl;
//--------------------------------------------
	thread threadGame(theGame);
//--------------------------------------------
	//textures and sprites initialization
	sf::Texture* textures[AofT];//[0] - reimu texture,
	for(int k = 0; k < (AofT-1); ++k)//this is here to make NULL works
	{
		textures[k] = (sf::Texture*)1;
	}
	textures[AofT - 1] = NULL;//see setTextures()'s commentaries for this s**t
	setTextures(textures);
	sf::Sprite *sprites[AofT];
	for(int k = 0; k < (AofT-1); ++k)
	{
		sprites[k] = (sf::Sprite*)1;
	}
	sprites[AofT - 1] = NULL;//here we go again
	for(int k=0; sprites[k]!= NULL; ++k)
	{
		#ifdef DEBUG
		cout << "First main()'s for() k: " << k << endl;
		cout << "setSprites(textures[k], k): " << setSprites(textures[k], k) << endl;
		#endif
		sprites[k] = setSprites(textures[k], k);
	}
	sprites[0][0].setTextureRect(sf::IntRect(0, 0, 32, 48));//sprites[0][0] - player
//------------------------------------------------------
	//sf:RenderWindow window;
	//the game itself.
	if(createWindow())
	{
		#ifdef DEBUG
		cout << "Creating a window.\n";
		#endif
		threadGame.detach();
		windowLoop(sprites);
	}
	else
	{
		cout << "The window hasn't been created. ";
		cout << "The program is closing. Please press \'Enter\' to exit";
		return 1;
	}
	#ifdef DEBUG
	cout << "The program is closing. Please press \'Enter\' to exit";
	cin.get();
	#endif
    return 0;
}
