#include "FailScene.h"

FailScene::FailScene(int widthVal, int heightVal)
    : AbstractScene(widthVal, heightVal)
{
    background.setSize(sf::Vector2f(width, height));
    background.setFillColor(sf::Color::Black);
    background.setOutlineThickness(1);
    background.setOutlineColor(sf::Color::Red);
    initMessage();
    initButtons();
}

FailScene::~FailScene()
{}

void FailScene::render(sf::RenderWindow& window)
{
    window.draw(background);
    window.draw(message);
    window.draw(restart);
}

void FailScene::centerOrigin()
{
    background.setOrigin(width/2, height/2);
}

void FailScene::update(Registry* reg)
{
    background.setPosition(x, y);
    message.setPosition(x, y - 30);
    restart.setPosition(x, (y + (height/2) - 60));
}

void FailScene::setFont(const sf::Font& font)
{
    message.setFont(font);
    sf::FloatRect bound = message.getLocalBounds();
    message.setOrigin(bound.width/2, bound.height/2);
}

void FailScene::setButtonFont(const sf::Font& font)
{
    restart.setFont(font);
    menu.setFont(font);
    sf::FloatRect boundRst = restart.getLocalBounds();
    restart.setOrigin(boundRst.width/2, boundRst.height/2);
}

void FailScene::initMessage()
{
    message.setString("FAILED !");
    message.setCharacterSize(80);
    message.setColor(sf::Color::Red);
}

void FailScene::initButtons()
{
    restart.setString("RESTART");
    restart.setCharacterSize(40);
    restart.setColor(sf::Color::Red);
    
    menu.setString("MENU");
    menu.setCharacterSize(40);
    menu.setColor(sf::Color::Red);
}