//
//  Level.hpp
//  jRPG
//
//  Created by Антон on 13.02.18.
//  Copyright © 2018 Tohue. All rights reserved.
//

#ifndef Level_hpp
#define Level_hpp

#include <stdlib.h>
#include <vector>
#include <SFML/Graphics.hpp>
#include "pugixml.hpp"

#include "TileMap.hpp"



class Instance {
public:
    Instance();
    int number;
    TileMap tileMap;
    int width;
    int height;
    struct exitPoint {
        sf::RectangleShape body;
        int next;
    };
    std::vector<exitPoint> exitPoints;
    
    void update();
};


class Level {
public:
    int number;
    Level(int num);
    int instanceCount;
    Instance* currentInstance;
    std::vector<Instance> instances;
    
    void update();
};

class Menu {
    
};

class MainMenu : public Menu {
    
};

class PauseMenu : public Menu {
    
    
};

#endif /* Level_hpp */
