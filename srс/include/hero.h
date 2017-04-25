#ifndef HERO
#define HERO

#include <iostream>
#include "gameObj.h"
#include <SFML/Graphics.hpp>

class Hero : public GameObj {
    sf::Image image;
    sf::Texture texture;
    sf::Sprite sprite;

    enum {walk, jump, stand} state;
    float curFrame;

    public:
        // Hero(); mb add one later ?
        Hero(float X, float Y, int W, int H, std::string Name);
        void control (void);
        void update(float timePassed);
        void animation(float timePassed);

        sf::Sprite getSprite();
};

#endif
