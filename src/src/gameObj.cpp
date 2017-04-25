 #include <gameObj.h>

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
	// sprite.setOrigin(w / 2, h / 2);
}

 GameObj::GameObj(){
    moveTimer = 0;
	speed = 0; 
    curHealth = 100; 
    dx = 0; 
    dy = 0;
	alive = true; 
    onGround = false; 
    isMoving = false;
}
