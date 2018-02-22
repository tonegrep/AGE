//
//  Game.cpp
//  jRPG
//
//  Created by Антон on 12.02.18.
//  Copyright © 2018 Tohue. All rights reserved.
//

#include <iostream>
#include "Game.hpp"
#include <SFML/Graphics.hpp>
#include "Character.hpp"
#include "Level.hpp"


Game::Game() {
    isOn = true;
    
    srand(time(NULL));
    
    
    //***************************
    //* for future declarations *
    //***************************
    
    
    // Create the main window
    //The old resolution is 896x504 (16:9)
    window.create(sf::VideoMode(800,600), "jRPG Engine");
    
    execute();
    
};

void Game::execute(){
    
    MainCharacter gg;
    TestChar ch;
    
    Level lvl(1);
    std::cout << lvl.number << " tourkw;"<< std::endl;
    Instance inst = *lvl.currentInstance;
    window.setView(gg.ggView);
    while (isOn) {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed) {
                isOn = false;
            }
            // Escape pressed: exit
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                isOn = false;
            }
        }
        
        gg.update();
        ch.update();
        
        // Clear screen
        window.clear();
        window.draw(inst.tileMap);
        window.draw(gg.getBody());
        window.draw(ch.getBody());
        // Update the window
        
        window.setView(gg.ggView);
        window.display();
    }
    
    window.close();
    
}
