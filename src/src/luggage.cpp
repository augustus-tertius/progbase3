#include <luggage.h>
#include <iostream>

using namespace sf;
using namespace std;

cell::cell(){
    isEmpty = true;
}

cell::cell(char ch){
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
}

luggage::~luggage(){
    delete cells;
}

void luggage::draw(sf::RenderWindow &window, sf::View &view){
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
            cout << pos.x << " " << pos.y << endl;
            if(curC.getGlobalBounds().contains(pos.x, pos.y)){
                active = i;
		    }
        }

        if(active == i){
             curC.setFillColor(sf::Color(102, 205, 170));
        }

        window.draw(curC);
        curC.setFillColor(sf::Color(143, 188, 143));

        if(!cells[i].isEmpty) {
            int spSize = 70;
            cells[i].sprite.setPosition(curX + (90 - spSize)/2, curY + (90 - spSize)/2);
            window.draw(cells[i].sprite);
        }

        curX += 100;
    }
}

bool luggage::add(char ch){
    if(size < capacity){
        for(int i = 0; i < capacity; i++) {
            if(cells[i].getCode() == ch) {
                cells[i].increase(1);
                size++;
                return true;
            }
        }
        
        for(int i = 0; i < capacity; i++) {
           if(cells[i].getIsEmpty()){
               cells[i] = cell(ch);
               size++;
               return true;
           }
       } 
    } else {
        return false;
    }

}

cell luggage::add(int pos, char ch){
    cell old = cells[pos];
    cells[pos] = cell(ch);
    return old;
}