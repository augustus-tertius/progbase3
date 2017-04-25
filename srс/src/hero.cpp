#include <SFML/Graphics.hpp>
#include "hero.h" 
#include "jump.h"

#define DEFAULT_MAX_HEALTH 50


using namespace sf;

Hero::Hero(){
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

void Hero::control (void) {
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
	    control();

		x += dx*time;
		checkCollisionWithMap(dx, 0);
	    y += dy*time;
		checkCollisionWithMap(0, dy);

		sprite.setPosition(x + w / 2, y + h / 2); 
		if (health <= 0) { 
            life = false; 
        }

		if (!onGround) { 
            dy = dy + 0.0015*time; 
        }

		if (life) { 
            setPlayerCoordinateForView(x, y); 
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

    if(this->derection == left) {
        this->sprite.scale(-1, 1);
    }
}

void checkCollisionWithMap(float Dx, float Dy) { //ф ция проверки столкновений с картой{
    for (int i = y / 32; i < (y + h) / 32; i++) {//проходимся по элементам карты
	    for (int j = x / 32; j<(x + w) / 32; j++) {
			if (TileMap[i][j] == '0') {
			    if (Dy > 0){ 
                    y = i * 32 - h;  dy = 0; onGround = true; 
                }//по Y вниз=>идем в пол(стоим на месте) или падаем. В этот момент надо вытолкнуть персонажа и поставить его на землю, при этом говорим что мы на земле тем самым снова можем прыгать
				if (Dy < 0){ 
                    y = i * 32 + 32;  dy = 0; 
                }//столкновение с верхними краями карты(может и не пригодиться)
				if (Dx > 0){ 
                    x = j * 32 - w; 
                }//с правым краем карты
				if (Dx < 0){ 
                    x = j * 32 + 32; 
                }// с левым краем карты
			}
			   //else { onGround = false; }//надо убрать т.к мы можем находиться и на другой поверхности или платформе которую разрушит враг
		}
    }
}


// class Player :public Entity {
// public:
// 	enum { left, right, up, down, jump, stay } state;//добавляем тип перечисления - состояние объекта
// 	int playerScore;//эта переменная может быть только у игрока

// 	   Player(Image &image, float X, float Y,int W,int H,String Name):Entity(image,X,Y,W,H,Name){
// 		   playerScore = 0; state = stay;
// 		   if (name == "Player1"){
// 			   sprite.setTextureRect(IntRect(4, 19, w, h));
// 		   }
// 	   }

// 	   void control(){
// 		   if (Keyboard::isKeyPressed){//если нажата клавиша
// 			   if (Keyboard::isKeyPressed(Keyboard::Left)) {//а именно левая
// 				   state = left; speed = 0.1;
// 			   }
// 			   if (Keyboard::isKeyPressed(Keyboard::Right)) {
// 				   state = right; speed = 0.1;
// 			   }

// 			   if ((Keyboard::isKeyPressed(Keyboard::Up)) && (onGround)) {//если нажата клавиша вверх и мы на земле, то можем прыгать
// 				   state = jump; dy = -0.6; onGround = false;//увеличил высоту прыжка
// 			   }

// 			   if (Keyboard::isKeyPressed(Keyboard::Down)) {
// 				   state = down;
// 			   }
// 		   }
// 	   } 

// 	   void checkCollisionWithMap(float Dx, float Dy)//ф ция проверки столкновений с картой
// 	   {
// 		   for (int i = y / 32; i < (y + h) / 32; i++)//проходимся по элементам карты
// 		   for (int j = x / 32; j<(x + w) / 32; j++)
// 		   {
// 			   if (TileMap[i][j] == '0')//если элемент наш тайлик земли? то
// 			   {
// 				   if (Dy>0){ y = i * 32 - h;  dy = 0; onGround = true; }//по Y вниз=>идем в пол(стоим на месте) или падаем. В этот момент надо вытолкнуть персонажа и поставить его на землю, при этом говорим что мы на земле тем самым снова можем прыгать
// 				   if (Dy<0){ y = i * 32 + 32;  dy = 0; }//столкновение с верхними краями карты(может и не пригодиться)
// 				   if (Dx>0){ x = j * 32 - w; }//с правым краем карты
// 				   if (Dx<0){ x = j * 32 + 32; }// с левым краем карты
// 			   }
// 			   //else { onGround = false; }//надо убрать т.к мы можем находиться и на другой поверхности или платформе которую разрушит враг
// 		   }
// 	   }
	    
// 	   void update(float time)
// 	   {
// 		   control();//функция управления персонажем
// 		   switch (state)//тут делаются различные действия в зависимости от состояния
// 		   {
// 		   case right:dx = speed; break;//состояние идти вправо
// 		   case left:dx = -speed; break;//состояние идти влево
// 		   case up: break;//будет состояние поднятия наверх (например по лестнице)
// 		   case down: dx = 0; break;//будет состояние во время спуска персонажа (например по лестнице)
// 		   case stay: break;//и здесь тоже		
// 		   }
// 		   x += dx*time;
// 		   checkCollisionWithMap(dx, 0);//обрабатываем столкновение по Х
// 		   y += dy*time;
// 		   checkCollisionWithMap(0, dy);//обрабатываем столкновение по Y
// 		   sprite.setPosition(x + w / 2, y + h / 2); //задаем позицию спрайта в место его центра
// 		   if (health <= 0){ life = false; }
// 		   if (!isMove){ speed = 0; }
// 		   //if (!onGround) { dy = dy + 0.0015*time; }//убираем и будем всегда притягивать к земле
// 		   if (life) { setPlayerCoordinateForView(x, y); }
// 		   dy = dy + 0.0015*time;//постоянно притягиваемся к земле
// 	   } 
// };

