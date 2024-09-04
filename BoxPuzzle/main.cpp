#include "Game.hpp"

int main(int, char const**)
{
    
    Game game;
    
    while(!game.getWindow()->isDone())
    {
        game.handleInput();
        game.update();
        game.render();
    }
    
    return EXIT_SUCCESS;
}

