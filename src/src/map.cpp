#include <map.h>

using namespace std;


void generateMap(int h, int w, char** map);

// for diamond square alg
void diamondSquare(int w, int h, char** map);
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

mapTiles::mapTiles(){
    sf::Image cur;
    cur.loadFromFile("images/tiles/grassCenter.png");
    groundTex.loadFromImage(cur);

    cur.loadFromFile("images/tiles/stoneCenter.png");
    stoneTex.loadFromImage(cur);

    cur.loadFromFile("images/tiles/snowCenter.png");
    snowTex.loadFromImage(cur);

    cur.loadFromFile("images/tiles/chocoCenter.png");
    chocoTex.loadFromImage(cur);

    cur.loadFromFile("images/tiles/sandCenter.png");
    sandTex.loadFromImage(cur);

    cur.loadFromFile("images/tiles/cakeCenter.png");
    cakeTex.loadFromImage(cur);
}


Map::Map(int h, int w){
    map = new char* [h];

    for(int i = 0; i < h; i++){
        map[i] = new char[w];
    }

    height = h;
    width = w;

    generateMap(h, w, map);
    tiles = mapTiles();

    tileSize = 64;
}

Map::~Map(){

    for(int i = 0; i < height; i++){
        delete map[i];
    }
    delete map;
}

char Map::getMapSymbol(int i, int j){
    // std::cout << "requested symbol in position " << i << " " << j << std::endl;
    
    if(i < height && i >= 0 && j < width && j >= 0) {
        return map[i][j];
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




void generateMap(int h, int w, char** map){

    diamondSquare(w, h, map);

    float** matrix = new float*[h];

    for(int i = 0; i < h; i++){
        matrix[i] = new float[w];
    }

    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            matrix[i][j] = 0;
        }
    }

    generateNoize(matrix, w, h*2/3);


    for(int i = h - 1; i > h/3; i--) {
        for (int j = 0; j < w; j++) {
            if(map[i - 1][j] != '~'){
                if(matrix[i - h/3][j] < -0.4) {
                    map[i - 1][j] = 'i';
                } else if(matrix[i - h/3][j] < -0.2){
                    map[i - 1][j] = 'z';
                } else if(matrix[i - h/3][j] < 0){
                    map[i - 1][j] = 's';
                } else if(matrix[i - h/3][j] < 0.1){
                    map[i - 1][j] = 'g';
                } else if(matrix[i - h/3][j] < 0.2){
                    map[i - 1][j] = 'r';
                } else if(matrix[i - h/3][j] < 0.3){
                    map[i - 1][j] = 'u';
                } else if(matrix[i - h/3][j] < 0.4){
                    map[i - 1][j] = 'm';
                } else if(matrix[i - h/3][j] < 0.6){
                    map[i - 1][j] = 'z';
                } else {
                    map[i - 1][j] = 'g';
                }
            }
        }
    }

    for(int i = h/3 - 1; i > 1; i--){
        for(int j = 0; j < w; j++){
            if(map[i][j] == 'o'){
                map[i][j] = 'g';
            }
        }
    }

    for(int j = 0; j < w; j++){
        map[0][j] = '0';
        map[h-1][0] = '0';
    }

    for(int i = 0; i < h; i++){
        map[i][0] = '0';
        map[i][w - 1] = '0';
    }

    for(int i = 0; i < h; i++){
        delete matrix[i];
    }
    delete matrix;
}

void diamondSquare(int w, int h, char** map) {
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


    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            map [i][j] = '~';
        }
    }

    for(int j = 0; j < w; j ++){
        int hi = heigths[j] + h/2;
        for(int i = h - 1; i >= hi; i--){
            map[i][j] = 'o';
        }
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
    // попробуем ограничить каждый квадрат сетки c заданой частотой и разместить в углах узлов случайные векторы
//    int frequency = h/2;
    int frequency = 10;

    Vector** grid = new Vector*[h/frequency + 1];

    for(int i = 0; i < h/frequency + 1; i++){
        grid[i] = new Vector[w/frequency + 1];
    }

    gridOfRandomVectors(grid, w/frequency + 1, h/frequency + 1);
//    char permutationTable [];

    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            matrix[i][j] = Noise((float)i/frequency, (float)j/frequency, grid);
        }
    }


    for(int i = 0; i < h/frequency + 1; i++) {
        delete grid[i];
    }
    delete grid;
}

void gridOfRandomVectors(Vector** grid, int w, int h){
    srand(time(NULL));

    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            grid[i][j].x = (rand() % 10)/(10 * 1.0);
            grid[i][j].y = (rand() % 10)/(10 * 1.0);
        }
    }
}

float QunticCurve(float t) {
    return t * t * t * (t * (t * 6 - 15) + 10) + 0.05;
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

    Vector distanceToTopLeft{ pointInQuadX,   pointInQuadY  };
    Vector distanceToTopRight { pointInQuadX-1, pointInQuadY   };
    Vector distanceToBottomLeft { pointInQuadX,   pointInQuadY-1 };
    Vector distanceToBottomRight { pointInQuadX-1, pointInQuadY-1 };

    float tx1 = Dot(distanceToTopLeft, topLeftGradient);
    float tx2 = Dot(distanceToTopRight, topRightGradient);
    float bx1 = Dot(distanceToBottomLeft, bottomLeftGradient);
    float bx2 = Dot(distanceToBottomRight, bottomRightGradient);

    pointInQuadX = QunticCurve(pointInQuadX);
    pointInQuadY = QunticCurve(pointInQuadY);

    float tx = Lerp(tx1, tx2, pointInQuadX);
    float bx = Lerp(bx1, bx2, pointInQuadX);

    float tb = Lerp(tx, bx, pointInQuadY);

    return tb;
}

