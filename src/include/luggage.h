#ifndef LUGGAGE
#define LUGGAGE

#include <SFML/Graphics.hpp>

class cell {
    bool isEmpty;
    bool isPowerUp;
    bool isTile;
    int quan;
    char code;

public:
    cell();
    cell(char ch);
    void increase(int q);
    void decrease(int q);
    void setCode(char ch);
    char getCode();
    bool getIsEmpty();

};

class luggage {
public:
    int size;
    int capacity;
    int active;
    cell* cells;

    luggage();
    luggage(int s);
    ~luggage();
    void draw(sf::RenderWindow &window, sf::View &view);
    bool add(char ch);
    cell add(int pos, char ch);
};

#endif