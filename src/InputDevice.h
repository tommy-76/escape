#ifndef INPUTDEVICE_H
#define INPUTDEVICE_H

#include <SFML/Window/Mouse.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

class InputDevice
{
public:
    InputDevice();
    ~InputDevice();

    void readMouse(sf::RenderWindow& window);
    sf::Vector2i& getMousePosition();
    bool isLeftMousePressed();

private:
    sf::Vector2i mousePosition;
    bool leftMousePressed;
};

#endif