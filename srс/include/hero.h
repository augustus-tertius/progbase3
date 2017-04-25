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
        Hero();
        void control (void);
        void update(float timePassed);
        void animation(float timePassed);

        sf::Sprite getSprite();
};

#endif
