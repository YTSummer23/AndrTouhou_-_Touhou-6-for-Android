#ifndef ENEMY_ENGINE_HPP
#define ENEMY_ENGINE_HPP

class Enemy
{
public:
	Enemy();
	float* move();//a function that change x and y...
protected:
	float x, y;
};

class Boss : public/*or private*/ Enemy
{

};

#endif