#ifndef WORLD
#define WORLD

#include <iostream>
#include "map.h"
#include "hero.h"
#include <SFML/Graphics.hpp>

class World { 
    Hero hero;
    // список врагов
    int tileSize;

    World();
    ~World();
    void update(float timePassed);
};

#endif