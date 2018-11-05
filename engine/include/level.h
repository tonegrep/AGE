#ifndef _LEVEL_H_
#define _LEVEL_H_

#include <stdlib.h>
#include <cstring>
#include <vector>
#include <SFML/Graphics.hpp>
#include "pugixml.hpp"

#include "tile-map.h"

class Instance;
class Level;

class ExitPoint {
private:
    sf::RectangleShape body;
    int next;
public:
    friend Instance;
};

class Instance {
private:
    int number;
    TileMap tile_map;
    int width;
    int height;
    std::vector<ExitPoint> exits;
public:
    Instance();
    void Update();
    friend Level;
};


class Level {
private:
    int number;
    int instance_count;
    Instance* current_instance;
    std::vector<Instance> instances;

    pugi::xml_document level_doc;
    
public:
    Level(int num);
    void Update();
};

class Menu {
    
};

class MainMenu : public Menu {
    
};

class PauseMenu : public Menu {
    
    
};

#endif // !_LEVEL_H_