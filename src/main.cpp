#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <hero.h>
// #include <enemy.h>
#include <enemies.h>
// #include <laser.h>
#include <list>
#include <map.h>

using namespace sf;
using namespace std; 


void renderMap(sf::RenderWindow &window, View &view ,Map &map);
void checkCollisionWithEnemies(Hero &hero, std::list <Enemy*>  enemies);
int generateEnemies(View &view, Map &map, std::list <Enemy*>  &enemies, int prev);
void drawEnemies(RenderWindow &window, View &view, Map &map, std::list <Enemy*>  &enemies, float time);
// void drawLasers(RenderWindow &window, View &view, Map &map, std::list <Enemy*>  &enemies,std::list <laser*> lasers, float time);

bool menu(sf::RenderWindow &window);
void interface(sf::RenderWindow &window, View &view, Font &font, Hero &hero);
void control(sf::RenderWindow &window, View &view, Hero &hero, Map &map);

int main() {
	RenderWindow window(VideoMode(1300, 1000), "sample rendering & gravity");

	View view;
    view.reset(FloatRect(0, 0, 1300, 1000));

	string hero, name;
	menu(window);

	Map map(120, 500);
	int sh = 30;

	int respX = map.tileSize*map.getMapWidth()/2 - sh;
	int respY = map.getSpawnY(map.tileSize*map.getMapWidth()/2 - sh);

	Hero h(respX, respY, 
		66, 93, "Player", "images/main hero/Yellow/Zeta/"); //объект класса игрока

	std::list <Enemy*>  enemies;
	// std::list <laser*> lasers;
	
	int generated = 0;
	bool backToMenu = true;

	Clock clock;

	Font font; 
 	font.loadFromFile("files/GoodDog.otf");

	sf::Texture bgT;
    bgT.loadFromFile("images/bg3.jpg");
    Sprite bg = Sprite(bgT);
	bg.scale(view.getSize().x / (float)bg.getTextureRect().width, view.getSize().y / (float)bg.getTextureRect().height);

	// Music music;
	// music.openFromFile("audio/Expansion.wav");
	// music.play();
	// music.setLoop(true);

	while (window.isOpen()) {
			while(h.getAlive()) {
				float time = clock.getElapsedTime().asMicroseconds();
			
				clock.restart();
				time = time / 800;

				h.update(time, map);

				view.setCenter(h.getX(), h.getY());
				window.setView(view);

				control(window, view, h, map);
						
				window.clear();
				bg.setPosition(view.getCenter().x - view.getSize().x/2, view.getCenter().y - view.getSize().y/2);
				window.draw(bg);

				renderMap(window, view, map);

				generated = generateEnemies(view, map, enemies, generated);
				drawEnemies(window, view, map, enemies, time);
				checkCollisionWithEnemies(h, enemies);

				window.draw(h.getSprite());
				if(h.getShield()){
					h.getShieldSprite().setPosition(h.getX(), h.getY());
					window.draw(h.getShieldSprite());
				}

				interface(window, view, font, h);
				h.heroL.draw(window, view, font);
				map.drawMiniMap(window, view);

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

			h.reset(respX, respY);	
	}


	return 0;
}

void control(sf::RenderWindow &window, View &view, Hero &h, Map &map){
	Event event;
	while (window.pollEvent(event)){
		if(Mouse::isButtonPressed(Mouse::Left)) {
			int centX = view.getCenter().x + h.getW()/2;
			int centY = view.getCenter().y + h.getH()/2;

			Vector2i pixelPos = Mouse::getPosition(window);
			Vector2f pos = window.mapPixelToCoords(pixelPos);

			if(h.heroL.charOfActive() == ',') {
				char d = map.renderChanges(centX, centY, pos.x, pos.y, map.tileSize, '~');
				if(d != '-'){
					h.heroL.add(d);
				}
			} else if(h.heroL.getActiveCell().getIsTile() && !h.heroL.getActiveCell().getIsEmpty()){
				char d = map.renderChanges(centX, centY, pos.x, pos.y, map.tileSize, h.heroL.charOfActive());
				if(d == '~'){
					h.heroL.decrActive(1);
				}	
			}
		}
	}
	// if(Mouse::isButtonPressed(Mouse::Left)) {
	// 	int centX = view.getCenter().x + h.getW()/2;
	// 	int centY = view.getCenter().y + h.getH()/2;

	// 	Vector2i pixelPos = Mouse::getPosition(window);
	// 	Vector2f pos = window.mapPixelToCoords(pixelPos);

	// 	if(h.heroL.charOfActive() == ',') {
	// 		char d = map.renderChanges(centX, centY, pos.x, pos.y, map.tileSize, '~');
	// 		if(d != '-'){
	// 			h.heroL.add(d);
	// 		}
	// 	} else if(h.heroL.getActiveCell().getIsTile() && !h.heroL.getActiveCell().getIsEmpty()){
	// 		char d = map.renderChanges(centX, centY, pos.x, pos.y, map.tileSize, h.heroL.charOfActive());
	// 		if(d == '~'){
	// 			h.heroL.decrActive(1);
	// 		}
	// 	}
	// }
}

void interface(sf::RenderWindow &window, View &view, Font &font, Hero &hero){
	RectangleShape upperBar = RectangleShape(sf::Vector2f(view.getSize().x, 60));
	upperBar.setFillColor(Color(47, 79, 79));
	upperBar.setPosition(view.getCenter().x - view.getSize().x/2, view.getCenter().y - view.getSize().y/2);

	window.draw(upperBar);

 	Text health("health: ", font, 50);

	health.setString(hero.getHealthStr());

	health.setPosition(view.getCenter().x + view.getSize().x/2 - 350, view.getCenter().y - view.getSize().y/2);
	window.draw(health);	
}

bool menu(sf::RenderWindow &window){
	bool menuOpened = true;
	string path = "images/menu/";


	Texture bgT, voidVoicesT, newGameT, contT, quitT;
	bgT.loadFromFile(path + "bg.jpg");
	voidVoicesT.loadFromFile(path + "voidVoices.png");
	newGameT.loadFromFile(path + "newGame.png");
	quitT.loadFromFile(path + "endGame.png");

	std::list <Sprite> items;

	Sprite bg(bgT);
	Sprite voidVoices(voidVoicesT);
	Sprite newGame(newGameT);
	Sprite quit(quitT);

	voidVoices.setPosition(200, 100);
	newGame.setPosition(200, 400);
	quit.setPosition(200, 530);

	items.push_back(newGame);
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
					char curCh = (map.getMapSymbol(i, j));
					if (curCh != '~') {
						if (curCh == 'm'){
							s_map.setTexture(map.tiles.mTex);
						} else if(curCh == 's'){
							s_map.setTexture(map.tiles.sTex);
						} else if(curCh == 'z'){
							s_map.setTexture(map.tiles.zTex);
						} else if(curCh == 'i'){
							s_map.setTexture(map.tiles.iTex);
						} else if(curCh == 'u'){
							s_map.setTexture(map.tiles.uTex);
						} else if(curCh == 'e'){
							s_map.setTexture(map.tiles.eTex);
						} else if(curCh == 'g'){
							s_map.setTexture(map.tiles.gTex);
						} 
						if(curCh != '0'){
							float scale = (float)map.tileSize / (float)s_map.getTextureRect().width;
							s_map.setScale(scale, scale);

							s_map.setPosition(j * map.tileSize, i * map.tileSize);
							window.draw(s_map);
						}
					}
				}
			}
				
}

void checkCollisionWithEnemies(Hero &hero, std::list <Enemy*>  enemies) {
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
	int probability = rand()%5000;

	if(probability != prev){
		if(probability >= 10 && enemies.size() < 6){
			// then gererate random enemy

			int x = rand() % map.getMapWidth();
			// int y = map.getSpawnY(x);
			int y = rand() % map.getMapHeight();
			
			bool free = true;

			for(int i = y - 5; i <= y + 5; i++){
				for(int j = x - 5; j <= x + 5; j++){
					if(map.getMapSymbol(i, j) != '~'){
						free = false;
						if(map.getMapSymbol(i, j) == '-') {
							return probability;
						}
					}
				}
			}

			if(free){
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
		Sprite curS = (*it)->getSprite();

		// delete enemy if it`s far away
		if(view.getCenter().x - view.getSize().x*3 > curS.getPosition().x ) {
			enemies.remove(*it);
			delete (*it);
		} else if(view.getCenter().x + view.getSize().x*3 < curS.getPosition().x){ 
			enemies.remove(*it);
			delete (*it);
		} else {
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
}

// void drawLasers(RenderWindow &window, View &view, Map &map, std::list <Enemy*>  &enemies,std::list <laser*> lasers, float time){
// 	for (auto it = lasers.begin(); it != lasers.end(); it++){
// 		(*it)->update(time);
// 		Sprite curS = (*it)->getSprite();

// 		window.draw(curS); 
// 	}
// }
