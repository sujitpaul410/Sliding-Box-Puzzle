#include <iostream>
#include "ResourcePath.hpp"
#include "Background.hpp"


Background::Background()
{
    initImage(bgTexture, bgSprite, "wood_bg.jpg", sf::Vector2f(1024.0f, 768.0f), sf::Vector2f(0, 0));
    
    initImage(bgFrameTexture, bgFrameSprite, "wood_frame.png", sf::Vector2f(823.0f, 623.0f), sf::Vector2f(128, 75));
    
    bgFrameOutline=new sf::RectangleShape(sf::Vector2f(823, 623));
    bgFrameOutline->setFillColor(sf::Color(150, 50, 250));
    bgFrameOutline->setPosition(128, 75);
    bgFrameOutline->setOutlineThickness(3.0f);
    bgFrameOutline->setOutlineColor(sf::Color::Black);
    
    initHeaderText(headerText, font);
}

//Background::~Background(){}

void Background::initImage(sf::Texture& texture, sf::Sprite& background, std::string texName, sf::Vector2f targetSize, sf::Vector2f pos)
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


void Background::initHeaderText(sf::Text& headerText, sf::Font& font)
{
    if(!font.loadFromFile(resourcePath() + "SamuraiBlast.ttf"))
    {
        std::cout<<"Error loading font "<<std::endl;
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


void Background::render(sf::RenderWindow* window)
{
    window->draw(bgSprite);
    window->draw((*bgFrameOutline));
    window->draw(bgFrameSprite);
    window->draw(headerText);
}
