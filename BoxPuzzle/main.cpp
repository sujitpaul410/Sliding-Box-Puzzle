#include <SFML/Graphics.hpp>
#include <iostream>
#include "ResourcePath.hpp"

void initImage(sf::Texture& texture, sf::Sprite& background, std::string texName, sf::Vector2f targetSize, sf::Vector2f pos)
{
    if (!texture.loadFromFile(resourcePath() + texName))
    {
        std::cout << "Error loading texture" << std::endl;
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

void initHeaderText(sf::Text& headerText, sf::Font& font)
{
    if(!font.loadFromFile(resourcePath() + "SamuraiBlast.ttf"))
    {
        std::cout<<"Error loading font"<<std::endl;
        return EXIT_FAILURE;
    }
    headerText.setFont(font);
    headerText.setString("Sliding Box Puzzle");
    headerText.setCharacterSize(60);
    headerText.setFillColor(sf::Color::Yellow);
    headerText.setStyle(sf::Text::Bold);
    
    sf::FloatRect textRect = headerText.getLocalBounds();
    headerText.setOrigin(textRect.left + textRect.width/2.0f, textRect.top-15);
    headerText.setPosition(sf::Vector2f(512, 0));
    headerText.setOutlineThickness(10.0f);
}

int main(int, char const**)
{
    sf::RenderWindow window(sf::VideoMode(1024, 768), "Sliding Box-Puzzle", sf::Style::Titlebar | sf::Style::Close);
    
    sf::Sprite bgSprite;
    sf::Texture bgTexture;
    
    sf::Sprite bgFrameSprite;
    sf::Texture bgFrameTexture;
    
    sf::Sprite boardSprite;
    sf::Texture boardTexture;
    
    sf::Font font;
    sf::Text headerText;
    
    initImage(boardTexture, boardSprite, "sample.jpg", sf::Vector2f(800.0f, 600.0f), sf::Vector2f(146, 97));
    
    initImage(bgTexture, bgSprite, "wood_bg.jpg", sf::Vector2f(1024.0f, 768.0f), sf::Vector2f(0, 0));
    
    initImage(bgFrameTexture, bgFrameSprite, "wood_frame.png", sf::Vector2f(823.0f, 623.0f), sf::Vector2f(128, 75));
    sf::RectangleShape bgFrameOutline(sf::Vector2f(823, 623));
    bgFrameOutline.setFillColor(sf::Color(150, 50, 250));
    bgFrameOutline.setPosition(128, 75);
    bgFrameOutline.setOutlineThickness(3.0f);
    bgFrameOutline.setOutlineColor(sf::Color::Black);
    
    initHeaderText(headerText, font);
    
    while (window.isOpen())
    {
        sf::Event event;
        
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        
        
        window.clear(sf::Color::Black);
        window.draw(bgSprite);
        window.draw(headerText);
        window.draw(bgFrameOutline);
        window.draw(boardSprite);
        window.draw(bgFrameSprite);
        window.display();
    }
    
    return EXIT_SUCCESS;
}

