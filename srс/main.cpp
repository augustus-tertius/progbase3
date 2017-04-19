#include <SFML/Graphics.hpp>

using namespace sf;

int main(){
	RenderWindow window(sf::VideoMode(640, 480), "putting out a pic"); 
 
	Texture herotexture;
	herotexture.loadFromFile("images/main hero/master_sheet.png");
 
	Sprite herosprite;
	herosprite.setTexture(herotexture);
    herosprite.setTextureRect(IntRect(0,0,70,96));
	herosprite.setPosition(50, 25);

    while (window.isOpen()){
        sf::Event event;
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if (Keyboard::isKeyPressed(Keyboard::Right)) {
            herosprite.move(0.5, 0);
        } else if(Keyboard::isKeyPressed(Keyboard::Left)) {
            herosprite.move(-0.5, 0);
        }

        window.clear();
        window.draw(herosprite);
        window.display();
    }

    return 0;
}