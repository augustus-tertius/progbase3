#include <SFML/Graphics.hpp>
#include <hero.h>
// #include <enemy.h>
#include <enemies.h>
#include <list>
#include <map.h>

using namespace sf;
using namespace std; 


void renderMap(sf::RenderWindow &window, View &view ,Map &map);
void checkCollisionWithEnemies(Hero& hero, std::list <Enemy*>  enemies);
int generateEnemies(View &view, Map &map, std::list <Enemy*>  &enemies, int prev);
void drawEnemies(RenderWindow &window, View &view, Map &map, std::list <Enemy*>  &enemies, float time);

int main() {
	RenderWindow window(VideoMode(1200, 900), "sample rendering & gravity");

	View view;
    view.reset(FloatRect(0, 0, 1200, 900));

	// calling for menu

	Map map(120, 500);
	Hero h(200, 200, 66, 93, "Player", "images/main hero/Green/Zeta/"); //объект класса игрока


	std::list <Enemy*>  enemies;

	int generated = 0;

	Clock clock;
	while (window.isOpen()) {

		bool backToMenu = false;

		while(!backToMenu){
			while(h.getAlive()) {
				float time = clock.getElapsedTime().asMicroseconds();
	
				clock.restart();
				time = time / 800;
				
				Event event;
				while (window.pollEvent(event)) {
					if (event.type == sf::Event::Closed)
						window.close();	
				}		

				h.update(time, map);

				view.setCenter(h.getX(), h.getY());
				window.setView(view);
				
				window.clear();
				renderMap(window, view, map);

				generated = generateEnemies(view, map, enemies, generated);
				drawEnemies(window, view, map, enemies, time);
				checkCollisionWithEnemies(h, enemies);

				window.draw(h.getSprite());
				window.display();

				if(!window.isOpen()){
					for (auto it = enemies.begin(); it != enemies.end(); it++){
						delete (*it);
					}
					break;
				}
			}
		
			h.reset(400, 200);
		}
	}

	return 0;
}

void renderMap(sf::RenderWindow &window,View &view, Map &map){
			Sprite s_map;
			int shift = 3;

			int xStart = (view.getCenter().x - view.getSize().x/2)/map.tileSize - shift;
			int xEnd = (view.getCenter().x + view.getSize().x/2)/map.tileSize + shift; 
			int yStart = (view.getCenter().y - view.getSize().y/2)/map.tileSize - shift;
			int yEnd = (view.getCenter().y + view.getSize().y/2)/map.tileSize + shift;

			if(xStart < 0){
				xStart = 0;
			}

			if(yStart < 0){
				yStart = 0;
			}

			if(xEnd > map.getMapWidth()){
				xEnd = map.getMapWidth();
			}
			
			if(yEnd > map.getMapHeight()){
				yEnd = map.getMapHeight();
			}


			for (int i = yStart; i < yEnd; i++) {
				for (int j = xStart; j < xEnd; j++) {
					if (map.getMapSymbol(i, j) != '~') {
						if (map.getMapSymbol(i, j) == 'm'){
							s_map.setTexture(map.tiles.snowTex);
						} else if(map.getMapSymbol(i, j) == 's'){
							s_map.setTexture(map.tiles.stoneTex);
						} else if(map.getMapSymbol(i, j) == 'c') {
							s_map.setTexture(map.tiles.cakeTex);
						} else if(map.getMapSymbol(i, j) == 'z') {
							s_map.setTexture(map.tiles.sandTex);
						} else if(map.getMapSymbol(i, j) != '0'){
							s_map.setTexture(map.tiles.groundTex);
						} 
						if(map.getMapSymbol(i, j) != '0'){
							float scale = (float)map.tileSize / (float)s_map.getTextureRect().width;
							s_map.setScale(scale, scale);

							s_map.setPosition(j * map.tileSize, i * map.tileSize);
							window.draw(s_map);
						}
					} 
				}
			}
				
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
		}
	}
}

int generateEnemies(View &view, Map &map, std::list <Enemy*>  &enemies, int prev){
	srand(time(NULL));
	int probability = rand()%500;

	if(probability != prev){
		if(probability >= 5 && enemies.size() < 10){
			// then gererate random enemy

			int x = rand() % map.getMapWidth();
			int y = rand() % map.getMapHeight();

			if(map.getMapSymbol(y, x) == '~'){
				int shift = 3;

				int xStart = (view.getCenter().x - view.getSize().x/2)/map.tileSize - shift;
				int xEnd = (view.getCenter().x + view.getSize().x/2)/map.tileSize + shift; 
				int yStart = (view.getCenter().y - view.getSize().y/2)/map.tileSize - shift;
				int yEnd = (view.getCenter().y + view.getSize().y/2)/map.tileSize + shift;

				if(!(x > xStart && x < xEnd)){
					// we don`t generate enemies in the visible zone
					cout << " new enemy in position " << x*map.tileSize << " " << y*map.tileSize << endl;
					enemies.push_back(new frog(x*map.tileSize, y*map.tileSize));
				}
			}
		}
	}

	return probability;
}

void drawEnemies(RenderWindow &window, View &view, Map &map, std::list <Enemy*>  &enemies, float time){
	for (auto it = enemies.begin(); it != enemies.end(); it++){
		(*it)->update(time, map);
				// delete enemy if it`s far away ?
		Sprite curS = (*it)->getSprite();

				// // checking, if enemy is currently visible 
		int shift = 3;

		int xStart = (view.getCenter().x - view.getSize().x/2)/map.tileSize - shift;
		int xEnd = (view.getCenter().x + view.getSize().x/2)/map.tileSize + shift; 
		int yStart = (view.getCenter().y - view.getSize().y/2)/map.tileSize - shift;
		int yEnd = (view.getCenter().y + view.getSize().y/2)/map.tileSize + shift;

		if(curS.getPosition().x/map.tileSize > xStart && curS.getPosition().x/map.tileSize  < xEnd && curS.getPosition().y/map.tileSize  > yStart && curS.getPosition().y/map.tileSize  < yEnd){
			window.draw(curS); 
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
