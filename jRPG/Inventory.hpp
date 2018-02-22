//
//  Inventory.hpp
//  jRPG
//
//  Created by Антон on 14.02.18.
//  Copyright © 2018 Tohue. All rights reserved.
//

#ifndef Inventory_hpp
#define Inventory_hpp

#include <vector>
#include <SFML/Graphics.hpp>
#include "Item.hpp"


class Inventory {
    
    int moneyCount;
    std::vector<Item> inventoryContainer;
    
    
};

#endif /* Inventory_hpp */
