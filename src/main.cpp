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

	sf::Texture texture;
	texture.loadFromFile("images/corona_up.png");
	sf::Sprite background(texture);
	// background.setOrigin(background.getGlobalBounds()/2);

	Image groundIm;
	groundIm.loadFromFile("images/tileGreen_03.png");
	Texture ground;
	ground.loadFromImage(groundIm);

	Sprite s_map;
	// s_map.setTexture(map);

	Hero p(400, 400, 66, 93, "Player"); //объект класса игрока
	
	sf::CircleShape shape(1.f);  // точка, которая указывает текущие координаты персонажа
	shape.setFillColor(sf::Color::Red); 


	Clock clock;
	while (window.isOpen()) {
 
		float time = clock.getElapsedTime().asMicroseconds();
 
		clock.restart();
		time = time / 800;
		
		Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();	
		}		
		p.update(time);

		// setView(p.getX(), p.getY(), view);
		view.setCenter(p.getX(), p.getY());
		window.setView(view);
		
		window.clear();

		background.move(p.getX(), p.getY());
		window.draw(background); 
		// todo движение фона вместе с персонажем
		// todo пофиксить анимацию & работу с картой 
		

		for (int i = 0; i < getMapHeight(); i++) {
            for (int j = 0; j < getMapWidth(); j++) {
                if (getMapSymbol(i, j) != ' ') {
     				if (getMapSymbol(i, j) == '0'){
						s_map.setTexture(ground);
					}
					s_map.setPosition(j * 64, i * 64);
					window.draw(s_map);
				} 
            }
		}
		shape.setPosition(p.getX(), p.getY());

		window.draw(p.getSprite());
		window.draw(shape);
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