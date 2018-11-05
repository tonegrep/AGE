#include "game.h"
#include "character.h"

Game::Game() {
    srand(time(NULL));
    window.create(sf::VideoMode(800, 600), "AGE");
}

int Game::Loop() {

    MainCharacter gg;
    TestChar ch;

    while(window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed) {
                return EXIT_SUCCESS;
            }
            // Escape pressed: exit
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                return EXIT_SUCCESS;
            }
        }
        gg.Update();
        ch.Update();
        window.setView(gg.GetView());
        window.clear();
        window.draw(gg.GetBody());
        window.draw(ch.GetBody());
        window.display();
    }

    return EXIT_SUCCESS;
}