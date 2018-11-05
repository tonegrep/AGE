#ifndef _GAME_H_
#define _GAME_H_

#include <SFML/Graphics.hpp>
#include "level.h"

class Game {
private:
    sf::RenderWindow window;
    std::vector<Level> levels;

public:
    Game();
    int Loop();
    int InitLevel(std::string name);
};



#endif