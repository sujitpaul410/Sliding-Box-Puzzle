#ifndef Game_hpp
#define Game_hpp

#include "Window.hpp"
#include "Background.hpp"
#include "Board.hpp"

class Game{
    
public:
    
    Game();
    
    ~Game();

    void handleInput();
    
    void update();
    
    void render();

    Window* getWindow();
    
    
private:
    
    Window* m_window;
    
    Background* m_background;
    Board* m_board;
    
    float m_elapsed;

};

#endif
