#include <SFML/Graphics.hpp>
#include "hero.h" 
#include "jump.h"

#define DEFAULT_MAX_HEALTH 50


using namespace sf;

Hero::Hero(){
	this->texture.loadFromFile("images/main hero/master_sheet.png");

	sprite.setTexture(this->texture);
    sprite.setTextureRect(IntRect(0,0,70,96));
	sprite.setPosition(300, 200);

    this->curHealth = DEFAULT_MAX_HEALTH;
    this->maxHealth = DEFAULT_MAX_HEALTH;
    this->filePath = "\0";
    this->jump = new Jump();
}

Hero::~Hero(){
    delete this->jump;
}

void Hero::update(float timePassed){
    if (Keyboard::isKeyPressed(Keyboard::Right)){
            curFrame += timePassed*0.005;
            if(curFrame > 2){
                curFrame = 0;
            }
            switch((int)curFrame){
                case 2:
                case 0:
                    this->sprite.setTextureRect(IntRect(415,0,70,96));
                    break;
                case 1:
                    this->sprite.setTextureRect(IntRect(495,0,70,96));
                    break;
            }

            this->sprite.move(0.2*timePassed, 0);
        } else if(Keyboard::isKeyPressed(Keyboard::Left)){
             curFrame += timePassed*0.005;
            if(curFrame > 2){
                curFrame = 0;
            }
            switch((int)curFrame){
                case 2:
                case 0:
                    this->sprite.setTextureRect(IntRect(485,0,-70,96));
                    break;
                case 1:
                    this->sprite.setTextureRect(IntRect(565,0,-70,96));
                    break;
            }
            
            this->sprite.move(-0.2*timePassed, 0);
        } else {
            this->sprite.setTextureRect(IntRect(0,0,70,96));
        }

}

sf::Sprite Hero::getSprite(){
    return this->sprite;
}

