#include <SFML/Graphics.hpp>
#include <hero.h>
// #include <enemy.h>
#include <enemies.h>
#include <world.h>
#include <list>

#include <map.h>
//#include <view.h>

// void setView(float x, float y, View view);
using namespace sf;


// int main(){
// 	World w;
// 	RenderWindow window(VideoMode(640, 480), "sample rendering & gravity");

// 	int opened = 1;

// 	while(opened){
// 		opened = w.update(window);
// 	}

// 	return 0;
// }

void checkCollisionWithEnemies(Hero& hero, std::list <Enemy*>  enemies);
void generateEnemies();

int main() {
	RenderWindow window(VideoMode(1200, 900), "sample rendering & gravity");

	View view;
    view.reset(FloatRect(0, 0, 1500, 900));

	Image groundIm;
	groundIm.loadFromFile("images/tileGreen_03.png");
	Texture ground;
	ground.loadFromImage(groundIm);

	Hero h(400, 400, 66, 93, "Player"); //объект класса игрока
	
	sf::CircleShape shape(1.f);  // точка, которая указывает текущие координаты персонажа
	shape.setFillColor(sf::Color::Red); 

	std::list <Enemy*>  enemies;
	enemies.push_back(new frog(2000, 300));
	enemies.push_back(new frog(1000, 300));
	// frog* e = new frog(2000, 400);

	Clock clock;
	while (window.isOpen()) {
		while(h.getAlive()){
			float time = clock.getElapsedTime().asMicroseconds();
 
			clock.restart();
			time = time / 800;
			
			Event event;
			while (window.pollEvent(event)) {
				if (event.type == sf::Event::Closed)
					window.close();	
			}		
			h.update(time);

			// setView(p.getX(), p.getY(), view);
			view.setCenter(h.getX(), h.getY());
			window.setView(view);
			
			window.clear();
			
			Sprite s_map;

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

			for (auto it = enemies.begin(); it != enemies.end(); it++){
				(*it)->update(time);
				window.draw((*it)->getSprite()); 
			}

			checkCollisionWithEnemies(h, enemies);

			window.draw(h.getSprite());
			window.draw(shape);
			window.display();
		}
	
		h.reset(400, 400);
	}

	return 0;
}

void checkCollisionWithEnemies(Hero& hero, std::list <Enemy*>  enemies){
	FloatRect heroR = hero.getSprite().getGlobalBounds();

	for (auto it = enemies.begin(); it != enemies.end(); it++){
		FloatRect enR = (*it)->getSprite().getGlobalBounds();
		if(heroR.intersects(enR)){
			(*it)->convertVectors();
			int damage = (*it)->getDamage();
			hero.reduceHealth(damage);
			std::cout << hero.curHealth << " / " << hero.maxHealth << std::endl;
		} 
	}
}

// void setView(float x, float y, View view) { 
// 	float tempX = x; 
//     float tempY = y;
 
// 	if (x < 320) tempX = 320; //убираем из вида левую сторону
// 	if (y < 240) tempY = 240; //верхнюю сторону
// 	if (y > 554) tempY = 554; //нижнюю сторону	
 
// 	view.setCenter(tempX, tempY); //следим за игроком, передавая его координаты. 
// }
