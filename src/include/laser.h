#ifndef LASER
#define LASER

#include <SFML/Graphics.hpp>
#include <gameObj.h>

class laser: public GameObj {
    public:
    laser();
    laser(int cx, int cy, int mx, int my);
    void update(float time);
    sf::Sprite getSprite();
};

laser::laser():GameObj(){
    name = "laser";
}

laser::laser(int cx, int cy, int mx, int my):GameObj(){
    name = "laser";
    float distance = std::sqrt((cx - mx)*(cx - mx) + (cy - my)*(cy - my));
    x = cx;
    y = cy;

	dx = (cx - mx) / distance;
	dy = (cy - my) / distance;
}

void laser::update(float time){
    x += dx*time;
    y += dy*time;
}

sf::Sprite laser::getSprite(){
    return sprite;
}

#endif