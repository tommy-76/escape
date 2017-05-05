#ifndef BUTTON_H
#define BUTTON_H

#include <SFML/Graphics.hpp>

class Button
{
    public:
        explicit Button(int widthVal, int heightVal, const sf::String& labelStr);
        Button(const Button& src) = delete;
        ~Button();
        
        void centerOrigin();
        
        void setPosition(int xVal, int yVal);
        
        void setFont(const sf::Font& font);
        
        int getWidth();
        
        int getHeight();
        
        void render(sf::RenderWindow& window);
    
    private:
        int width;
        int height;
        sf::Text label;
        sf::RectangleShape shape;
        
        void initShape();
};

#endif