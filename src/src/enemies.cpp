#include "../include/enemies.h" 

using namespace sf;

frog::frog(float x, float y): Enemy( "frog", x, y, 128, 128, 20, 4){
    this->texture.loadFromFile("images/enemies/frog.png");
    state = stand;
}

void frog::update (float timePassed, Map map) {
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
		checkCollisionWithMap(dx, 0, map);

	    y += dy*timePassed;
		checkCollisionWithMap(0, dy, map);

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

void frog::checkCollisionWithMap(float Dx, float Dy, Map map) {

    if(Dx >= 0 && Dy >= 0) {
         for (int i = y / map.tileSize; i < (y + h/2) / map.tileSize; i++) {
            for (int j = x / map.tileSize; j < (x + w/2) / map.tileSize; j++) {
                if (map.getMapSymbol(i, j) != '~') {
                    if (Dy > 0) { 
                        y = i * map.tileSize - h/2;  
                        dy = 0; 
                        onGround = true;
                    } else if (Dx > 0){ 
                        x = j * map.tileSize - w/2; 
                        direction = right;

                    }
                }
            }
         }
    } else {
         for (int i = (y - h/2) / map.tileSize; i < y / map.tileSize; i++) {
            for (int j = (x - w/2) / map.tileSize; j < x / map.tileSize; j++) {
                if (map.getMapSymbol(i, j) != '~') {
                    if (Dy < 0){ 
                        y = i * map.tileSize + map.tileSize + h/2;  
                        dy = 0; 
                    } else if (Dx < 0){ 
                        direction = left;
                        x = j * map.tileSize + map.tileSize + w/2; 
                    }
                }
            }
         }
    }
}