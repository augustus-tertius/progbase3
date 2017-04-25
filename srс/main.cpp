#include <SFML/Graphics.hpp>
#include <hero.h>
//#include <map.h>
//#include <view.h>

using namespace sf;

void setView(float x, float y, View view);

int main() {
	RenderWindow window(VideoMode(640, 480), "sample rendering & gravity");

	View view;
    view.reset(FloatRect(0, 0, 640, 480));
 
	Image map_image;
	map_image.loadFromFile("images/planetCenter.png");
	Texture map;
	map.loadFromImage(map_image);
	Sprite s_map;
	s_map.setTexture(map);

	Hero p(750, 500, 40, 30, "Player"); //объект класса игрока
	
	Clock clock;
	while (window.isOpen()) {
 
		float time = clock.getElapsedTime().asMicroseconds();
 
		clock.restart();
		time = time / 800;
		
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();	
		}		
		p.update(time);

		setView(p.getX(), p.getY(), view);
		window.clear();
 
		for (int i = 0; i < getMapHeight(); i++) {
            for (int j = 0; j < getMapWidth(); j++) {
                if (getMapSymbol(i, j) == ' ')  s_map.setTextureRect(IntRect(0, 0, 128, 128));
                // if ((TileMap[i][j] == '0')) s_map.setTextureRect(IntRect(64, 0, 32, 32));

                s_map.setPosition(j * 32, i * 32);
                window.draw(s_map);
            }
		}

		window.draw(p.getSprite());
		window.display();
	}

	return 0;
}

void setView(float x, float y, View view) { 
	float tempX = x; 
    float tempY = y;
 
	if (x < 320) tempX = 320; //убираем из вида левую сторону
	if (y < 240) tempY = 240; //верхнюю сторону
	if (y > 554) tempY = 554; //нижнюю сторону	
 
	view.setCenter(tempX, tempY); //следим за игроком, передавая его координаты. 
}


// int main(){
// 	RenderWindow window(sf::VideoMode(640, 480), "some sample"); 
     
//     Hero* mainHero = new Hero();

//     Clock clock;
//     float curFrame = 0;

//     while (window.isOpen()){
//         float time = clock.getElapsedTime().asMicroseconds();
//         time = time/500;
//         clock.restart();

//         sf::Event event;
//         while (window.pollEvent(event)){
//             if (event.type == sf::Event::Closed)
//                 window.close();
//         }

//         window.clear();
//         mainHero->update(time);

//         window.draw(mainHero->getSprite());
//         window.display();
//     }

//     return 0;
// }