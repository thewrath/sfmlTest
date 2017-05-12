#include "sfDebug.hpp"
#include "../utils/utils.hpp"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

sfDebug::sfDebug()
{
    this->textToDebugLength = 0;
    if (!this->debugFont.loadFromFile("/home/thomas/Desktop/code/cpp/sfmlTest/res/arial.ttf"))
    {
        cout << "Can't loading font" << endl;
    }
    this->debugText.setPosition(50,50);
    this->debugText.setFont(this->debugFont);
    this->debugText.setCharacterSize(24);
    this->debugText.setColor(sf::Color::Green);
    
    this->addText("Debug true");
}

sfDebug::~sfDebug()
{
    
}

void sfDebug::draw(sf::RenderWindow& window)
{
    for(string text : this->textToDebug)
    {
            debugText.setString(text);
            window.draw(this->debugText);
            debugText.setPosition(debugText.getPosition().x, debugText.getPosition().y+debugText.getCharacterSize());
    }
    
    debugText.setPosition(debugText.getPosition().x, debugText.getPosition().y-debugText.getCharacterSize()*this->textToDebug.size());

}

void sfDebug::addText(string text)
{
    this->textToDebug.push_back(text);
    this->textToDebugLength++;
}

ostream& operator<< (ostream& out, sfDebug& o)
{
    if(DEBUG)
    {
        for(string text : o.textToDebug)
        {
            out << text << endl;
        }
    }
}