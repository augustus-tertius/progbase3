#include <SFML/Graphics.hpp>
#include <hero.h>

using namespace sf;

int main(){
	RenderWindow window(sf::VideoMode(640, 480), "some sample"); 
     
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

        window.draw(mainHero->getSprite());
        window.display();
    }

    return 0;
}