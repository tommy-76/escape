#ifndef TEXTBUTTON_H
#define TEXTBUTTON_H

#include <SFML/Graphics.hpp>

class Registry;

class TextButton
{
    public:
        explicit TextButton(const sf::String& label);
        ~TextButton();
        
        void setTextSize(int size);
        
        void setFont(const sf::Font& font);
        
        void setPosition(int x, int y);
        
        void setTextColor(const sf::Color& color);
        
        void update(Registry* reg);
        
        void render(sf::RenderWindow& window);
    
    private:
        sf::Text txt;
};

#endif