#ifndef MENUSTATE_H
#define MENUSTATE_H
#include <SFML/Graphics.hpp>
#include "../gameState.hpp"

class GameState;
class MenuState : public GameState
{
    private:
    protected:
    public:
        MenuState();
        ~MenuState();        
        
        void init();
        void update(float dt);
        void draw(sf::RenderWindow& window);
        void dispose();
};

#endif