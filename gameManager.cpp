#include "gameManager.hpp"
#include "gameState.hpp"
#include "states/loaderState.hpp"
#include "debug/sfDebug.hpp"
#include <iostream>

GameManager& GameManager::getInstance()
{
    static GameManager gameManager;
    return gameManager;
}


GameManager::GameManager()
{
    
}

GameManager::~GameManager()
{
    
}

void GameManager::start()
{
    this->running = this->init();
    this->update();
    this->dispose();
}

bool GameManager::init()
{
    this->window.create(sf::VideoMode(800, 600), "SFML works!");
    this->pushState(this->loaderState);
    this->debug.addText(this->states.top()->getName());\
    return true;
}

void GameManager::update()
{
    while (this->running)
    {
       
        this->catchEvents();
        this->draw();
    }
}

void GameManager::catchEvents()
{
    sf::Event event;
    while (this->window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            this->running = false;
    }
}

void GameManager::draw()
{
    this->window.clear();
    this->states.top()->draw(this->window);
    this->drawDebug();
    this->window.display();
}

void GameManager::drawDebug()
{
    
    this->debug.draw(this->window);
}

void GameManager::dispose()
{
    
}

void GameManager::pushState(GameState& state)
{
    state.setGameManager(this);
    this->states.push(&state);
    this->states.top()->init();
}

void GameManager::setState(GameState& state)
{
    state.setGameManager(this);
    this->popState();
    this->pushState(state);
    
}

void GameManager::popState()
{
    if(!this->states.empty()){
        this->states.top()->dispose();
        this->states.pop();
    }
}

