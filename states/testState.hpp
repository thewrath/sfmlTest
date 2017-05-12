#ifndef TESTSTATE_H
#define TESTSTATE_H
#include <SFML/Graphics.hpp>
#include "../gameState.hpp"

class GameState;
class TestState : public GameState
{
    private:
        sf::CircleShape circle;
    protected:
    public:
        void init();
        void update(float dt);
        void draw(sf::RenderWindow& window);
        void dispose();
};

#endif