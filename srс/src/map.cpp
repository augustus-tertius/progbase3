#include <map.h>

const int HEIGHT_MAP = 25;
const int WIDTH_MAP = 40;

std::string TileMap[HEIGHT_MAP] = {
        "0000000000000000000000000000000000000000",
        "0                                      0",
        "0                                      0",
        "0                                      0",
        "0                                      0",
        "0                                      0",
        "0                                      0",
        "0                                      0",
        "0                                      0",
        "0                                      0",
        "0                                      0",
        "0                                      0",
        "0                                      0",
        "0                                      0",
        "0                                      0",
        "0                                      0",
        "0                                      0",
        "0                                      0",
        "0                                      0",
        "0                                      0",
        "0                                      0",
        "0                       00             0",
        "0                    00000             0",
        "0      000           000000            0",
        "0000000000000000000000000000000000000000",
};

char getMapSymbol(int i, int j){
    return TileMap[i][j];
}

int getMapHeight(){
    return HEIGHT_MAP;
}

int getMapWidth(){
    return WIDTH_MAP;
}

