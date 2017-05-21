#include "../include/enemies.h" 

using namespace sf;

frog::frog(float x, float y): Enemy( "frog", x, y, 57, 36, 20){
    this->texture.loadFromFile("images/enemies/frog.png");
    // sprite.scale(0.5, 0.5);
    sprite.setOrigin(w/2, h/2);
    state = stand;
}

void frog::update (float timePassed) { 
    // std::cout << "i`m on " << x << " " << y << std::endl;
    std::cout << onGround << std::endl;
    FloatRect sp = sprite.getGlobalBounds();

    std::cout << "w = " << sp.width << "  h = " << sp.height << std::endl;

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

        sprite.setPosition(x - w / 2, y - h / 2);

		if (!onGround) { 
            dy = dy + 0.0008*timePassed; 
        }

        this->texture.loadFromFile(this->filePath + "frog_move.png");
    }

    if (curHealth <= 0) { 
        alive = false; 
        this->texture.loadFromFile(this->filePath + "frog_dead.png");
    } 

    sprite.setTexture(this->texture);
    sprite.setScale(0.5, 0.5);
}

void frog::checkCollisionWithMap(float Dx, float Dy) {
	// for (int i = y / 32; i < (y + h) / 32; i++){ 
    //     for (int j = x / 32; j<(x + w) / 32; j++){
    //         if (getMapSymbol(i, j) == '0') {
    //             if (Dy>0){ y = i * 64 - h; }
    //             if (Dy<0){ y = i * 64 + 64; }
    //             if (Dx>0){ x = j * 64 - w; dx = -0.2; sprite.scale(-1, 1); }
    //             if (Dx<0){ x = j * 64 + 64; dx = 0.2; sprite.scale(-1, 1); }
    //         }
    //     }
    // }

    // bool colision = false;  

    if(Dx >= 0 && Dy >= 0) {
         for (int i = y / 64; i < (y + h/2) / 64; i++) {
            for (int j = x/ 64; j < (x + w/2) /64; j++) {
                if (getMapSymbol(i, j) == '0') {
                    if (Dy > 0) { 
                        y = i * 64 - h;  
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