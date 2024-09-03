#include "Board.hpp"

void Board::loadBoard()
{
    game->initImage(boardTexture, boardSprite, "sample.jpg", sf::Vector2f(800.0f, 600.0f), sf::Vector2f(146, 97));
    game->addToDrawables("mainBoard", boardSprite);
}

void Board::init()
{
    game=Game::getInstance();
    loadBoard();
}
