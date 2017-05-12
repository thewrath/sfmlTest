#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <string>
#include <SFML/Graphics.hpp>

class GameManager;
class GameState
{
    private:
        
    protected:
        GameManager* gameManager;
        std::string name = "none";
    public:
        virtual void init() = 0;
        virtual void update(float dt) = 0;
        virtual void draw(sf::RenderWindow& window) = 0;
        virtual void dispose() = 0;
        void setGameManager(GameManager* gameManager){this->gameManager = gameManager; }
        std::string getName(){ return this->name; }
        void setName(std::string name) {this->name = name; }
};

#endif