#include <SFML/Graphics.hpp>
#include "gameObj.h" 
#include <hero.h>
#include "map.h"
// #include "view.h"

#define DEFAULT_MAX_HEALTH 50


using namespace sf;

Hero::Hero(float X, float Y, int W, int H, std::string Name) :GameObj(){
	sprite.setTexture(this->texture);
    sprite.setTextureRect(IntRect(0,0,66,93));
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
    // this->sprite.scale(-1, 1);
    // this->texture.loadFromFile("images/main hero/master_sheet.png");
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

    bool prevState = false;
    if(this->direction == right){
         prevState = true;
    }
 

        if (Keyboard::isKeyPressed(Keyboard::Right)){
            this->direction = right;
            if(onGround) {
                this->state = walk;
            }
            this->dx = 0.2;

            if(onGround){
                this->animation(timePassed, prevState!= this->direction);
            }
            
        } else if(Keyboard::isKeyPressed(Keyboard::Left)){
            this->direction = left;
            if(onGround) {
                this->state = walk;
            }
            this->dx = -0.2;

            if(onGround){ 
                this->animation(timePassed, prevState!= this->direction);
            }
        } else {
            this->dx = 0;
            this->state = stand;
            this->texture.loadFromFile(this->filePath + "stand.png");
        }  
        
        if(Keyboard::isKeyPressed(Keyboard::Space)) {
            if(onGround) {
                this->state = jump; 
                this->dy = -0.6; 
                this->onGround = false;
                this->animation(timePassed, prevState!= this->direction);     
            } 
        }

        if(!onGround){
            this->state = jump;  
            this->animation(timePassed, prevState!= this->direction);
        }

}

void Hero::update(float timePassed) {
	    control(timePassed);

		x += dx*timePassed;
		checkCollisionWithMap(dx, 0);
	    y += dy*timePassed;
		checkCollisionWithMap(0, dy);


        // checkCollisionWithMap(dx, dy);

		// sprite.setPosition(x + w / 2, y + h / 2); 

        sprite.setPosition(x - w / 2, y - h / 2);

		if (curHealth <= 0) { 
            alive = false; 
        }

		if (!onGround) { 
            dy = dy + 0.00015*timePassed; 
        }

		// if (alive) { 
        //     setView(x, y);
        // }
} 

// void Hero::checkCollisionWithMap(){
//     int curJ = x / 64; // ширина
//     int curI = y / 64; // высота


//     // проверка на столкновение с землей
//     if(getMapSymbol(curI - h/64, curJ) == '0') {
//         dy = 0;
//         y = curI*64 - h;
//         onGround = true;
//     } else if (getMapSymbol(curI, curJ) == '-') {
//         std::cout << "Error: Index out of bounds" << std::endl;
//     } else if (getMapSymbol(curI, curJ) == ' ') {
//         std::cout << "There is noting here" << std::endl;
//     }

//     std::cout << "cur i = " << curI << ";  cur j = " << curJ << ";  x = " << x << ";  y = " << y <<std::endl;
// }

void Hero::checkCollisionWithMap(float Dx, float Dy) { 

    onGround = false; 
    if(Dx >= 0 && Dy >= 0) {
         for (int i = y / 64; i < (y + h/2) / 64; i++) {
            for (int j = x/ 64; j < (x + w/2) /64; j++) {
                if (getMapSymbol(i, j) == '0') {
                    if (Dy > 0) { 
                        y = i * 64 - h/2;  
                        dy = 0; 
                        onGround = true; 
                        std::cout << "\n setting y coord to " << this->y << std::endl;
                    } else if (Dx > 0){ 
                        x = j * 64 - w/2; 
                        std::cout << "\n setting x coord to " << this->x << std::endl;
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
                        std::cout << "\n setting y coord to " << this->y << std::endl;
                    } else if (Dx < 0){ 
                        x = j * 64 + 64 + w/2; 
                        std::cout << "\n setting x coord to " << this->x << std::endl;
                    }
                }
            }
         }
    }
        // for (int i = y / 64; i < (y + h/2) / 64; i++) {
        //     for (int j = x/ 64; j < (x + w/2) /64; j++) {
        //         if (getMapSymbol(i, j) == '0') {
        //             if (Dy > 0){ 
        //                 y = i * 64 - h/2;  
        //                 dy = 0; 
        //                 onGround = true; 
        //                 std::cout << "\n setting y coord to " << this->y << std::endl;
        //             } else if (Dy < 0){ 
        //                 y = i * 64 + 64 + h/2;  
        //                 dy = 0; 
        //                 std::cout << "\n setting y coord to " << this->y << std::endl;
        //             } else if (Dx > 0){ 
        //                 x = j * 64 - w/2; 
        //                 std::cout << "\n setting x coord to " << this->x << std::endl;
        //             } else if (Dx < 0){ 
        //                 x = j * 64 + 64 + w/2; 
        //                 std::cout << "\n setting x coord to " << this->x << std::endl;
        //             }
        //         }
        //     }
        // }
}


void Hero::animation(float timePassed, bool dirChanged){
    this->curFrame += timePassed*0.005;
    if(curFrame > 2){
        curFrame = 0;
    }

    // switch(this->state) {
    //     case stand:
    //         this->texture.loadFromFile(this->filePath + "stand.png");
    //         // if(direction == right) {
    //         //     sprite.setTextureRect(IntRect(66, 0, -66, 96));
    //         // } else {
    //         //     sprite.setTextureRect(IntRect(0, 0, 66, 96));
    //         // }
    //         break;
    //     case walk:
    //         switch((int)curFrame){
    //         case 2:
    //         case 0:
    //             this->texture.loadFromFile(this->filePath + "walk_1.png");
    //             if(direction == left) {
    //              sprite.setTextureRect(IntRect(66, 0, -66, 96));
    //             }
    //             break;
    //         case 1:
    //             this->texture.loadFromFile(this->filePath + "walk_2.png");
    //             if(direction == left) {
    //              sprite.setTextureRect(IntRect(66, 0, -66, 96));
    //             }
    //             break;
    //         }
    //         break;
    // }

    // if(!onGround){
    //     this->texture.loadFromFile(this->filePath + "jump.png");
    //     if(direction == left) {
    //              sprite.setTextureRect(IntRect(66, 0, -66, 96));
    //     }
    // }

    sprite.setTexture(this->texture);

    // if(this->direction == left && dirChanged) {
    //     this->sprite.scale(-1, 1);
    // } 

    // if(dirChanged) {
    //     this->sprite.scale(-1, 1);
    // } 
}



