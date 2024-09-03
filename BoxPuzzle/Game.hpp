#ifndef Game_hpp
#define Game_hpp

#include <SFML/Graphics.hpp>
#include <iostream>
#include <unordered_map>
#include <string>
#include "ResourcePath.hpp"


class Game{
    
private:
    
    static Game *game;
    
    Game() {}
    
    sf::RenderWindow *window;
    
    sf::Sprite bgSprite;
    sf::Texture bgTexture;
    
    sf::Sprite bgFrameSprite;
    sf::Texture bgFrameTexture;
    
    sf::Font font;
    sf::Text headerText;
    
    sf::RectangleShape *bgFrameOutline;
    
    bool isGameInit=false;
    
    bool isGameRunning=false;
    
    std::unordered_map<std::string, sf::Sprite> drawables;
    
    
    void initHeaderText(sf::Text& headerText, sf::Font& font);
    
    void draw();
    
public:
    
    Game(const Game& obj) = delete;
    
    static Game* getInstance()
    {
        if (game == nullptr)
        {
            game = new Game();
        }
        return game;
    }
    
    sf::RenderWindow* getWindow();
    
    void initImage(sf::Texture& texture, sf::Sprite& background, std::string texName, sf::Vector2f targetSize, sf::Vector2f pos);
    
    void initGame();
    
    void runGame();
    
    void pauseGame();
    
    void muteVolume();
    
    void showNumMoves();
    
    void addToDrawables(std::string name, sf::Sprite& sp);
    
};

#endif
