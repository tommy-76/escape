#include "TextButton.h"
#include "Registry.h"
#include "InputDevice.h"

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
    txtColor = &color;
}

void TextButton::setTextHoverColor(const sf::Color& color)
{
    hoverTxtColor = &color;
}

void TextButton::update(Registry* reg)
{
    sf::Vector2i mousePos = reg->inputDevice->getMousePosition();
    sf::FloatRect border = txt.getGlobalBounds();
    if (border.contains(mousePos.x, mousePos.y)) {
        txt.setColor(*hoverTxtColor);
    } else {
        txt.setColor(*txtColor);
    }
}

void TextButton::render(sf::RenderWindow& window)
{
    window.draw(txt);
}