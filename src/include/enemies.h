#include "enemy.h" 

class frogTextures {
public:

    sf::Texture stand;
    sf::Texture jump;
    sf::Texture dead;

    frogTextures();
    frogTextures(std::string filePath);
};

class frog :public Enemy {
    enum {jump, stand} state;
    std::string filePath = "images/enemies/";
    frogTextures ft;
    
    public:

    frog(float x, float y);
    void update (float time, Map &map);
    void checkCollisionWithMap(float Dx, float Dy, Map &map);    
};

