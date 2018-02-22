//
//  Character.hpp
//  jRPG
//
//  Created by Антон on 12.02.18.
//  Copyright © 2018 Tohue. All rights reserved.
//

#ifndef Character_hpp
#define Character_hpp

#include <SFML/Graphics.hpp>
#include "StateMachine.hpp"

class Character {
protected:
    float moveSpeed;
    sf::RectangleShape body;
public:
    sf::Texture txt;
    Character();
    sf::RectangleShape getBody() {return body;};
    
};

class MainCharacter : public Character {
public:
    sf::View ggView;
    MainCharacter();
    void update();
    
    
    
};


enum testStates {stand, walkLeft, walkRight};

class TestChar : public Character{
  
private:
    testStates state = stand;
    sf::Clock timeCheck;
    
public:
    TestChar();
    void update();
    
};





#endif /* Character_hpp */
