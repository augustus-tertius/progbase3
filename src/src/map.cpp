#include <map.h>

// const int HEIGHT = 18; // 18
// const int WIDTH = 81;

// char TileMap[HEIGHT][WIDTH] = {
//     "00000000000000000000000000000000000000000000000000000000000000000000000000000000",
//     "0                                                                              0",
//     "0                                                                              0",
//     "0                                                                              0",
//     "0                                                                              0",
//     "0                                                                              0",
//     "0                                                                              0",
//     "0                                                                              0",
//     "0                                                                              0",
//     "0                                                                              0",
//     "0                                                                              0",
//     "0                 0000                                                         0",
//     "0        0000                                                                  0",
//     "0                                                               0000000000000000",
//     "00000                                      0000000000000000000000000000000000000",
//     "0                                      00000000000000000000000000000000000000000",
//     "0              0000                   000000000000000000000000000000000000000000",
//     "00000000000000000000000000000000000000000000000000000000000000000000000000000000"
// };



Map::Map(int h, int w){
    map* = new char [h][w];
}

Map::~Map(){

}

char Map::getMapSymbol(int i, int j){
    if(i < height && i >= 0 && j <= width && j >= 0) {
        return m[i][j];
    } else {
        return '-';
    }
}

int Map::getMapHeight() {
    return height;
}

int Map::getMapWidth() {
    return width;
}

