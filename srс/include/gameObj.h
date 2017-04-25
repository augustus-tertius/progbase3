#include <SFML/Graphics.hpp>

class GameObj {
public:
	float dx, dy, x, y, speed, moveTimer;
	int w, h, curHealth, maxHealth;
	bool alive, isMoving, onGround;
    enum {left, rigth} direction;

    std::string filePath;
	sf::Texture texture;
	sf::Sprite sprite;

	std::string name;
    
    GameObj(float X, float Y, int W, int H, std::string Name){
		x = X; 
        y = Y; 
        w = W; 
        h = H; 
        name = Name; 
        moveTimer = 0;
		speed = 0; 
        curHealth = 100; 
        dx = 0; 
        dy = 0;
		alive = true; 
        onGround = false; 
        isMoving = false;
		sprite.setTexture(texture);
		sprite.setOrigin(w / 2, h / 2);
	}

	GameObj(sf::Image &image, float X, float Y, int W, int H, std::string Name){
		x = X; 
        y = Y; 
        w = W; 
        h = H; 
        name = Name; 
        moveTimer = 0;
		speed = 0; 
        curHealth = 100; 
        dx = 0; 
        dy = 0;
		alive = true; 
        onGround = false; 
        isMoving = false;
		texture.loadFromImage(image);
		sprite.setTexture(texture);
		sprite.setOrigin(w / 2, h / 2);
	}
};