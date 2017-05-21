#include <gameObj.h>

class Enemy :public GameObj{
public:
	Enemy(sf::Image &image, std::string Name, float X, float Y, int W, int H, int hel);
 
	void checkCollisionWithMap(float Dx, float Dy) {
		for (int i = y / 32; i < (y + h) / 32; i++){ 
            for (int j = x / 32; j<(x + w) / 32; j++){
                if (TileMap[i][j] == '0') {
                    if (Dy>0){ y = i * 32 - h; }
                    if (Dy<0){ y = i * 32 + 32; }
                    if (Dx>0){ x = j * 32 - w; dx = -0.1; sprite.scale(-1, 1); }
                    if (Dx<0){ x = j * 32 + 32; dx = 0.1; sprite.scale(-1, 1); }
                }
            }
        }
	}
 
    virtual void update(float time) = 0;
};