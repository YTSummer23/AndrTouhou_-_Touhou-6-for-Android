#ifndef PLAYER_ENGINE_HPP
#define PLAYER_ENGINE_HPP

const unsigned char UP = 0x1, DOWN = 0x2,  RIGHT = 0x4, LEFT = 0x8, FOCUSED = 0x10;

class Player
{
public:
	Player(unsigned char, unsigned char, unsigned char);
	float* move(unsigned char &);
	float* getCoord();
private:
	float xy[2];//xy[0] - x, xy[1] - y.
	int radius;//radius of player's hitbox
	unsigned char livingMode;//0 - player doesn't exists, 1 -player is living, 2 -player is dead, 3 - player is invincible.
	unsigned char lives, bombs, power;
	unsigned char gotHits, continues, usedContinues;
	int point, graze;
	bool focused;
	const float speed = 0.005f, focusSpeed = 0.0025f;//temporary variables
};

#endif
