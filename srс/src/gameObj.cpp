 #include <gameObj.h>
 #include <SFML/Graphics.hpp>  
   
   
GameObj::GameObj(float X, float Y, int W, int H, std::string Name){
	x = X; 
    y = Y; 
    w = W; 
    h = H; 
    name = Name; 
    moveTimer = 0;
	speed = 0; 
    curHealth = 100; 
    dx = 0; 
    dy = 0;
	alive = true; 
    onGround = false; 
    isMoving = false;
	sprite.setTexture(texture);
	sprite.setOrigin(w / 2, h / 2);
}

float GameObj::getX(){
    return this->x;
}

float GameObj::getY(){
    return this->y;
}