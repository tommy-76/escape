#include "PlayScene.h"
#include "Player.h"
#include "Registry.h"
#include "InputDevice.h"
#include "Enemy.h"
#include "Logger.h"

PlayScene::PlayScene(int widthVal, int heightVal, Registry* registry)
    : AbstractScene(widthVal, heightVal, registry)
{
    background.setSize(sf::Vector2f(width, height));
    background.setFillColor(sf::Color::Black);
}

PlayScene::~PlayScene()
{}

void PlayScene::update()
{
    if (!reg->playerCollision) {
        updatePlayer();
        updateEnemies();
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

void PlayScene::updatePlayer()
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

void PlayScene::updateEnemies()
{
    protectEnemiesPositions();
    playerCollisionDetection();
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

void PlayScene::playerCollisionDetection()
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