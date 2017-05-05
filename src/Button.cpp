#include "Button.h"

Button::Button(int widthVal, int heightVal, const sf::String& labelStr)
    : width(widthVal), height(heightVal)
{
    label.setString(labelStr);
    label.setColor(sf::Color::Blue);
    initShape();
}

Button::~Button()
{}

void Button::centerOrigin()
{
    shape.setOrigin(width/2, height/2);
}

void Button::setPosition(int xVal, int yVal)
{
    shape.setPosition(xVal, yVal);
    // @todo set label position
}

int Button::getWidth()
{
    return width;
}

int Button::getHeight()
{
    return height;
}

void Button::setFont(const sf::Font& font)
{
    label.setFont(font);
}

void Button::render(sf::RenderWindow& window)
{
    window.draw(shape);
}

void Button::initShape()
{
    shape.setSize(sf::Vector2f(width, height));
    shape.setFillColor(sf::Color::Yellow);
    shape.setOutlineColor(sf::Color::Blue);
    shape.setOutlineThickness(1);
}