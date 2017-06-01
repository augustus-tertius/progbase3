// #include "world.h"

// using namespace sf;

// // World::World(sf::RenderWindow* win): window(win){
// World::World(){
//     //  window = RenderWindow(VideoMode(640, 480), "sample rendering & gravity");
// 	hero = new Hero(400, 400, 66, 93, "Player");
// 	view.reset(FloatRect(0, 0, 640, 480));

//      //
//     groundIm.loadFromFile("images/tileGreen_03.png");
//     ground.loadFromImage(groundIm);
//      //
 
//     tileSize = 32;
// }

// World::~World(){
//     std::cout << "closing" << std::endl;
// }

// int World::update(sf::RenderWindow& window){
//     if(window.isOpen()){
//         float time = clock.getElapsedTime().asMicroseconds();
 
// 		clock.restart();
// 		time = time / 800;
		
// 		Event event;
// 		while (window.pollEvent(event)) {
// 			if (event.type == sf::Event::Closed)
// 				window.close();	
// 		}	

// 		hero->update(time);

// 		view.setCenter(hero->getX(), hero->getY());
// 		window.setView(view);
		
// 		window.clear();

//         Sprite s_map;
// 		for (int i = 0; i < getMapHeight(); i++) {
//             for (int j = 0; j < getMapWidth(); j++) {
//                 if (getMapSymbol(i, j) != ' ') {
//      				if (getMapSymbol(i, j) == '0'){
// 						s_map.setTexture(ground);
// 					}
// 					s_map.setPosition(j * 64, i * 64);
// 					window.draw(s_map);
// 				} 
//             }
// 		}
// 		// shape.setPosition(p.getX(), p.getY());

// 		window.draw(hero->getSprite());
// 		// window.draw(shape);
// 		window.display();

//         return 1;
// 	}
//     return 0;   
// }