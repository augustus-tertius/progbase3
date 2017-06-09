#ifndef LUGGAGE
#define LUGGAGE

#include <SFML/Graphics.hpp>
#include "map.h"

class cell {
    bool isEmpty;
    bool isPowerUp;
    bool isTile;
    bool isTool;
    int quan;
    char code;

public:
    sf::Sprite sprite;

    cell();
    cell(char ch);
    void increase(int q);
    void decrease(int q);
    void setCode(char ch);
    char getCode();
    bool getIsEmpty();
    bool getIsTile();
    bool getIsPowerUp();
    void setIsTool(bool t);
    int getQuan();
    void setSprite(sf::Texture t);
    void setSpritePos(float x, float y);
    sf::Sprite getSprite();
};

class luggage {
public:
    int size;
    int capacity;
    int active;
    cell* cells;
    mapTiles mT;
    // itemTex itmT;

    luggage();
    luggage(int s);
    ~luggage();
    void draw(sf::RenderWindow &window, sf::View &view, sf::Font &font);
    cell getActiveCell();
    bool add(char ch);
    cell add(int pos, char ch);
    void pickTex(int pos);
    char charOfActive();
    void decrActive(int d);
};

#endif