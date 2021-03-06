//
//  Level.cpp
//  jRPG
//
//  Created by Антон on 13.02.18.
//  Copyright © 2018 Tohue. All rights reserved.
//

#include "Level.hpp"
#include "getPath.hpp"
#include <iostream>



Level::Level(int num) {
    
    
    pugi::xml_document levelDoc;
    //char * temp = getPath::as_char();
    pugi::xml_parse_result result = levelDoc.load_file(strcat(getPath::as_char(),"/Resources/level.xml"));
    if (!result)
        std::cout << "error loading level.xml, check document availability" << std::endl;
    pugi::xml_node docStruct = levelDoc.child("LevelDoc");
    std::cout << docStruct.name() << std::endl;
    pugi::xml_node levelNode = docStruct.find_child_by_attribute("number", "1");
    number = levelNode.child("number").text().as_int();
    
    pugi::xml_node instanceNode = levelNode.child("Instance");
    //while (instanceNode != levelNode.last_child())
    //for (pugi::xml_node instanceNode = levelNode.child("Instance"); instanceNode; instanceNode = instanceNode.next_sibling("Instance"))
    
    //{
        if (!strcmp(instanceNode.name(),"Instance"))
        {
            std::cout << instanceNode.name() << std::endl;
            Instance * instance = new Instance();
            (*instance).number = instanceNode.child("number").text().as_int();
            (*instance).width = instanceNode.child("width").text().as_int() * 32;
            (*instance).height = instanceNode.child("height").text().as_int() * 32;
            
            pugi::xml_node pointNode = instanceNode.first_child();
            /*while (pointNode != instanceNode.last_child())
            {
                if (!strcmp(instanceNode.name(), "ExitPoint"))
                {
                    Instance::exitPoint point;
                    point.body.setPosition(pointNode.child("x").text().as_int(), pointNode.child("y").text().as_int());
                    point.body.setSize(sf::Vector2f(pointNode.child("width").text().as_int(), pointNode.child("height").text().as_int()));
                    point.next = pointNode.child("nextNumber").text().as_int();
                    instance.exitPoints.push_back(point);
                    
                }
                
            }*/
            
            //should move this inside my magic xml file!!!
            /*const int a[] =
            {
                0,0,0,0,0,0,0,0,0,0,
                0,0,0,0,0,0,0,0,0,0,
                0,0,0,0,0,0,0,0,0,0,
                0,0,0,0,0,0,0,0,0,0,
                0,0,0,0,0,0,0,0,0,0,
                0,0,0,0,0,0,0,0,0,0,
                0,0,0,0,0,0,0,0,0,0,
                0,0,0,0,0,0,0,0,0,0,
                0,0,0,0,0,0,0,0,0,0,
                0,0,0,0,0,0,0,0,0,0,
            };*/
            std::cout << instanceNode.child("TileStruct").text().as_int();
            
            //Loading TileStruct
            
            
            
            
            int a[] =
            {
                instanceNode.child("TileStruct").text().as_int(),
            };
            (*instance).tileMap.load(instanceNode.child("TileMap").text().as_string(),
                                  sf::Vector2u(32,32),
                                  a,
                                  instanceNode.child("width").text().as_int(),
                                  instanceNode.child("height").text().as_int());
            instanceCount++;
            instances.push_back(*instance);
            if (number == 1) currentInstance = instance;
        }
    
        //instanceNode = instanceNode.next_sibling();
    //}

}


Instance::Instance() {
    
    
}


void Level::update(/*maybe RenderWindow & window*/) {
    

    
    
    //level update should keep mostly variable updates, all the graphics part goes to instance update
    currentInstance->update();
    
}

void Instance::update(/*maybe RenderWindow & window*/){
    
    
    
}
