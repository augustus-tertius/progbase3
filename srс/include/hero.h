#ifndef HERO
#define HERO

#include <iostream>
#include "jump.h"
#include <SFML/Graphics.hpp>

class Hero {
    sf::Image image;
    sf::Texture texture;
    sf::Sprite sprite;

    float x;
    float y;
    float height;
    float wildth;
    float curFrame;

    int curHealth;
    int maxHealth;
    std::string filePath;
    Jump* jump;

    public:
        Hero();
        ~Hero();
        void update(float timePassed);
        sf::Sprite getSprite();
};

#endif
