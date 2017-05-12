#include "testState.hpp"
#include <SFML/Graphics.hpp>


void TestState::init()
{
    this->circle.setRadius(50);
}

void TestState::update(float dt)
{
    
}

void TestState::draw(sf::RenderWindow& window)
{
    window.draw(this->circle);   
}

void TestState::dispose()
{
    
}