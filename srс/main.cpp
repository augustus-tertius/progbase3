#include <SFML/Graphics.hpp>
#include "hero.h"

using namespace sf;

int main(){
	RenderWindow window(sf::VideoMode(640, 480), "some sample"); 
 
	// Texture herotexture;
	// herotexture.loadFromFile("images/main hero/master_sheet.png");
 
	// Sprite herosprite;
	// herosprite.setTexture(herotexture);
    // herosprite.setTextureRect(IntRect(0,0,70,96));
	// herosprite.setPosition(300, 200);
     
    Hero* mainHero = new Hero();

    Clock clock;
    float curFrame = 0;

    while (window.isOpen()){
        float time = clock.getElapsedTime().asMicroseconds();
        time = time/500;
        clock.restart();

        sf::Event event;
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        mainHero->update(time);

        // if (Keyboard::isKeyPressed(Keyboard::Right)){
        //     curFrame += time*0.005;
        //     if(curFrame > 2){
        //         curFrame = 0;
        //     }
        //     switch((int)curFrame){
        //         case 2:
        //         case 0:
        //             herosprite.setTextureRect(IntRect(415,0,70,96));
        //             break;
        //         case 1:
        //             herosprite.setTextureRect(IntRect(495,0,70,96));
        //             break;
        //     }

        //     herosprite.move(0.2*time, 0);
        // } else if(Keyboard::isKeyPressed(Keyboard::Left)){
        //      curFrame += time*0.005;
        //     if(curFrame > 2){
        //         curFrame = 0;
        //     }
        //     switch((int)curFrame){
        //         case 2:
        //         case 0:
        //             herosprite.setTextureRect(IntRect(485,0,-70,96));
        //             break;
        //         case 1:
        //             herosprite.setTextureRect(IntRect(565,0,-70,96));
        //             break;
        //     }
            
        //     herosprite.move(-0.2*time, 0);
        // } else {
        //     herosprite.setTextureRect(IntRect(0,0,70,96));
        // }

        window.draw(mainHero->getSprite());
        window.display();
    }

    return 0;
}