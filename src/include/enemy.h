#ifndef ENEMY
#define ENEMY

#include "gameObj.h"
#include "map.h"

class Enemy :public GameObj{
    int damage;
    
public:
	Enemy(std::string Name, float X, float Y, int W, int H, int hel, int dam);
 
    sf::Sprite getSprite();
    int getDamage();
    virtual void update(float time, Map map) = 0;
    void convertVectors();
};

#endif