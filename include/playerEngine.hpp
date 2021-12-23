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

Player::Player(unsigned char lives1, unsigned char bombs1, unsigned char power1)
{
	point = 0;
	graze = 0;
	lives = lives1;
	bombs = bombs1;
	power = power1;
	xy[0]=0;xy[1]=0;
	xyP = xy;
}

float* Player::move(unsigned char &direction)//direction: 0b00001 - up, 0b00010 - down, 0b00100 - right, 0b01000 - left, 0b10000 - focused
{
	if(! (input & FOCUSED) ) 
	{
		xy[0] += speed*((RIGHT&input)>>2)*(*gameTime);
		xy[0] -= speed*((LEFT&input)>>3)*(*gameTime);
		xy[1] += speed*((DOWN&input)>>1)*(*gameTime);
		xy[1] -= speed*(UP&input)*(*gameTime);
	} 
	else
	{
		xy[0] += focusSpeed*((RIGHT&input)>>2)*(*gameTime);
		xy[0] -= focusSpeed*((LEFT&input)>>3)*(*gameTime);
		xy[1] += focusSpeed*((DOWN&input)>>1)*(*gameTime);
		xy[1] -= focusSpeed*(UP&input)*(*gameTime);
	}
	return xy;
}

#endif
