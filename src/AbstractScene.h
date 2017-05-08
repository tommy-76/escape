#ifndef ABSTRACTSCENE_H
#define ABSTRACTSCENE_H

#include <SFML/Graphics.hpp>

class Registry;

class AbstractScene
{
public:

    explicit AbstractScene(int widthVal, int heightVal, Registry* registry);
    AbstractScene(const AbstractScene& src) = delete;
    virtual ~AbstractScene();

    virtual void setPosition(int xVal, int yVal);
    
    virtual void updateLayout();

    virtual void render(sf::RenderWindow& window) = 0;

    virtual void update() = 0;

protected:
    int x;
    int y;
    int width;
    int height;
    int xMin;
    int yMin;
    int xMax;
    int yMax;
    Registry* reg;

    virtual void protectItemPosition(sf::Vector2f& pos, int xMargin = 0, int yMargin = 0);
};

#endif