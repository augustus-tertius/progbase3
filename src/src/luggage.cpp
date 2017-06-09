#include <luggage.h>
#include <iostream>

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
    capacity = 0;
    size = 0;
}

luggage::luggage(int s){
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
        window.draw(curC);
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