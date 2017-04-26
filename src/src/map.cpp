#include <map.h>

const int HEIGHT = 10;
const int WIDTH= 41;

char TileMap[HEIGHT][WIDTH] = {
        "0000000000000000000000000000000000000000",
        "0                                      0",
        "0    0000                              0",
        "0                        000           0",
        "0                      00              0",
        "0                000000                0",
        "0     000000                           0",
        "0                                      0",
        "0              0000                    0",
        "0000000000000000000000000000000000000000",
};

char getMapSymbol(int i, int j){
    if(i < HEIGHT && i >= 0 && j <= WIDTH && j >= 0) {
        return TileMap[i][j];
    } else {
        // std::cout << i << " " << j << std::endl;
        return '-';
    }
    // return TileMap[i][j];
}

int getMapHeight() {
    return HEIGHT;
}

int getMapWidth() {
    return WIDTH;
}

