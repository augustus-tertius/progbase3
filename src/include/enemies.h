#include "enemy.h" 

class frog :public Enemy {
    enum {jump, stand} state;
    std::string filePath = "images/enemies/";

    public:

    frog(float x, float y);
    void update (float time, Map map);
    void checkCollisionWithMap(float Dx, float Dy, Map map);    
};

