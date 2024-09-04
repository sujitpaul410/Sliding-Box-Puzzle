#include "Window.hpp"

Window* Window::window=nullptr;

Window::Window(sf::VideoMode videoMode, const std::string title, int titleBar=(sf::Style::Titlebar | sf::Style::Close))
{
    m_renderWindow=new sf::RenderWindow(videoMode, title);
    m_isDone=false;
}

Window::~Window()
{
    m_renderWindow->close();
}

void Window::beginDraw()
{
    m_renderWindow->clear(sf::Color::Black);
}

void Window::endDraw()
{
    m_renderWindow->display();
}

bool Window::isDone()
{
    return m_isDone;
}

sf::RenderWindow* Window::getRenderWindow()
{
    return m_renderWindow;
}


void Window::update()
{
    sf::Event event;
    while(m_renderWindow->pollEvent(event))
    {
        if(event.type == sf::Event::Closed)
        {
            m_isDone=true;
        }
        else if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
        {
            m_isDone=true;
            
        }
    }
}
