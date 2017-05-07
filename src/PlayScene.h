#ifndef PLAYSCENE_H
#define PLAYSCENE_H

#include "AbstractScene.h"

#include <SFML/Graphics.hpp>
#include <memory>

class Player;
class Registry;
class Enemy;

using EnemyListPtr = std::vector<std::shared_ptr<Enemy>>*;

class PlayScene : public AbstractScene
{
public:
    explicit PlayScene(int widthVal, int heightVal);
    virtual ~PlayScene();

    virtual void render(sf::RenderWindow& window);

    virtual void update(Registry* reg);
    
    virtual void updateLayout();

    void setPlayer(Player* playerPtr);

    void setEnemies(EnemyListPtr enemies);

private:
    sf::RectangleShape background;
    Player* player = nullptr;
    EnemyListPtr enemyList;

    void updatePlayer(Registry* reg);

    void updateEnemies(Registry* reg);

    void protectEnemiesPositions();
    
    void protectPlayerPosition();
    
    void playerCollisionDetection(Registry* reg);

    void renderEnemies(sf::RenderWindow& window);
};

#endif