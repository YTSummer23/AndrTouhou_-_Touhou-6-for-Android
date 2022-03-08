#include <playerEngine.hpp>
#include <globals.hpp>

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

float* Player::move(unsigned char &direction)
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
