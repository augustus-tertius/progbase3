#ifndef HERO
#define HERO

#include <iostream>
#include "gameObj.h"
#include <SFML/Graphics.hpp>

class Hero : public GameObj {
    sf::Image image;
    sf::Texture texture;
    sf::Sprite sprite;

    enum {walk, jump, stand} state;
    float curFrame;

    public:
        Hero();
        ~Hero();
        void update(float timePassed);
        sf::Sprite getSprite();
};

#endif

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
