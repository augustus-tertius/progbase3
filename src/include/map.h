#ifndef MAP
#define MAP

#include <iostream>
#include <SFML/Graphics.hpp>

class mapTiles{
public:
    sf::Texture groundTex;
    sf::Texture stoneTex;
    sf::Texture snowTex;
    sf::Texture chocoTex;
    sf::Texture sandTex;
    sf::Texture cakeTex;

    mapTiles();
};

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
    void renderChanges(int xCent, int yCent, int MousePosX, int MousePosY, int tileSize);
    void saveToFile();
    char getMapSymbol(int i, int j);
    int getMapHeight();
    int getMapWidth();
};

// char getMapSymbol(int i, int j);
// int getMapHeight();
// int getMapWidth();

#endif