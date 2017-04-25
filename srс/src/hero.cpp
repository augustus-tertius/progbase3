#include <SFML/Graphics.hpp>
#include "gameObj.h" 
#include <hero.h>
#include "map.h"
// #include "view.h"

#define DEFAULT_MAX_HEALTH 50


using namespace sf;

Hero::Hero(float X, float Y, int W, int H, std::string Name) :GameObj(){
	sprite.setTexture(this->texture);
    sprite.setTextureRect(IntRect(0,0,70,96));
	sprite.setPosition(300, 200);

    this->curHealth = DEFAULT_MAX_HEALTH;
    this->maxHealth = DEFAULT_MAX_HEALTH;
    this->filePath = "images/main hero/Green/Zeta";

    this->texture.loadFromFile(this->filePath + "stand.png");
}

sf::Sprite Hero::getSprite(){
    return this->sprite;
}

float Hero::getX(){
    return this->x;
}

float Hero::getY(){
    return this->y;
}

void Hero::control (float timePassed) {
     if (Keyboard::isKeyPressed(Keyboard::Right)){
            this->direction = right;
            this->state = walk;
            this->dx = 0.2;

            this->animation(timePassed);
        } else if(Keyboard::isKeyPressed(Keyboard::Left)){
            this->direction = left;
            this->state = walk;
            this->dx = -0.2;

            this->animation(timePassed);
        } else if(Keyboard::isKeyPressed(Keyboard::Space)) {
            this->state = jump; 
            this->dy = -0.6; 
            this->onGround = false;
        } else {
            this->sprite.setTextureRect(IntRect(0,0,70,96));
        }
}

void Hero::update(float timePassed) {
	    control(timePassed);

		x += dx*timePassed;
		checkCollisionWithMap(dx, 0);
	    y += dy*timePassed;
		checkCollisionWithMap(0, dy);

		sprite.setPosition(x + w / 2, y + h / 2); 
		if (curHealth <= 0) { 
            alive = false; 
        }

		if (!onGround) { 
            dy = dy + 0.0015*timePassed; 
        }

		// if (alive) { 
        //     setView(x, y);
        // }
} 

void Hero::checkCollisionWithMap(float Dx, float Dy) { 
        for (int i = this->y / 32; i < (this->y + this->h) / 32; i++) {
            for (int j = this->x / 32; j < (this->x + this->w) / 32; j++) {
                if (getMapSymbol(i, j) == '0') {
                    if (Dy > 0){ 
                        y = i * 32 - h;  
                        dy = 0; 
                        onGround = true; 
                    }
                    if (Dy < 0){ 
                        y = i * 32 + 32;  
                        dy = 0; 
                    }
                    if (Dx > 0){ 
                        x = j * 32 - w; 
                    }
                    if (Dx < 0){ 
                        x = j * 32 + 32; 
                    }
                }
            }
        }
}

void Hero::animation(float timePassed){
    this->curFrame += timePassed*0.005;
    if(curFrame > 2){
        curFrame = 0;
    }

    switch(this->state) {
        case stand:
            this->texture.loadFromFile(this->filePath + "stand.png");
            break;
        case walk:
            switch((int)curFrame){
            case 2:
            case 0:
                this->texture.loadFromFile(this->filePath + "walk_1.png");
                break;
            case 1:
                this->texture.loadFromFile(this->filePath + "walk_1.png");
                break;
            }
            break;
        case jump:
            this->texture.loadFromFile(this->filePath + "jump.png");
            break;
    }

    if(this->direction == left) {
        this->sprite.scale(-1, 1);
    }
}

// void Hero::checkCollisionWithMap(float Dx, float Dy) { 
//         for (int i = this->y / 32; i < (this->y + this->h) / 32; i++) {
//             for (int j = this->x / 32; j < (this->x + this->w) / 32; j++) {
//                 if (TileMap[i][j] == '0') {
//                     if (Dy > 0){ 
//                         y = i * 32 - h;  
//                         dy = 0; 
//                         onGround = true; 
//                     }
//                     if (Dy < 0){ 
//                         y = i * 32 + 32;  
//                         dy = 0; 
//                     }
//                     if (Dx > 0){ 
//                         x = j * 32 - w; 
//                     }
//                     if (Dx < 0){ 
//                         x = j * 32 + 32; 
//                     }
//                 }
//             }
//         }
// }



