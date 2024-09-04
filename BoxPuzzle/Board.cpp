#include "Board.hpp"


Board::Board()
{
    loadBoard();
}

void Board::loadBoard()
{
    initImage(boardTexture, boardSprite, "sample.jpg", sf::Vector2f(785.0f, 580.0f), sf::Vector2f(146, 97));
}

void Board::initImage(sf::Texture& texture, sf::Sprite& background, std::string texName, sf::Vector2f targetSize, sf::Vector2f pos)
{
    if (!texture.loadFromFile(resourcePath() + texName))
    {
        std::cout << "Error loading texture "+texName << std::endl;
        return EXIT_FAILURE;
    }
    std::cout<<"X: "<<texture.getSize().x<<" Y: "<<texture.getSize().y<<std::endl;
    // background.setTextureRect(sf::IntRect(sf::Rect(0, 0, 1000, 1000)));
    background.setTexture(texture);
    //    sf::Vector2f targetSize(800.0f, 600.0f);
    //    background.setPosition(sf::Vector2f(128, 70));
    background.setPosition(pos);
    background.setScale(targetSize.x / background.getLocalBounds().width, targetSize.y / background.getLocalBounds().height);
}


void Board::render(sf::RenderWindow* window)
{
    window->draw(boardSprite);
}

