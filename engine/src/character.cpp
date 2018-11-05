#include "character.h"
#include "get-path.h"

Character::Character() :
    move_speed(0.05f) {
    body.setSize(sf::Vector2f(32.0f,32.0f));
    body.setPosition(100.0f, 100.0f);
    body.setFillColor(sf::Color::Blue);
    txt.loadFromFile(strcat(GetPath::as_char(),"/Resources/testTileSet.png"));
    body.setTexture(&txt);
    
};
MainCharacter::MainCharacter() {
    gg_view.setSize(480.0f, 360.0f);
    gg_view.setCenter(body.getPosition());
    
    //sf::Texture txt;

    
}

void MainCharacter::Update() {
    
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        body.move(sf::Vector2f(-move_speed, 0.0f));
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        body.move(sf::Vector2f(0.0f, -move_speed));
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        body.move(sf::Vector2f(0.0f, move_speed));
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        body.move(sf::Vector2f(move_speed, 0.0f));
    
    gg_view.setCenter(body.getPosition());
}

TestChar::TestChar() {
    body.setFillColor(sf::Color::Magenta);
    body.setPosition(500.0f, 100.0f);
    time_check.restart();
    
}

void TestChar::Update() {
    if (time_check.getElapsedTime() > sf::seconds(4.0f))
    {
        int rnd = rand() % 3;
        switch (rnd)
        {
            case 0:
                if (state == walkLeft || state == walkRight)
                    state = stand;
                else state = walkLeft;
                time_check.restart();
                break;
            case 1:
                if (state == walkLeft || state == walkRight)
                    state = stand;
                else state = walkRight;
                time_check.restart();
                break;
            default:
                time_check.restart();
                break;
        }
    }
    if (state == walkRight) body.move(sf::Vector2f(move_speed, 0.0f));
    else if (state == walkLeft) body.move(sf::Vector2f(-move_speed, 0.0f));
}
