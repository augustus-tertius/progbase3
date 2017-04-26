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
	sprite.setPosition(0, 0);

    x = X;
    y = Y;
    w = W;
    h = H;
    name = Name;
    this->curHealth = DEFAULT_MAX_HEALTH;
    this->maxHealth = DEFAULT_MAX_HEALTH;
    this->filePath = "images/main hero/Green/Zeta/";

    this->texture.loadFromFile(this->filePath + "stand.png");
    this->sprite.scale(-1, 1);
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

		sprite.setPosition(x + w / 2, y + h / 2); 
		if (curHealth <= 0) { 
            alive = false; 
        }

		if (!onGround) { 
            dy = dy + 0.0015*timePassed; 
            // dy = 0.0015*timePassed;
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
        for (int i = y / 64; i < (y + h) / 64; i++) {
            for (int j = x / 64; j < (x + w) /64; j++) {
                if (getMapSymbol(i + 1, j - 1) == '0') {
                    if (Dy > 0){ 
                        y = i * 64 - h;  
                        dy = 0; 
                        onGround = true; 
                        std::cout << "\n setting y coord to " << this->y << std::endl;
                    } else if (Dy < 0){ 
                        y = i * 64 + 64;  
                        dy = 0; 
                        std::cout << "\n setting y coord to " << this->y << std::endl;
                    } else if (Dx > 0){ 
                        x = j * 64 - w; 
                        std::cout << "\n setting x coord to " << this->x << std::endl;
                    } else if (Dx < 0){ 
                        x = j * 64 + 64; 
                        std::cout << "\n setting x coord to " << this->x << std::endl;
                    }

            //         			   if (TileMap[i][j] == '0')//если элемент наш тайлик земли? то
			//    {
			// 	   if (Dy>0){ y = i * 32 - h;  dy = 0; onGround = true; }//по Y вниз=>идем в пол(стоим на месте) или падаем. В этот момент надо вытолкнуть персонажа и поставить его на землю, при этом говорим что мы на земле тем самым снова можем прыгать
			// 	   if (Dy<0){ y = i * 32 + 32;  dy = 0; }//столкновение с верхними краями карты(может и не пригодиться)
			// 	   if (Dx>0){ x = j * 32 - w; }//с правым краем карты
			// 	   if (Dx<0){ x = j * 32 + 32; }// с левым краем карты
			//    }
    //         	void checkCollisionWithMap(float Dx, float Dy)
	// {
	// 	for (int i = 0; i<obj.size(); i++)
	// 	if (getRect().intersects(obj[i].rect))
	// 	{
	// 		if (obj[i].name == "solid")//если встретили препятствие
	// 		{
	// 			if (Dy>0)	{ y = obj[i].rect.top - h;  dy = 0; onGround = true; }
	// 			if (Dy<0)	{ y = obj[i].rect.top + obj[i].rect.height;   dy = 0; }
	// 			if (Dx>0)	{ x = obj[i].rect.left - w;  dx = -0.1; sprite.scale(-1, 1); }
	// 			if (Dx<0)	{ x = obj[i].rect.left + obj[i].rect.width; dx = 0.1; sprite.scale(-1, 1); }
	// 		}
	// 	}
	
                }
            }
        }
}


void Hero::animation(float timePassed, bool dirChanged){
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
                this->texture.loadFromFile(this->filePath + "walk_2.png");
                break;
            }
            break;
    }

    if(!onGround){
        this->texture.loadFromFile(this->filePath + "jump.png");
    }

    sprite.setTexture(this->texture);

    // if(this->direction == left && dirChanged) {
    //     this->sprite.scale(-1, 1);
    // } 
    if(dirChanged) {
        this->sprite.scale(-1, 1);
    } 
}



