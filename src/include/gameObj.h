#ifndef GAME_OBJ
#define GAME_OBJ

#include <SFML/Graphics.hpp>

class GameObj {

protected:
// public:
	float dx, dy, x, y, speed, moveTimer;
	int w, h, curHealth, maxHealth;
	bool alive, isMoving, onGround;
    enum {left, right} direction;

    std::string filePath;
	sf::Texture texture;
	sf::Sprite sprite;

	std::string name;

    GameObj(float X, float Y, int W, int H, std::string Name);
	GameObj(float X, float Y, int W, int H, int heal, std::string Name);
    GameObj();

public:
	void reduceHealth(int damage);
};

#endif