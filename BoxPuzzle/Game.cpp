#include "Game.hpp"


Game* Game::game=nullptr;


void Game::initImage(sf::Texture& texture, sf::Sprite& background, std::string texName, sf::Vector2f targetSize, sf::Vector2f pos)
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


void Game::initHeaderText(sf::Text& headerText, sf::Font& font)
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


void Game::initGame()
{
    if(isGameInit)
    {
        std::cout<<"Game already init."<<std::endl;
        return;
    }
    
    initImage(bgTexture, bgSprite, "wood_bg.jpg", sf::Vector2f(1024.0f, 768.0f), sf::Vector2f(0, 0));
    
    initImage(bgFrameTexture, bgFrameSprite, "wood_frame.png", sf::Vector2f(823.0f, 623.0f), sf::Vector2f(128, 75));
    
    bgFrameOutline=new sf::RectangleShape(sf::Vector2f(823, 623));
    bgFrameOutline->setFillColor(sf::Color(150, 50, 250));
    bgFrameOutline->setPosition(128, 75);
    bgFrameOutline->setOutlineThickness(3.0f);
    bgFrameOutline->setOutlineColor(sf::Color::Black);
    
    initHeaderText(headerText, font);
    
    window=new sf::RenderWindow(sf::VideoMode(1024, 768), "Sliding Box-Puzzle", sf::Style::Titlebar | sf::Style::Close);
    
    isGameInit=true;
    std::cout<<"Game init."<<std::endl;
}

void Game::runGame()
{
    if(!isGameInit)
    {
        initGame();
        runGame();
    }
    
    
    else
    {
        if(isGameRunning)
        {
            std::cout<<"Game already running."<<std::endl;
            return;
        }
        
        std::cout<<"Game starts running."<<std::endl;
        isGameRunning=true;
        
        while (window->isOpen())
        {
            sf::Event event;
            
            while (window->pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window->close();
            }
            
            
            window->clear(sf::Color::Black);
            window->draw(bgSprite);
            window->draw(headerText);
            window->draw(*bgFrameOutline);
            window->draw(bgFrameSprite);
            
            draw();
            
            window->display();
        }
        
        
    }
}

sf::RenderWindow* Game::getWindow()
{
    if (!isGameRunning)
    {
        std::cout<<"Game is not running yet"<<std::endl;
        return;
    }
    
    
    return window;
}

void Game::draw()
{
    std::cout<<"drawing extra: "<<drawables.size()<<std::endl;
    for(auto item:drawables)
    {
        window->draw(item.second);
    }
}

void Game::addToDrawables(std::string name, sf::Sprite& sp)
{
    if(drawables.find(name)!=drawables.end())
    {
        std::cout<<"Drawable item with the same name exists"<<std::endl;
        return;;
    }
    
    std::cout<<"drawable pushed"<<std::endl;
    drawables[name]=sp;
    
}


