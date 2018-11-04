// Disclaimer:
// ----------
//
// Everybody knows shit's fucked, I don't give a fuck
// Goddamn you uncle Sam is a motherfucker
// I don't wanna see him again, how to pretend, count to ten
// You blew up your towers to justify a war
// Or I don't really care what your arms are for
// More money for defence, fuck hospitals
// Fuck human beings, fuck humanity

#include "Game.hpp"
#include <SFML/Graphics.hpp>

// Here is a small helper for you! Have a look.
#include "ResourcePath.hpp"

int main(int, char const**)
{
    //The game creates & executes
    Game* game = new Game();
    //After all the game process the game is being freed
    delete(game);
    
    return EXIT_SUCCESS;
}
