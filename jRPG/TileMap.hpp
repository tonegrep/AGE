//
//  TileMap.hpp
//  jRPG
//
//  Created by Антон on 13.02.18.
//  Copyright © 2018 Tohue. All rights reserved.
//

#ifndef TileMap_hpp
#define TileMap_hpp

#include <SFML/Graphics.hpp>

class TileMap : public sf::Drawable, public sf::Transformable
{
public:
    
    bool load(const std::string& tileset, sf::Vector2u tileSize, const int* tiles, unsigned int width, unsigned int height);
    
private:
    
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        // apply the transform
        states.transform *= getTransform();
        // apply the tileset texture
        states.texture = &m_tileset;
        // draw the vertex array
        target.draw(m_vertices, states);
    }
    
    sf::VertexArray m_vertices;
    sf::Texture m_tileset;
};


#endif /* TileMap_hpp */
