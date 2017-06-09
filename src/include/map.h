#ifndef MAP
#define MAP

#include <iostream>
#include <SFML/Graphics.hpp>

class mapTiles{
public:
    sf::Texture zTex;
    sf::Texture sTex;
    sf::Texture iTex;
    sf::Texture mTex;
    sf::Texture uTex;
    sf::Texture eTex;
    sf::Texture gTex;

    sf::Texture shovelTex;

    mapTiles();
};

// class itemTex {
// public:
//     sf::Texture shovelTex;

//     itemTex();
// };

class Map {
    std::string filePath;

    int height;
    int width;
    char** map;

public:
    mapTiles tiles;
    int tileSize;

    Map(int h, int w);
    Map(std::string filePath);
    ~Map();
    char renderChanges(int xCent, int yCent, int MousePosX, int MousePosY, int tileSize, char insert);
    void saveToFile();
    void drawMiniMap(sf::RenderWindow &window, sf::View &view);
    int getSpawnY(int x);
    char getMapSymbol(int i, int j);
    int getMapHeight();
    int getMapWidth();
};

// char getMapSymbol(int i, int j);
// int getMapHeight();
// int getMapWidth();

#endif