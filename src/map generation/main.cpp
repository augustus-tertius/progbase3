#include <iostream>

using namespace std;

// for diamond square alg
void generateMap(string fileName, int partsQuan, int height, int width);
void diamondSquare(int w, int h);
void changeCenterHeight (int heights [], int r, int l, int bounds, int seed);
void recountSegment(int heights [], int r, int l);


// for Perlin Noise
typedef struct vector {
    float x;
    float y;
} Vector;
void gridOfRandomVectors(Vector** grid, int w, int h);
float Noise(float fx, float fy, Vector** grid);
void generateNoize(float** matrix, int w, int h);


int main() {
//    diamondSquare(80, 20);
    int h = 100;
    int w = 100;

    float** matrix = new float*[h];

    for(int i = 0; i < h; i++){
        matrix[i] = new float[w];
    }

    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            matrix[i][j] = 0;
        }
    }

    generateNoize(matrix, w, h);

    for(int i = 0; i < h; i++){
        delete matrix[i];
    }
    delete matrix;

    return 0;
}

//void generateMap(string fileName, int partsQuan, int height, int width){
//    int w = width / partsQuan;
//
//
//}

void diamondSquare(int w, int h) {
    // w / h is optimal in somewhere around 2/5 !!!

    int heigths [w];

    for(int i = 0; i < w; i++){
        heigths[i] = 0;
    }

    srand (time(NULL));
    changeCenterHeight(heigths, 0, w - 1, h/4, rand());

    // убираем единичные выступы
    for(int i = 1; i < w - 2; i++){
        if(heigths[i - 1] == heigths[i + 1]){
            if(abs(heigths[i - 1] - heigths[i]) == 1){
                heigths[i] = heigths[i - 1];
            }
        }
    }

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

void generateNoize(float** matrix, int w, int h){
    // попробуем ограничить каждый квадрат сетки 10х10 и разместить в углах узлов случайные векторы
    int frequency = 5;

    Vector** grid = new Vector*[h/frequency + 1];
    for(int i = 0; i < w/frequency + 1; i++){
        grid[i] = new Vector[w/frequency + 1];
    }

    gridOfRandomVectors(grid, w/frequency + 1, h/frequency + 1);
//    char permutationTable [];

    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            matrix[i][j] = Noise((float)i/frequency, (float)j/frequency, grid);
        }
    }

    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
//            if(matrix[i][j] != 0){
//                if(matrix[i][j] < 0.015 && matrix[i][j] > -0.015) {
//                    std::cout << 's' << " ";
//                } else {
//                    std::cout << '*' << " ";
//                }
//            }

            std::cout << matrix[i][j] << "\t";
        }
        std::cout << std::endl;
    }

    for(int i = 0; i < w/frequency + 1; i++){
        delete grid[i];
    }
    delete grid;
}

//Vector GetPseudoRandomGradientVector(int x, int y, char permutationTable []) {
//    int v = (int)(((x * 1836311903) ^ (y * 2971215073) + 4807526976) & 1023);
//    v = permutationTable[v]&3;
//
//    switch (v) {
//        case 0:  return (Vector){  1, 0 };
//        case 1:  return (Vector){ -1, 0 };
//        case 2:  return (Vector){  0, 1 };
//        default: return (Vector){  0,-1 };
//    }
//}

void gridOfRandomVectors(Vector** grid, int w, int h){
    srand(time(NULL));

    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            grid[i][j].x = (rand() % 100)/(100 * 1.0);
            grid[i][j].y = (rand() % 100)/(100 * 1.0);
        }
    }
}

float QunticCurve(float t) {
    return t * t * t * (t * (t * 6 - 15) + 10);
}

float Lerp(float a, float b, float t) {
    return a + (b - a) * t;
}

float Dot(Vector a, Vector b) {
    // скалярное произведение векторов
    return a.x * b.x + a.x * b.x;
}

float Noise(float fx, float fy, Vector** grid) {

    int left = (int)fx;
    int top  = (int)fy;
    float pointInQuadX = fx - left;
    float pointInQuadY = fy - top;

    Vector topLeftGradient     = grid[left][top];
    Vector topRightGradient    = grid[left + 1][top];
    Vector bottomLeftGradient  = grid[left][top + 1];
    Vector bottomRightGradient = grid[left + 1][top + 1];

    Vector distanceToTopLeft{ pointInQuadX,   pointInQuadY   };
    Vector distanceToTopRight { pointInQuadX-1, pointInQuadY   };
    Vector distanceToBottomLeft { pointInQuadX,   pointInQuadY-1 };
    Vector distanceToBottomRight { pointInQuadX-1, pointInQuadY-1 };

    float tx1 = Dot(distanceToTopLeft,     topLeftGradient);
    float tx2 = Dot(distanceToTopRight,    topRightGradient);
    float bx1 = Dot(distanceToBottomLeft,  bottomLeftGradient);
    float bx2 = Dot(distanceToBottomRight, bottomRightGradient);

    pointInQuadX = QunticCurve(pointInQuadX);
    pointInQuadY = QunticCurve(pointInQuadY);

    float tx = Lerp(tx1, tx2, pointInQuadX);
    float bx = Lerp(bx1, bx2, pointInQuadX);
    float tb = Lerp(tx, bx, pointInQuadY);

    return tb;
}
