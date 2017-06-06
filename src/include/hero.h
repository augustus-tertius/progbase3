#ifndef HERO
#define HERO

#include <iostream>
#include "gameObj.h"
#include "map.h"
#include <SFML/Graphics.hpp>


class heroTextures {
public:
    sf::Texture stand;
    sf::Texture walk_1;
    sf::Texture walk_2;
    sf::Texture jump;

    heroTextures();
    heroTextures(std::string filePath);
};

class Hero : public GameObj {

    sf::Image image;
    sf::Texture texture;
    sf::Sprite sprite;

    enum {walk, jump, stand} state;
    float curFrame;
    float healTimer;
    float shieldTimer;
    heroTextures ht;
    bool shield;


    public:
        // Hero(); mb add one later ?
        Hero(float X, float Y, int W, int H, std::string Name, std::string filePath);
        void control (float timePassed);
        void update(float timePassed, Map &map);

        void updateHealth(float timePassed);
        void updateShield(float timePassed);

        void animation(float timePassed);
        void checkCollisionWithMap(float Dx, float Dy, Map &map);
        void checkCollisionWithMap();
        void checkCollisionWithEnemies();

        void reset(float X, float Y);
        void setShield(float duration);

        sf::Sprite getSprite();        
        float getX();
        float getY();
        bool getAlive();
        bool getShield();

        void setAlive(bool a);
};

#endif
