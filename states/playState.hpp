#ifndef PLAYSTATE_H
#define PLAYSTATE_H
#include <SFML/Graphics.hpp>
#include "../gameState.hpp"

class GameState;
class PlayState : public GameState
{
    private:
    protected:
    public:
        PlayState();
        ~PlayState();
        
        void init();
        void update(float dt);
        void draw(sf::RenderWindow& window);
        void dispose();
};

#endif