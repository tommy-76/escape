#include "PlayScene.h"
#include "Player.h"
#include "Registry.h"
#include "InputDevice.h"
#include "Enemy.h"
#include "Logger.h"

PlayScene::PlayScene(int widthVal, int heightVal)
    : AbstractScene(widthVal, heightVal)
{
    background.setSize(sf::Vector2f(width, height));
    background.setFillColor(sf::Color::Black);
    background.setOutlineThickness(1);
    background.setOutlineColor(sf::Color::Yellow);
}

PlayScene::~PlayScene()
{}

void PlayScene::update(Registry* reg)
{
    if (!reg->playerCollision) {
        updatePlayer(reg);
        updateEnemies(reg);
        protectPlayerPosition();
        protectEnemiesPositions();
    }
}

void PlayScene::updateLayout()
{
    background.setPosition(x, y);
}

void PlayScene::render(sf::RenderWindow& window)
{
    window.draw(background);
    renderEnemies(window);
    player->render(window);
}

void PlayScene::setPlayer(Player* playerPtr)
{
    player = playerPtr;
}

void PlayScene::setEnemies(EnemyListPtr enemies)
{
    enemyList = enemies;
}

void PlayScene::updatePlayer(Registry* reg)
{
    if (!reg->inputDevice->isLeftMousePressed()) {
        return;
    }
    float frameSec = reg->frameTime.asSeconds();
    sf::Vector2f& playerPos = player->getPosition();
    sf::Vector2i& mousePos = reg->inputDevice->getMousePosition();

    float xDiff = (mousePos.x - playerPos.x) * frameSec;
    float yDiff = (mousePos.y - playerPos.y) * frameSec;
    playerPos.x += xDiff;
    playerPos.y += yDiff;
}

void PlayScene::updateEnemies(Registry* reg)
{
    protectEnemiesPositions();
    playerCollisionDetection(reg);
}

void PlayScene::renderEnemies(sf::RenderWindow& window)
{
    for (auto enemyPtr : *enemyList) {
        enemyPtr->render(window);
    }
}

void PlayScene::protectEnemiesPositions()
{
    for (auto enemyPtr : *enemyList) {
        int margin = enemyPtr->getSize();
        protectItemPosition(enemyPtr->getPosition(), margin, margin);
        enemyPtr->updateView();
    }
}

void PlayScene::protectPlayerPosition()
{
    int margin = player->getSize();
    protectItemPosition(player->getPosition(), margin, margin);
    player->updateView();
}

void PlayScene::playerCollisionDetection(Registry* reg)
{
    sf::Vector2f& playerPos = player->getPosition();
    for (auto enemyPtr : *enemyList) {
        sf::Vector2f& enemyPos = enemyPtr->getPosition();
        if (reg->collider->checkCirclesCollision(player->getShape(), enemyPtr->getShape())) {
            reg->playerCollision = true;
            break;
        }
    }
}