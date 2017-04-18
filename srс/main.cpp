#include <SFML/Graphics.hpp>

using namespace sf;

int main()
{
	RenderWindow window(sf::VideoMode(640, 480), "putting out a pic"); //увеличили для удобства размер окна
 
	
 
	Texture herotexture;//создаем объект Texture (текстура)
	herotexture.loadFromFile("images/main hero/master_sheet.png");//загружаем картинку
 
	Sprite herosprite;//создаем объект Sprite(спрайт)
	herosprite.setTexture(herotexture);//передаём в него объект Texture (текстуры)
    herosprite.setTextureRect(IntRect(0,0,70,96));//получили нужный нам прямоугольник с котом
	herosprite.setPosition(50, 25);//задаем начальные координаты появления спрайта

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(herosprite);
        window.display();
    }

    return 0;
}