#include <map.h>

const int HEIGHT = 10;
const int WIDTH= 40;

std::string TileMap[HEIGHT] = {
        "0000000000000000000000000000000000000000",
        "00                                     0",
        "0                                      0",
        "00                                     0",
        "0                                      0",
        "00                                     0",
        "0                       00             0",
        "0                    00000             0",
        "0      000           000000            0",
        "0000000000000000000000000000000000000000",
};

char getMapSymbol(int i, int j){
    if(i < HEIGHT && i > 0 && j < WIDTH && j > 0) {
        return TileMap[i][j];
    } else {
        return '-';
    }

}

int getMapHeight(){
    return HEIGHT;
}

int getMapWidth(){
    return WIDTH;
}

