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
int generateEnemies(Map map, std::list <Enemy*>  &enemies, int prev);

int main() {
	RenderWindow window(VideoMode(1200, 900), "sample rendering & gravity");

	View view;
    view.reset(FloatRect(0, 0, 1200, 900));

	Image groundIm;
	groundIm.loadFromFile("images/tileGreen_03.png");
	Texture ground;
	ground.loadFromImage(groundIm);

	Map map(30, 100);
	Hero h(2000, 400, 66, 93, "Player"); //объект класса игрока
	
	sf::CircleShape shape(1.f);  // точка, которая указывает текущие координаты персонажа
	shape.setFillColor(sf::Color::Red); 

	std::list <Enemy*>  enemies;
	// enemies.push_back(new frog(2000, 300));
	// enemies.push_back(new frog(1000, 300));
	// frog* e = new frog(2000, 400);
	int generated = 0;

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
			h.update(time, map);

			// setView(p.getX(), p.getY(), view);
			view.setCenter(h.getX(), h.getY());
			window.setView(view);
			
			window.clear();
			
			Sprite s_map;

			for (int i = 0; i < map.getMapHeight(); i++) {
				for (int j = 0; j < map.getMapWidth(); j++) {
					if (map.getMapSymbol(i, j) != '~') {
						if (map.getMapSymbol(i, j) == '0'){
							s_map.setTexture(ground);
						}
						s_map.setPosition(j * map.tileSize, i * map.tileSize);
						window.draw(s_map);
					} 
				}
			}

			generated = generateEnemies(map, enemies, generated);

			for (auto it = enemies.begin(); it != enemies.end(); it++){
				(*it)->update(time, map);
				// delete enemy if it`s far away ?
				window.draw((*it)->getSprite()); 
			}
			std::cout << enemies.size() << std::endl;

			checkCollisionWithEnemies(h, enemies);

			window.draw(h.getSprite());
			window.draw(shape);
			window.display();

			if(!window.isOpen()){
				for (auto it = enemies.begin(); it != enemies.end(); it++){
					delete (*it);
				}
				break;
			}
		}
	
		h.reset(2000, 400);
	}

	return 0;
}

void checkCollisionWithEnemies(Hero& hero, std::list <Enemy*>  enemies) {
	FloatRect heroR = hero.getSprite().getGlobalBounds();

	for (auto it = enemies.begin(); it != enemies.end(); it++){
		FloatRect enR = (*it)->getSprite().getGlobalBounds();
		if(heroR.intersects(enR) && !hero.getShield()){
			(*it)->convertVectors();
			int damage = (*it)->getDamage();
			hero.reduceHealth(damage);
			hero.setShield(1500);
			std::cout << hero.curHealth << " / " << hero.maxHealth << std::endl;
		}
	}
}

int generateEnemies(Map map, std::list <Enemy*>  &enemies, int prev){
	srand(time(NULL));
	int probability = rand()%500;

	if(probability != prev){
		if(probability >= 5 && enemies.size() < 10){
			// then gererate random enemy

			int x = rand() % map.getMapWidth();
			int y = rand() % map.getMapHeight();

			if(map.getMapSymbol(x, y) == '~'){
				enemies.push_back(new frog(x*map.tileSize, y*map.tileSize));
			}
		}
	}

	return probability;
}

// void setView(float x, float y, View view) { 
// 	float tempX = x; 
//     float tempY = y;
 
// 	if (x < 320) tempX = 320; //убираем из вида левую сторону
// 	if (y < 240) tempY = 240; //верхнюю сторону
// 	if (y > 554) tempY = 554; //нижнюю сторону	
 
// 	view.setCenter(tempX, tempY); //следим за игроком, передавая его координаты. 
// }
