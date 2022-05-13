#include <playerEngine.hpp>
#include <globals.hpp>

Player::Player(unsigned char lives1, unsigned char bombs1, unsigned char power1)
{
    point = 0;
    graze = 0;
    lives = lives1;
    bombs = bombs1;
    power = power1;
    xy.x=0;xy.y=0;
    xyP = xy;
}

gameCoord Player::move()
{
    if(! (input & FOCUSED) )
    {
        xy.x += speed*((RIGHT&input)>>2)*(gameTime);
        xy.x -= speed*((LEFT&input)>>3)*(gameTime);
        xy.y += speed*((DOWN&input)>>1)*(gameTime);
        xy.y -= speed*(UP&input)*(gameTime);
    }
    else
    {
        xy.x += focusSpeed*((RIGHT&input)>>2)*(gameTime);
        xy.x -= focusSpeed*((LEFT&input)>>3)*(gameTime);
        xy.y += focusSpeed*((DOWN&input)>>1)*(gameTime);
        xy.y -= focusSpeed*(UP&input)*(gameTime);
    }
    return xy;
}
