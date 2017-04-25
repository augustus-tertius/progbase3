#include <view.h>

View view;
view.reset(FloatRect(0, 0, 640, 480));

void setView(float x, float y) { 
	float tempX = x; 
    float tempY = y;
 
	if (x < 320) tempX = 320; //убираем из вида левую сторону
	if (y < 240) tempY = 240; //верхнюю сторону
	if (y > 554) tempY = 554; //нижнюю сторону	
 
	view.setCenter(tempX, tempY); //следим за игроком, передавая его координаты. 
}