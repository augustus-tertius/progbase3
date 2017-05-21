#include <enemy.h>

using namespace sf;

Enemy::Enemy(std::string Name, float X, float Y, int W, int H, int hel): GameObj( X, Y, W, H, hel, Name){
		// if (name == "EasyEnemy"){
		// 	sprite.setTextureRect(IntRect(0, 0, w, h));
		// 	dx = 0.1;
		// }
}

sf::Sprite Enemy::getSprite(){
    return sprite;
}

// void Enemy::checkCollisionWithMap(float Dx, float Dy) {
// 	// for (int i = y / 32; i < (y + h) / 32; i++){ 
//     //     for (int j = x / 32; j<(x + w) / 32; j++){
//     //         if (getMapSymbol(i, j) == '0') {
//     //             if (Dy>0){ y = i * 64 - h; }
//     //             if (Dy<0){ y = i * 64 + 64; }
//     //             if (Dx>0){ x = j * 64 - w; dx = -0.2; sprite.scale(-1, 1); }
//     //             if (Dx<0){ x = j * 64 + 64; dx = 0.2; sprite.scale(-1, 1); }
//     //         }
//     //     }
//     // }

//     // bool colision = false;  

//     if(Dx >= 0 && Dy >= 0) {
//          for (int i = y / 64; i < (y + h/2) / 64; i++) {
//             for (int j = x/ 64; j < (x + w/2) /64; j++) {
//                 if (getMapSymbol(i, j) == '0') {
//                     if (Dy > 0) { 
//                         y = i * 64 - h/2;  
//                         dy = 0; 
//                         onGround = true;
//                     } else if (Dx > 0){ 
//                         x = j * 64 - w/2; 
//                     }
//                 }
//             }
//          }
//     } else {
//          for (int i = (y - h/2) / 64; i < y / 64; i++) {
//             for (int j = (x - w/2) / 64; j < x / 64; j++) {
//                 if (getMapSymbol(i, j) == '0') {
//                     if (Dy < 0){ 
//                         y = i * 64 + 64 + h/2;  
//                         dy = 0; 
//                     } else if (Dx < 0){ 
//                         x = j * 64 + 64 + w/2; 
//                     }
//                 }
//             }
//          }
//     }
// }
