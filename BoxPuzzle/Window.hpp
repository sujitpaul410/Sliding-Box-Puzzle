#ifndef Window_hpp
#define Window_hpp

#include <string>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>



class Window{
    
public:
    
    Window(const Window& obj)=delete;
    
    static Window* getInstance()
    {
        if(window==nullptr)
        {
            window=new Window(sf::VideoMode(1024, 768), "Sliding Box-Puzzle", sf::Style::Titlebar | sf::Style::Close);
        }
        
        return window;
    }
    
    ~Window();

    void beginDraw();
    void endDraw();

    void update();

    bool isDone();
    
    sf::RenderWindow* getRenderWindow();

    void draw(sf::Drawable& drawable);
    
    
    
private:

    sf::RenderWindow* m_renderWindow;
    
    static Window* window;
    
    Window() {}
    
    Window(sf::VideoMode videoMode, const std::string title, int titleBar);
    
    bool m_isDone;
};

#endif
