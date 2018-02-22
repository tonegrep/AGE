//
//  Character.cpp
//  jRPG
//
//  Created by Антон on 12.02.18.
//  Copyright © 2018 Tohue. All rights reserved.
//



#include "Character.hpp"
#include "getPath.hpp"

Character::Character() {
    body.setSize(sf::Vector2f(32.0f,32.0f));
    body.setPosition(100.0f, 100.0f);
    body.setFillColor(sf::Color::Blue);
    moveSpeed = 1.0f;
    txt.loadFromFile(strcat(getPath::as_char(),"/Resources/testTileSet.png"));
    body.setTexture(&txt);
    
};
MainCharacter::MainCharacter() {
    ggView.setSize(480.0f, 360.0f);
    ggView.setCenter(body.getPosition());
    
    //sf::Texture txt;

    
}

void MainCharacter::update() {
    
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        body.move(sf::Vector2f(-moveSpeed, 0.0f));
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        body.move(sf::Vector2f(0.0f, -moveSpeed));
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        body.move(sf::Vector2f(0.0f, moveSpeed));
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        body.move(sf::Vector2f(moveSpeed, 0.0f));
    
    ggView.setCenter(body.getPosition());
}

TestChar::TestChar() {
    body.setFillColor(sf::Color::Magenta);
    body.setPosition(500.0f, 100.0f);
    moveSpeed = 0.3f;
    timeCheck.restart();
    
}

void TestChar::update() {
    if (timeCheck.getElapsedTime() > sf::seconds(4.0f))
    {
        int rnd = rand() % 3;
        switch (rnd)
        {
            case 0:
                if (state == walkLeft || state == walkRight)
                    state = stand;
                else state = walkLeft;
                timeCheck.restart();
                break;
            case 1:
                if (state == walkLeft || state == walkRight)
                    state = stand;
                else state = walkRight;
                timeCheck.restart();
                break;
            default:
                timeCheck.restart();
                break;
        }
    }
    if (state == walkRight) body.move(sf::Vector2f(moveSpeed, 0.0f));
    else if (state == walkLeft) body.move(sf::Vector2f(-moveSpeed, 0.0f));
}
