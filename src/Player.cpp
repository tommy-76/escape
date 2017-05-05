#include "Player.h"

Player::Player()
{
}

Player::~Player()
{}

sf::Vector2f& Player::getPosition()
{
    return position;
}

void Player::setPosition(float xVal, float yVal)
{
    position.x = xVal;
    position.y = yVal;
    shape.setPosition(position);
}

void Player::setTexture(const sf::Texture& tex)
{
    shape.setTexture(&tex);
}

void Player::setColor(sf::Color colorVal)
{
    shape.setFillColor(colorVal);
}

void Player::setSize(int sizeInp)
{
    size = sizeInp;
    shape.setRadius(size);
}

int Player::getSize()
{
    return size;
}

sf::CircleShape& Player::getShape()
{
    return shape;
}

void Player::centerOrigin()
{
    shape.setOrigin(size, size);
}

void Player::updateView()
{
    shape.setPosition(position);
}

void Player::render(sf::RenderWindow& window)
{
    window.draw(shape);
}
