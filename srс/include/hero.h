#include <SFML/Graphics.hpp>
#include <iostream>
#include "jump.h"

class Hero {
    int curHealth;
    int maxHealth;
    std::string filePath;
    Jump jump;

    Hero();
    void update(float timePassed);
};
