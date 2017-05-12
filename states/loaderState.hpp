#ifndef LOADERSTATE_H
#define LOADERSTATE_H
#include <SFML/Graphics.hpp>
#include "../gameState.hpp"

class GameState;
class LoaderState : public GameState
{
    private:
    protected:
    public:
        LoaderState();
        ~LoaderState();
        
        void init();
        void update(float dt);
        void draw(sf::RenderWindow& window);
        void dispose();
};

#endif