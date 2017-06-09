#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
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

bool menu(sf::RenderWindow &window, string &hero, string &name);
void interface(sf::RenderWindow &window, View &view, Font &font, Hero &hero);

int main() {
	RenderWindow window(VideoMode(1300, 1000), "sample rendering & gravity");

	View view;
    view.reset(FloatRect(0, 0, 1300, 1000));

	string hero, name;
	menu(window, hero, name);

	Map map(120, 500);
	Hero h(200, 200, 66, 93, "Player", "images/main hero/Green/Zeta/"); //объект класса игрока
	std::list <Enemy*>  enemies;
	
	int generated = 0;
	bool backToMenu = true;

	Clock clock;

	Font font; 
 	font.loadFromFile("files/FFF_Tusj.ttf");
	
	sf::CircleShape shape(1.f);	
	shape.setFillColor(sf::Color::Red);

	// Music music;
	// music.openFromFile("audio/Expansion.wav");
	// music.play();
	// music.setLoop(true);

	while (window.isOpen()) {
		// calling for menu
		// creating menu and hero using info from menu launching
		// bool play = menu(window, hero, name);

		// if(false == play) {
		// 	// window.close();
		// 	backToMenu = true;
		// } else {
		// 	backToMenu = false;
		// }

		// while (!backToMenu) {
			while(h.getAlive()) {
				float time = clock.getElapsedTime().asMicroseconds();
			
				clock.restart();
				time = time / 800;

				h.update(time, map);

				view.setCenter(h.getX(), h.getY());
				window.setView(view);

				// shape.setPosition(centX, centY);
				if(Mouse::isButtonPressed(Mouse::Left)) {
					int centX = view.getCenter().x + h.getW()/2;
					int centY = view.getCenter().y;

					int msX = view.getCenter().x - view.getSize().x/2 + Mouse::getPosition(window).x;
					int msY = view.getCenter().y - view.getSize().y/2 + Mouse::getPosition(window).y;

					char d = map.renderChanges(centX, centY, msX, msY, map.tileSize);
					if(d != '-'){
						h.luggage.add(d);
					}
				}
						
				window.clear();
				renderMap(window, view, map);

				// generated = generateEnemies(view, map, enemies, generated);
				drawEnemies(window, view, map, enemies, time);
				checkCollisionWithEnemies(h, enemies);

				window.draw(h.getSprite());
				interface(window, view, font, h);
				h.heroL.draw(window, view);
				map.drawMiniMap(window, view);
				window.draw(shape);
				window.display();

				if (Keyboard::isKeyPressed(Keyboard::M)){
					for (auto it = enemies.begin(); it != enemies.end(); it++){
						enemies.remove(*it);
						delete (*it);
					}
					h.setAlive(false);
					window.close();
					break;
				}
				
				Event event;
				while (window.pollEvent(event)) {
					if (event.type == sf::Event::Closed) {
						for (auto it = enemies.begin(); it != enemies.end(); it++){
							enemies.remove(*it);
							delete (*it);
						}
						h.setAlive(false);
						window.close();
						break;
					}						
				}
			}

			// if(!backToMenu) {
			// 	h.reset(400, 200);
			// }
			h.reset(400, 200);
		// }	
	}


	return 0;
}

void interface(sf::RenderWindow &window, View &view, Font &font, Hero &hero){
	RectangleShape upperBar = RectangleShape(sf::Vector2f(view.getSize().x, 60));
	upperBar.setFillColor(Color(47, 79, 79));
	upperBar.setPosition(view.getCenter().x - view.getSize().x/2, view.getCenter().y - view.getSize().y/2);

	window.draw(upperBar);

 	Text health("health: ", font, 46);

	health.setString(hero.getHealthStr());

	health.setPosition(view.getCenter().x + view.getSize().x/2 - 350, view.getCenter().y - view.getSize().y/2);
	window.draw(health);	
}

bool menu(sf::RenderWindow &window, string &hero, string &name){
	bool menuOpened = true;
	string path = "images/menu/";


	Texture bgT, voidVoicesT, newGameT, contT, quitT;
	bgT.loadFromFile(path + "bg.jpg");
	voidVoicesT.loadFromFile(path + "voidVoices.png");
	contT.loadFromFile(path + "continue.png");
	newGameT.loadFromFile(path + "newGame.png");
	quitT.loadFromFile(path + "endGame.png");

	std::list <Sprite> items;

	Sprite bg(bgT);
	Sprite voidVoices(voidVoicesT);
	Sprite newGame(newGameT);
	Sprite cont(contT);
	Sprite quit(quitT);

	voidVoices.setPosition(200, 100);
	newGame.setPosition(200, 400);
	cont.setPosition(200, 500);
	quit.setPosition(200, 600);

	items.push_back(newGame);
	items.push_back(cont);
	items.push_back(quit);

	// while(menuOpened){
	while (window.isOpen()) { 
		for (auto it = items.begin(); it != items.end(); it++){
			(*it).setColor(Color::White);
		}

		int counter = 0;
		int chosen = -1;
		for (auto it = items.begin(); it != items.end(); it++){
			if((*it).getGlobalBounds().contains(Mouse::getPosition(window).x, Mouse::getPosition(window).y)){
				(*it).setColor(Color(60, 179, 113));
				chosen = counter;
			}
			counter++;
		}

		if (Mouse::isButtonPressed(Mouse::Left)) {
			switch(chosen){
			case -1:
				break;
			case 0:
				cout << endl <<  "//////////////asked for new game, loading game" << endl << endl;
				return true;
				break;
			case 1:
				break;
			case 2:
				cout << endl <<  "//////////////asked for quit, closing window" << endl << endl;
				window.close();
				return false;
				break;
			}
		}
		

		window.clear();
		window.draw(bg);
		window.draw(voidVoices);
		for (auto it = items.begin(); it != items.end(); it++){
			window.draw(*it);
		}
		window.display();

		Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
				return false;
				break;
			}						
		}
	}
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

		// checking, if enemy is currently visible 
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
