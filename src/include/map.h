#ifndef MAP
#define MAP

#include <iostream>

class Map {
    int tileSize;
    std::string filePath;

    int height;
    int width;
    char* map;


    Map(int h, int w);
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