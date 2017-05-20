#ifndef WORLD
#define WORLD

#include <iostream>
#include "map.h"
#include "hero.h"
#include <SFML/Graphics.hpp>

class World { 
    sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode(640, 480), "sample rendering & gravity");
    sf::View view;
    sf::Clock clock;
    Hero hero = Hero(400, 400, 66, 93, "Player");

    // перенести в класс текстуры
    sf::Image groundIm;
	sf::Texture ground;
    //

    // список врагов
    int tileSize;

    public:
        World();
        ~World();
        int update();
};

#endif