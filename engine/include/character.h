//
//  Character.hpp
//  jRPG
//
//  Created by Антон on 12.02.18.
//  Copyright © 2018 Tohue. All rights reserved.
//

#ifndef _CHARACTER_H_
#define _CHARACTER_H_

#include <cstring>
#include <SFML/Graphics.hpp>

#include "state-machine.h"

class Character {
protected:
    float move_speed;
    sf::RectangleShape body;
    sf::Texture txt;
public:
    Character();
    virtual void Update() = 0;
    sf::RectangleShape GetBody() {return body;};
    
};

class MainCharacter : public Character {
private:
    sf::View gg_view;
public:
    sf::View GetView() {return gg_view;};
    MainCharacter();
    void Update();
    
    
    
};


enum testStates {stand, walkLeft, walkRight};

class TestChar : public Character{
  
private:
    testStates state = stand;
    sf::Clock time_check;
    
public:
    TestChar();
    void Update();
    
};





#endif /* _CHARACTER_H_ */
