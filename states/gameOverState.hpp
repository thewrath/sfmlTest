#ifndef GAMEOVERSTATE_H
#define GAMEOVERSTATE_H
#include <SFML/Graphics.hpp>
#include "../gameState.hpp"

class GameState;
class GameOverState : public GameState
{
    private:
    protected:
    public:
        GameOverState();
        ~GameOverState();
        
        void init();
        void update(float dt);
        void draw(sf::RenderWindow& window);
        void dispose();
};

#endif