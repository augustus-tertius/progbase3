#include <SFML/Graphics.hpp>
#include "gameObj.h" 
#include <hero.h>
// #include "map.h"
// #include "view.h"

#define DEFAULT_MAX_HEALTH 50


using namespace sf;

Hero::Hero(float X, float Y, int W, int H, std::string Name) :GameObj(){
	sprite.setTexture(this->texture);
	// sprite.setPosition(0, 0);

    x = X;
    y = Y;
    w = W;
    h = H;
    
    name = Name;
    this->curHealth = DEFAULT_MAX_HEALTH;
    this->maxHealth = DEFAULT_MAX_HEALTH;
    this->filePath = "images/main hero/Green/Zeta/";

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
            if(onGround) {
                this->state = walk;
            }
            this->dx = 0.2;     
        } else if(Keyboard::isKeyPressed(Keyboard::Left)){
            this->direction = left;
            if(onGround) {
                this->state = walk;
            }
            this->dx = -0.2; 
        } else {
            this->dx = 0;
            this->state = stand;
        }  
        
        if(Keyboard::isKeyPressed(Keyboard::Space)) {
            if(onGround) {
                this->state = jump; 
                this->dy = -0.6; 
                this->onGround = false;   
            } 
        }

        

        this->animation(timePassed);
}

void Hero::update(float timePassed) {
	    control(timePassed);

        x += dx*timePassed;
		checkCollisionWithMap(dx, 0);

	    y += dy*timePassed;
		checkCollisionWithMap(0, dy);

        sprite.setPosition(x - w / 2, y - h / 2);

		if (curHealth <= 0) { 
            alive = false; 
        }

		if (!onGround) { 
            dy = dy + 0.0008*timePassed; 
        }
} 

void Hero::checkCollisionWithMap(float Dx, float Dy) {
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


void Hero::animation(float timePassed){
    this->curFrame += timePassed*0.005;
    if(curFrame > 2){
        curFrame = 0;
    }

    switch(this->state) {
        case stand:
            onGround = true; // полностью убирает мигания персонажа из-за проверки падения 
            this->texture.loadFromFile(this->filePath + "stand.png");
            if(direction == left) {
                sprite.setTextureRect(IntRect(66, 0, -66, 93));
            } else {
                sprite.setTextureRect(IntRect(0, 0, 66, 93));
            }
            break;
        case walk:
            onGround = true; // полностью убирает мигания персонажа при ходьбе из-за проверки падения 
            switch((int)curFrame){
            case 2:
            case 0:
                this->texture.loadFromFile(this->filePath + "walk_1.png");
                if(direction == left) {
                    sprite.setTextureRect(IntRect(68, 0, -68, 94));
                } else {
                    sprite.setTextureRect(IntRect(0, 0, 68, 94));
                }
                break;
            case 1:
                this->texture.loadFromFile(this->filePath + "walk_2.png");
                if(direction == left) {
                    sprite.setTextureRect(IntRect(71, 0, -71, 97));
                } else {
                    sprite.setTextureRect(IntRect(0, 0, 71, 97));
                }
                break;
            }
            break;
    }

    if(!onGround){
        this->texture.loadFromFile(this->filePath + "jump.png");
        if(direction == left) {
            sprite.setTextureRect(IntRect(67, 0, -67, 94));
        } else {
            sprite.setTextureRect(IntRect(0, 0, 67, 94));
        }
    }

    sprite.setTexture(this->texture);
}



