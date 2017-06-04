#include "../include/enemies.h" 

using namespace sf;


frogTextures::frogTextures(){

}

frogTextures::frogTextures(std::string filePath){
    this->stand.loadFromFile(filePath + "frog.png");
    this->jump.loadFromFile(filePath + "frog_move.png");
    this->dead.loadFromFile(filePath + "frog_dead.png");
}


frog::frog(float x, float y): Enemy( "frog", x, y, 128, 128, 20, 4){
    state = stand;
    ft = frogTextures(filePath);

    this->texture = ft.stand;
}

void frog::update (float timePassed, Map &map) {
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
        this->texture = ft.stand;
    } else {
        x += dx*timePassed;
		checkCollisionWithMap(dx, 0, map);

	    y += dy*timePassed;
		checkCollisionWithMap(0, dy, map);

        sprite.setPosition(x, y);

		if (!onGround) { 
            dy = dy + 0.0008*timePassed; 
        }

        this->texture = ft.jump;
    }

    if (curHealth <= 0) { 
        alive = false; 
        this->texture = ft.dead;
    } 

    if(direction == right){
        sprite.setTextureRect(IntRect(0, 0, 128, 128));
    } else {
        sprite.setTextureRect(IntRect(128, 0, -128, 128));
    }

    sprite.setTexture(this->texture);
    // sprite.setScale();
}

void frog::checkCollisionWithMap(float Dx, float Dy, Map &map) {  

    	for (int i = y / map.tileSize; i < (y + h) / map.tileSize; i++) { 
			for (int j = x / map.tileSize; j<(x + w) / map.tileSize; j++) {
				if (map.getMapSymbol(i, j) != '~') { 
					if (Dy > 0) {
						y = i * map.tileSize - h;
                        dy = 0; 
                        onGround = true;
					}
					if (Dy < 0) {
						y = i * map.tileSize + map.tileSize; 
                        dy = 0;		
                    }
					if (Dx > 0) {
						x = j * map.tileSize - w;
                        direction = right;
                        dx = 0;
					}
					if (Dx < 0) {
						x = j * map.tileSize + map.tileSize;
                        direction = left;
                        dx = 0;
					}
				}
            }
        }
}