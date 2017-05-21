#include <enemy.h>

using namespace sf;

Enemy::Enemy(std::string Name, float X, float Y, int W, int H, int hel): GameObj( X, Y, W, H, hel, Name){
		// if (name == "EasyEnemy"){
		// 	sprite.setTextureRect(IntRect(0, 0, w, h));
		// 	dx = 0.1;
		// }
}

sf::Sprite Enemy::getSprite(){
    return sprite;
}

void Enemy::checkCollisionWithMap(float Dx, float Dy) {
	// for (int i = y / 32; i < (y + h) / 32; i++){ 
    //     for (int j = x / 32; j<(x + w) / 32; j++){
    //         if (TileMap[i][j] == '0') {
    //             if (Dy>0){ y = i * 32 - h; }
    //             if (Dy<0){ y = i * 32 + 32; }
    //             if (Dx>0){ x = j * 32 - w; dx = -0.1; sprite.scale(-1, 1); }
    //             if (Dx<0){ x = j * 32 + 32; dx = 0.1; sprite.scale(-1, 1); }
    //         }
    //     }
    // }

    bool colision = false;  

    if(Dx >= 0 && Dy >= 0) {
         for (int i = y / 64; i < (y + h/2) / 64; i++) {
            for (int j = x/ 64; j < (x + w/2) /64; j++) {
                if (getMapSymbol(i, j) == '0') {
                    if (Dy > 0) { 
                        y = i * 64 - h/2;  
                        dy = 0; 
                        onGround = true;
                        colision = true;
                    } else if (Dx > 0){ 
                        x = j * 64 - w/2; 
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
                        x = j * 64 + 64 + w/2; 
                    }
                }
            }
         }
    }

    onGround = colision;
}

	// void update(float time)
	// {
	// 	if (name == "EasyEnemy"){
	// 		//moveTimer += time;if (moveTimer>3000){ dx *= -1; moveTimer = 0; }//меняет направление примерно каждые 3 сек
	// 		checkCollisionWithMap(dx, 0);
	// 		x += dx*time;
	// 		sprite.setPosition(x + w / 2, y + h / 2);
	// 		if (health <= 0){ life = false; }
	// 	}
	// }