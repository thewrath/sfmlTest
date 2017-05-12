#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "states/loaderState.hpp"
#include "debug/sfDebug.hpp"
#include <SFML/Graphics.hpp>
#include <stack>

class GameState;
class LoaderState;
class sfDebug;
class GameManager
{
    private:
        GameManager();
        std::stack<GameState*> states;
        sf::RenderWindow window;
        bool running;
        bool init();
        void update();
        void catchEvents();
        void draw();
        void drawDebug();
        void dispose();
        
        LoaderState loaderState;
        sfDebug debug;
    protected:
        
    public:
        static GameManager& getInstance();
        ~GameManager();
        
        void start();
        
        GameState* getCurrentState(){ return (!this->states.empty()) ? this->states.top() : nullptr; }
        void pushState(GameState& state);
        void setState(GameState& state);
        void popState();
        
};

#endif