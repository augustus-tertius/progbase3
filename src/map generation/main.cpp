#include <iostream>


// trying to implement random map gereration

void diamondSquare(int w, int h);
void changeCenterHeight (int heights [], int r, int l, int bounds, int seed);
void recountSegment(int heights [], int r, int l);

int main() {
    diamondSquare(40, 20);
    return 0;
}

void diamondSquare(int w, int h) {
    int heigths [w];

    for(int i = 0; i < w; i++){
        heigths[i] = 0;
    }

    srand (time(NULL));
    changeCenterHeight(heigths, 0, w - 1, h/4, rand());

    for(int i = 0; i < w; i++){
        std::cout << heigths[i] << " ";
    }
    std::cout << std::endl << std::endl << std::endl;

    char map [h][w];

    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            map [i][j] = ' ';
        }
    }

    for(int j = 0; j < w; j ++){
        int hi = heigths[j] + h/2;
        for(int i = h - 1; i >= hi; i--){
            map[i][j] = 'o';
        }
    }

    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            std::cout << map[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void changeCenterHeight (int heights [], int l, int r, int bounds, int seed){
    if(r > l && r - l > 1 && bounds > 0){
        srand (seed);
        int center = (r + l)/2;
        heights[center] = rand() % (2*bounds) - bounds;

        recountSegment(heights, l, center);
        recountSegment(heights, center, r);

        changeCenterHeight(heights, l, center, bounds/2, seed + 1356);
        changeCenterHeight(heights, center, r, bounds/2, seed - 1040);
    }
}

void recountSegment(int heights [], int l, int r){
    if(r - l == 1){
        return;
    }

    int c = (r + l)/2;
    heights[c] = (heights[r] + heights[l])/2;

    recountSegment(heights, l, c);
    recountSegment(heights, c, r);
}

