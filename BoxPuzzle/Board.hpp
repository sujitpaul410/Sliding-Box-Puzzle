#ifndef Board_hpp
#define Board_hpp


#include <iostream>
#include "ResourcePath.hpp"
#include "Background.hpp"

class Board{
  
private:
    
    sf::Sprite boardSprite;
    sf::Texture boardTexture;
    
    void loadBoard();
    
    void initImage(sf::Texture& texture, sf::Sprite& background, std::string texName, sf::Vector2f targetSize, sf::Vector2f pos);
  
    
public:
    
    Board();
    
    void render(sf::RenderWindow* window);
};

#endif
