#include <SFML/Graphics.hpp>
#include "gameObj.h" 
#include <hero.h>
#include "map.h"
#include <sstream>
// #include "view.h"

#define DEFAULT_MAX_HEALTH 50


using namespace sf;
using namespace std;

heroTextures::heroTextures(){
}

heroTextures::heroTextures(std::string filePath){
        this->stand.loadFromFile(filePath + "stand.png");
        this->walk_1.loadFromFile(filePath + "walk_1.png");
        this->walk_2.loadFromFile(filePath + "walk_2.png");
        this->jump.loadFromFile(filePath + "jump.png");
}

Hero::Hero(float X, float Y, int W, int H, std::string Name, std::string filePath) :GameObj() {
    // sprite.setOrigin(w / 2, h / 2);
	sprite.setTexture(this->texture);
	// sprite.setPosition(0, 0);

    x = X;
    y = Y;
    w = W;
    h = H;
    
    name = Name;

    this->curHealth = DEFAULT_MAX_HEALTH;
    this->maxHealth = DEFAULT_MAX_HEALTH;
    this->filePath = filePath;
    ht = heroTextures(filePath);

    // this->texture.loadFromFile(this->filePath + "stand.png");
    this->texture = ht.stand;
    healTimer = 0;
    shield = false;
}

void Hero::setAlive(bool a){
    if(!a){
        curHealth = 0;
    }
    alive = a;
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

int Hero::getH(){
    return h;
}

int Hero::getW(){
    return w;
}

bool Hero::getAlive(){
    return alive;
}

bool Hero::getShield(){
    return shield;
}

int Hero::getCurHealth(){
    return curHealth;
}

int Hero::getMaxHealth(){
    return maxHealth;
}

std::string Hero::getHealthStr(){
    std::ostringstream HealthStr, MHStr;    
	HealthStr << curHealth;
	MHStr << maxHealth;

	string res = "health: " + HealthStr.str() + "/" + MHStr.str();
    return res;
}

void Hero::reset(float X, float Y){
    alive = true;
    curHealth = maxHealth;
    x = X;
    y = Y;
}

void Hero::setShield(float duration){
    if(duration > 0){
        shield = true;
        shieldTimer = duration;
    }
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

void Hero::updateHealth(float timePassed){
    healTimer += timePassed;
    if(healTimer > 1000){
        healTimer = 0;
        if(curHealth < maxHealth){
            curHealth++;
            // curHealth += regenerationSpeed; ???
        }
    }
}

void Hero::updateShield(float timePassed){
    if(shield){
            shieldTimer -= timePassed;
            if(shieldTimer < 0){
                shield = false;
                shieldTimer = 0;
            }
    }
}

void Hero::update(float timePassed, Map &map) {
        
	    control(timePassed);

        x += dx*timePassed;
		checkCollisionWithMap(dx, 0, map);

	    y += dy*timePassed;
		checkCollisionWithMap(0, dy, map);


        sprite.setPosition(x, y);

        updateHealth(timePassed);
        updateShield(timePassed);

		if (curHealth <= 0) { 
            alive = false; 
        }

		if (!onGround) { 
            dy = dy + 0.0008*timePassed; 
        }
} 

void Hero::checkCollisionWithMap(float Dx, float Dy, Map &map) {
    bool colision = false;  

    	for (int i = y / map.tileSize; i < (y + h) / map.tileSize; i++) { 
			for (int j = x / map.tileSize; j<(x + w) / map.tileSize; j++) {
				if (map.getMapSymbol(i, j) != '~') { 
					if (Dy > 0) {
						y = i * map.tileSize - h;
                        dy = 0; 
                        onGround = true;
                        colision = true;
					}
					if (Dy < 0) {
						y = i * map.tileSize + map.tileSize; 
                        dy = 0;		
                    }
					if (Dx > 0) {
						x = j * map.tileSize - w;
                        dx = 0;
					}
					if (Dx < 0) {
						x = j * map.tileSize + map.tileSize;
                        dx = 0;
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
            // this->texture.loadFromFile(this->filePath + "stand.png");
            texture = ht.stand;
            if(direction == left) {
                sprite.setTextureRect(IntRect(66, 0, -66, 93));
            } else {
                sprite.setTextureRect(IntRect(0, 0, 66, 93));
            }
            break;
        case walk:
            onGround = true; // полностью убирает мигания персонажа при ходьбе из-за проверки падения 
            switch((int)curFrame) {
            case 2:
            case 0:
                this->texture = ht.walk_1;
                if(direction == left) {
                    sprite.setTextureRect(IntRect(68, 0, -68, 94));
                } else {
                    sprite.setTextureRect(IntRect(0, 0, 68, 94));
                }
                break;
            case 1:
                this->texture = ht.walk_2;
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
        this->texture = ht.jump;
        if(direction == left) {
            sprite.setTextureRect(IntRect(67, 0, -67, 94));
        } else {
            sprite.setTextureRect(IntRect(0, 0, 67, 94));
        }
    }

    sprite.setTexture(this->texture);
}





