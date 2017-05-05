#include "InputDevice.h"

InputDevice::InputDevice()
{}

InputDevice::~InputDevice()
{}

void InputDevice::readMouse(sf::RenderWindow& window)
{
    mousePosition = sf::Mouse::getPosition(window);
    leftMousePressed = sf::Mouse::isButtonPressed(sf::Mouse::Left);
}

sf::Vector2i& InputDevice::getMousePosition()
{
    return mousePosition;
}

bool InputDevice::isLeftMousePressed()
{
    return leftMousePressed;
}