#include <luggage.h>
#include <iostream>

using namespace sf;
using namespace std;

cell::cell(){
    quan = 0;
    isEmpty = true;
}

cell::cell(char ch){
    quan = 0;
    if(ch > 0 && ch <= 9) {
        isPowerUp = true;
        isEmpty = false;
        code = ch;
    } else {
        isTile = true;
        isEmpty = false;
        code = ch;
    }
}

void cell::increase(int q){
    quan += q;
}

void cell::decrease(int q){
    quan -= q;
    if(quan <= 0) {
        quan = 0;
        isEmpty = true;
    }
    cout << "now quan is  " << quan << endl;
}

void cell::setCode(char ch){
    code = ch;
}

char cell::getCode() {
    return code;
}

bool cell::getIsEmpty(){
    return isEmpty;
}

bool cell::getIsTile(){
    return isTile;
}

bool cell::getIsPowerUp(){
    return isPowerUp;
}

int  cell::getQuan(){
    return quan;
}

void cell::setSprite(sf::Texture t){
    sprite = Sprite(t);
}

void cell::setSpritePos(float x, float y) {
    sprite.setPosition(x, y);
}

sf::Sprite cell::getSprite(){
    return sprite;
}

void cell::setIsTool(bool t){
    isTool = t;
}

// items::items(){
//     // creating shovel
//     shovel = cell(',');
//     Texture st;
//     st.loadFromFile("shov.png");
//     // float scale = 54 / (float)curSprite.getTextureRect().width;
//     // st.setScale(scale, scale);
//     shovel.setSprite(st);
//     shovel.setIsTool(true);

//     // todo creating laser
// }

luggage::luggage(){
    active = 0;
    capacity = 0;
    size = 0;
}

luggage::luggage(int s){
    active = 0;
    capacity = s;
    size = 0;
    cells = new cell[s];
    // itmT = itemTex();

    for(int i = 0; i < s; i++){
        cells[i] = cell();
    }

    if(capacity >= 3){
        // cells[0] = cell(',');
        // cells[0].increase(1);
        // cells[0].sprite = Sprite(mT.shovelTex);
        // cells[0].setIsTool(true);
        // size++;
        add(',');
        cells[0].setIsTool(true);
        size++;
    }

    mT = mapTiles();
}

luggage::~luggage(){
    // if freeing memory crashes for some reason ???

    // if(capacity > 0) {
    //     delete [] cells;
    // }
}

char luggage::charOfActive(){
    return cells[active].getCode();
}

void luggage::draw(sf::RenderWindow &window, sf::View &view, sf::Font &font){
    int barHi = 110;
    sf::RectangleShape lugBG = sf::RectangleShape(sf::Vector2f(1010, barHi));
	lugBG.setFillColor(sf::Color(47, 79, 79));
	lugBG.setPosition(view.getCenter().x - view.getSize().x/2, view.getCenter().y + view.getSize().y/2 - barHi - 10);
    window.draw(lugBG);

    int curX = view.getCenter().x - view.getSize().x/2 + 10;
    int curY = view.getCenter().y + view.getSize().y/2 - barHi;
    sf::RectangleShape curC = sf::RectangleShape(sf::Vector2f(90, 90));
    curC.setFillColor(sf::Color(143, 188, 143));

    for(int i = 0; i < this->capacity; i++){
        curC.setPosition(curX, curY);

        if(Mouse::isButtonPressed(Mouse::Left)){
            Vector2i pixelPos = Mouse::getPosition(window);
		    Vector2f pos = window.mapPixelToCoords(pixelPos);
            if(curC.getGlobalBounds().contains(pos.x, pos.y)){
                active = i;
		    }
        }

        if(active == i){
             curC.setFillColor(sf::Color(255, 160, 122));
        }

        window.draw(curC);
        curC.setFillColor(sf::Color(143, 188, 143));

        if(!cells[i].getIsEmpty()) {
            int spSize = 54;
            cells[i].setSpritePos(curX + (90 - spSize)/2, curY + (90 - spSize)/2);
            Sprite curSprite = cells[i].getSprite();
            float scale = (float)spSize / (float)curSprite.getTextureRect().width;
            curSprite.setScale(scale, scale);
            window.draw(curSprite);

            string qStr = to_string(cells[i].getQuan());
            Text q("", font, 24);
	        q.setString(qStr);
            q.setColor(Color::Black);
	        q.setPosition(curX + 3, curY + 70);
	        window.draw(q);
        }

        if(i == 0) {
             Text q("shovel", font, 43);
             q.setPosition(curX + 5, curY + 20);
             q.setColor(Color::Black);
             window.draw(q);
        }

        curX += 100;
    }
}

cell luggage::getActiveCell(){
    return cells[active];
}

bool luggage::add(char ch){
    if(size < capacity){
        for(int i = 0; i < capacity; i++) {
            if(cells[i].getCode() == ch && (!cells[i].getIsEmpty())) {
                cells[i].increase(1);
                return true;
            }
        }
        
        for(int i = 0; i < capacity; i++) {
           if(cells[i].getIsEmpty()){
               cells[i] = cell(ch);
               cells[i].increase(1);
               pickTex(i);
            //    cells[i].setSprite(mT.getCharSprite(ch));
                // cells[i].sprite = Sprite(mT.getCharSprite(ch));
            
               size++;
               return true;
           }
       } 
    } else {
        return false;
    }

}

void luggage::pickTex(int pos){
    if(pos >= capacity) return;

    char ch = cells[pos].getCode();

    switch(ch){
        case 'm':
        cells[pos].sprite = Sprite(mT.mTex);
        return;
        case 's':
        cells[pos].sprite = Sprite(mT.sTex);
        return;
        case 'z':
        cells[pos].sprite = Sprite(mT.zTex);
        return;
        case 'i':
        cells[pos].sprite = Sprite(mT.iTex);
        return;
        case 'u':
        cells[pos].sprite = Sprite(mT.uTex);
        return;
        case 'e':
        cells[pos].sprite = Sprite(mT.eTex);
        return;
        case 'g':
        cells[pos].sprite = Sprite(mT.gTex);
        return;
        case ',':
        cells[pos].sprite = Sprite(mT.shovelTex);
    }  
}

cell luggage::add(int pos, char ch){
    cell old = cells[pos];
    cells[pos] = cell(ch);
    return old;
}

void luggage::decrActive(int d){
    cells[active].decrease(d);
}