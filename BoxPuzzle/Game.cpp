#include "Game.hpp"

Game::Game()
{
    m_window=Window::getInstance();
    m_background=new Background();
    m_board=new Board();
}

Game::~Game(){}


Window* Game::getWindow()
{
    return m_window;
}

void Game::handleInput()
{
    // Input handling.
}

void Game::update()
{
    m_window->update();
}

void Game::render()
{
    m_window->beginDraw();
    
    m_background->render(m_window->getRenderWindow());
    m_board->render(m_window->getRenderWindow());
    
    m_window->endDraw();
}

