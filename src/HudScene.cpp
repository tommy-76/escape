#include "HudScene.h"
#include "Registry.h"
#include "Asset.h"

#include <string>

HudScene::HudScene(int widthVal, int heightVal, Registry* registry)
    : AbstractScene(widthVal, heightVal, registry)
{
    background.setSize(sf::Vector2f(width, height));
    background.setFillColor(sf::Color::Black);
    background.setOutlineThickness(1);
    background.setOutlineColor(sf::Color::Green);
    initFPS();
}

HudScene::~HudScene()
{}

void HudScene::updateLayout()
{
    background.setPosition(x, y);
    float textHeight = (height/2) - 20;
    fpsValue.setPosition((width - 60), textHeight);
    fpsLabel.setPosition((fpsValue.getPosition().x - 70), textHeight);
}

void HudScene::render(sf::RenderWindow& window)
{
    window.draw(background);
    window.draw(fpsLabel);
    window.draw(fpsValue);
}

void HudScene::update()
{
    int fps = static_cast<int> (1 / reg->frameTime.asSeconds());
    fpsValue.setString(sf::String(std::to_string(fps)));
}

void HudScene::initFPS()
{
    int fontSize = 25;

    fpsLabel.setFont(reg->asset->getFont("button"));
    fpsLabel.setCharacterSize(fontSize);
    fpsLabel.setString("FPS: ");

    fpsValue.setFont(reg->asset->getFont("button"));
    fpsValue.setCharacterSize(fontSize);
    fpsValue.setString("0");
}