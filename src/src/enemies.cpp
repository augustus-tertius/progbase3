#include "../include/enemies.h" 

using namespace sf;

frog::frog(float x, float y): Enemy( "frog", x, y, 128, 128, 20){
    this->texture.loadFromFile("images/enemies/frog.png");
    state = stand;
}

void frog::update (float timePassed){ 
    std::cout << "i`m on " << x << " " << y << std::endl;
    if(onGround){
        if(moveTimer > 2000){
            moveTimer = 0;
            state = jump;
            onGround = false;
            dy = 0.4;
            dx = 0.2;
        } else {
            moveTimer += timePassed;
        }
        this->texture.loadFromFile(this->filePath + "frog.png");
    } else {
        x += dx*timePassed;
		checkCollisionWithMap(dx, 0);

	    y += dy*timePassed;
		checkCollisionWithMap(0, dy);

        sprite.setPosition(x - w / 2, y - h / 2);

		if (!onGround) { 
            dy = dy + 0.0008*timePassed; 
        }
        this->texture.loadFromFile(this->filePath + "frog.png");
    }

    if (curHealth <= 0) { 
        alive = false; 
        this->texture.loadFromFile(this->filePath + "dead.png");
    } 

    sprite.setTexture(this->texture);
}