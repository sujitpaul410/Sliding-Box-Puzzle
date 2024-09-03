#include "Game.hpp"
#include "Board.hpp""

int main(int, char const**)
{
    
    Game *game=Game::getInstance();
    game->initGame();
    
    Board board;
    board.init();
    
    game->runGame();
    
    
    return EXIT_SUCCESS;
}

