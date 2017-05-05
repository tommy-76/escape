#include "AbstractScene.h"

AbstractScene::AbstractScene(int widthVal, int heightVal)
    : width(widthVal), height(heightVal)
{}

AbstractScene::~AbstractScene()
{}

void AbstractScene::setPosition(int xVal, int yVal)
{
    x = xVal;
    y = yVal;
    xMin = x;
    yMin = y;
    xMax = x + width;
    yMax = y + height;
}

void AbstractScene::protectItemPosition(sf::Vector2f& pos, int xMargin, int yMargin)
{
    int xMinMod = xMin + xMargin;
    int yMinMod = yMin + yMargin;
    int xMaxMod = xMax - xMargin;
    int yMaxMod = yMax - yMargin;

    if (xMinMod > pos.x) {
        pos.x = xMinMod;
    }
    if (xMaxMod < pos.x) {
        pos.x = xMaxMod;
    }
    if (yMinMod > pos.y) {
        pos.y = yMinMod;
    }
    if (yMaxMod < pos.y) {
        pos.y = yMaxMod;
    }
}