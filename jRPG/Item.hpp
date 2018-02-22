//
//  Item.hpp
//  jRPG
//
//  Created by Антон on 13.02.18.
//  Copyright © 2018 Tohue. All rights reserved.
//

#ifndef Item_hpp
#define Item_hpp

#include <SFML/Graphics.hpp>

class Item {
public:
    sf::RectangleShape body;
    
    
    
};

//For foods, something like flasks etc.
class Consumable : public Item {
    
    
    
    
};

//For money and ammo
class Spendable : public Item {
    
    
};





#endif /* Item_hpp */
