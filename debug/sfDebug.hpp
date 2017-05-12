#ifndef SFDEBUG_H
#define SFDEBUG_H

#include <iostream>
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>

using namespace std;

class sfDebug
{
    private:
        vector<string> textToDebug;
        int textToDebugLength;
        sf::Text debugText;
        sf::Font debugFont;
    protected:
    
    public:
        sfDebug();
        ~sfDebug();
        void draw(sf::RenderWindow& window);
        void addText(string text);
        friend ostream& operator<< (ostream& out, sfDebug & o);
      
};

#endif