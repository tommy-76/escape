#include "FailScene.h"
#include "TextButton.h"

FailScene::FailScene(int widthVal, int heightVal, Registry* registry)
    : AbstractScene(widthVal, heightVal, registry)
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
    restartBtn->render(window);
    menuBtn->render(window);
}

void FailScene::centerOrigin()
{
    background.setOrigin(width/2, height/2);
}

void FailScene::update()
{
    restartBtn->update(reg);
    menuBtn->update(reg);
}

void FailScene::updateLayout()
{
    background.setPosition(x, y);
    message.setPosition(x, y - 30);
    float leftX = x - (width/2);
    float bottomY = y + (height/2);
    float rightX = x + (width/2);
    restartBtn->setPosition((leftX + 15), (bottomY - 50));
    menuBtn->setPosition((rightX - 80), (bottomY - 50));
}

void FailScene::setFont(const sf::Font& font)
{
    message.setFont(font);
    sf::FloatRect bound = message.getLocalBounds();
    message.setOrigin(bound.width/2, bound.height/2);
}

void FailScene::setButtonFont(const sf::Font& font)
{
    restartBtn->setFont(font);
    menuBtn->setFont(font);
}

void FailScene::initMessage()
{
    message.setString("FAILED !");
    message.setCharacterSize(80);
    message.setColor(sf::Color::Red);
}

void FailScene::initButtons()
{
    restartBtn.reset(new TextButton("RESTART"));
    restartBtn->setTextSize(30);
    restartBtn->setTextColor(sf::Color::Red);
    restartBtn->setTextHoverColor(sf::Color::Yellow);
    
    menuBtn.reset(new TextButton("MENU"));
    menuBtn->setTextSize(30);
    menuBtn->setTextColor(sf::Color::Red);
    menuBtn->setTextHoverColor(sf::Color::Yellow);
}