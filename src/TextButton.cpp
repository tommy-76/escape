#include "TextButton.h"
#include "Registry.h"

TextButton::TextButton(const sf::String& label)
{
    txt.setString(label);
}

TextButton::~TextButton()
{}

void TextButton::setTextSize(int size)
{
    txt.setCharacterSize(size);
}

void TextButton::setFont(const sf::Font& font)
{
    txt.setFont(font);
}

void TextButton::setPosition(int x, int y)
{
    txt.setPosition(x, y);
}

void TextButton::setTextColor(const sf::Color& color)
{
    txt.setColor(color);
}

void TextButton::update(Registry* reg)
{
    //
}

void TextButton::render(sf::RenderWindow& window)
{
    window.draw(txt);
}