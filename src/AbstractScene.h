#ifndef ABSTRACTSCENE_H
#define ABSTRACTSCENE_H

#include <SFML/Graphics.hpp>

class Registry;

class AbstractScene
{
public:

    explicit AbstractScene(int widthVal, int heightVal);
    AbstractScene(const AbstractScene& src) = delete;
    virtual ~AbstractScene();

    virtual void setPosition(int xVal, int yVal);

    virtual void render(sf::RenderWindow& window) = 0;

    virtual void update(Registry* reg) = 0;

protected:
    int x;
    int y;
    int width;
    int height;
    int xMin;
    int yMin;
    int xMax;
    int yMax;

    virtual void protectItemPosition(sf::Vector2f& pos, int xMargin = 0, int yMargin = 0);
};

#endif