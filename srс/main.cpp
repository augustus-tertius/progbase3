#include <SFML/Graphics.hpp>
#include <hero.h>
#include <map.h>
#include <view.h>

using namespace sf;

int main() {
	RenderWindow window(VideoMode(640, 480), "sample rendering & gravity");

	// View view;
    // view.reset(FloatRect(0, 0, 640, 480));
 
	Image map_image;
	map_image.loadFromFile("images/map.png");
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

		setView(p.getX(), p.getY());
		window.clear();
 
		
			for (int i = 0; i < HEIGHT_MAP; i++) { 
                for (int j = 0; j < WIDTH_MAP; j++) {
                    if (TileMap[i][j] == ' ')  s_map.setTextureRect(IntRect(0, 0, 32, 32));
                    if (TileMap[i][j] == 's')  s_map.setTextureRect(IntRect(32, 0, 32, 32));
                    if ((TileMap[i][j] == '0')) s_map.setTextureRect(IntRect(64, 0, 32, 32));
                    if ((TileMap[i][j] == 'f')) s_map.setTextureRect(IntRect(96, 0, 32, 32));
                    if ((TileMap[i][j] == 'h')) s_map.setTextureRect(IntRect(128, 0, 32, 32));
                    s_map.setPosition(j * 32, i * 32);
                    
                    window.draw(s_map);
                }
			}

		window.draw(p.getSprite());
		window.display();
	}

	return 0;
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