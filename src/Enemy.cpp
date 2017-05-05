#include "Enemy.h"

Enemy::Enemy()
{}

Enemy::~Enemy()
{}

sf::Vector2f& Enemy::getPosition()
{
    return position;
}

void Enemy::setPosition(float xVal, float yVal)
{
    position.x = xVal;
    position.y = yVal;
    shape.setPosition(position);
}

void Enemy::setSize(int sizeInp)
{
    size = sizeInp;
    shape.setRadius(size);
}

int Enemy::getSize()
{
    return size;
}

sf::CircleShape& Enemy::getShape()
{
    return shape;
}

void Enemy::centerOrigin()
{
    shape.setOrigin(size, size);
}

void Enemy::setColor(sf::Color colorVal)
{
    shape.setFillColor(colorVal);
}

void Enemy::setTexture(const sf::Texture& tex)
{
    shape.setTexture(&tex);
}

void Enemy::updateView()
{
    shape.setPosition(position);
}

void Enemy::render(sf::RenderWindow& window)
{
    window.draw(shape);
}
