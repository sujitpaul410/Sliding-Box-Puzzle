#ifndef Background_hpp
#define Background_hpp

#include <SFML/Graphics.hpp>


class Background{
    
private:
    
    sf::RenderWindow *window;
    
    sf::Sprite bgSprite;
    sf::Texture bgTexture;
    
    sf::Sprite bgFrameSprite;
    sf::Texture bgFrameTexture;
    
    sf::Font font;
    sf::Text headerText;
    
    sf::RectangleShape *bgFrameOutline;
    
    
    void initHeaderText(sf::Text& headerText, sf::Font& font);
    
    void initImage(sf::Texture& texture, sf::Sprite& background, std::string texName, sf::Vector2f targetSize, sf::Vector2f pos);
    
    
public:
    
    Background();
    
    void render(sf::RenderWindow* window);
    
};

#endif
