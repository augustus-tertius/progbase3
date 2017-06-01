#ifndef MAP
#define MAP

#include <iostream>

class Map {
    std::string filePath;

    int height;
    int width;
    char map;

public:
    int tileSize;

    Map(int h, int w);
    Map(std::string filePath);
    ~Map();
    void saveToFile();
    char getMapSymbol(int i, int j);
    int getMapHeight();
    int getMapWidth();
};

// char getMapSymbol(int i, int j);
// int getMapHeight();
// int getMapWidth();

#endif