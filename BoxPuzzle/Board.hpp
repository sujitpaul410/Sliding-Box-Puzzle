#ifndef Board_hpp
#define Board_hpp

#include"Game.hpp"

class Board{
  
private:
    
    sf::Sprite boardSprite;
    sf::Texture boardTexture;
    
    Game *game;
    
    void loadBoard();
    
public:
    
    void init();
};

#endif
