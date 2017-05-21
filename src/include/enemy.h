#ifndef ENEMY
#define ENEMY

#include "gameObj.h"
#include "map.h"

class Enemy :public GameObj{
public:
	Enemy(std::string Name, float X, float Y, int W, int H, int hel);
 
    sf::Sprite getSprite();
    virtual void update(float time) = 0;
    
};

#endif