#ifndef BULLET_ENGINE_HPP
#define BULLET_ENGINE_HPP

class Bullet
{
private:
	float x, y;
	int radius;
};

class LaserBullet
{
private:
	float x, y;
	float k, b, rk, rb, lk, lb;//r - right, l - left. r will be probably for user side.
	
};

#endif