#include "../include/enemies.h" 

using namespace sf;

frog::frog(float x, float y): Enemy( "frog", x, y, 128, 128, 20, 4){
    this->texture.loadFromFile("images/enemies/frog.png");
    state = stand;
}

void frog::update (float timePassed) {
    if(onGround){
        if(moveTimer > 2000){
            moveTimer = 0;
            state = jump;
            onGround = false;
            dy = -0.4;

            if(direction == left) {
                dx = 0.2;
            } else {
                dx = -0.2;
            }
            
        } else {
            moveTimer += timePassed;
        }
        this->texture.loadFromFile(this->filePath + "frog.png");
    } else {
        x += dx*timePassed;
		checkCollisionWithMap(dx, 0);

	    y += dy*timePassed;
		checkCollisionWithMap(0, dy);

        sprite.setPosition(x, y);

		if (!onGround) { 
            dy = dy + 0.0008*timePassed; 
        }

        this->texture.loadFromFile(this->filePath + "frog_move.png");
    }

    if (curHealth <= 0) { 
        alive = false; 
        this->texture.loadFromFile(this->filePath + "frog_dead.png");
    } 

    if(direction == right){
        sprite.setTextureRect(IntRect(0, 0, 128, 128));
    } else {
        sprite.setTextureRect(IntRect(128, 0, -128, 128));
    }

    sprite.setTexture(this->texture);
    // sprite.setScale();
}

void frog::checkCollisionWithMap(float Dx, float Dy) {

    if(Dx >= 0 && Dy >= 0) {
         for (int i = y / 64; i < (y + h/2) / 64; i++) {
            for (int j = x/ 64; j < (x + w/2) /64; j++) {
                if (getMapSymbol(i, j) == '0') {
                    if (Dy > 0) { 
                        y = i * 64 - h/2;  
                        dy = 0; 
                        onGround = true;
                    } else if (Dx > 0){ 
                        x = j * 64 - w/2; 
                        direction = right;

                    }
                }
            }
         }
    } else {
         for (int i = (y - h/2) / 64; i < y / 64; i++) {
            for (int j = (x - w/2) / 64; j < x / 64; j++) {
                if (getMapSymbol(i, j) == '0') {
                    if (Dy < 0){ 
                        y = i * 64 + 64 + h/2;  
                        dy = 0; 
                    } else if (Dx < 0){ 
                        direction = left;
                        x = j * 64 + 64 + w/2; 
                    }
                }
            }
         }
    }
}