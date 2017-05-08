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
    explicit PlayScene(int widthVal, int heightVal, Registry* registry);
    virtual ~PlayScene();

    virtual void render(sf::RenderWindow& window);

    virtual void update();
    
    virtual void updateLayout();

    void setPlayer(Player* playerPtr);

    void setEnemies(EnemyListPtr enemies);

private:
    sf::RectangleShape background;
    Player* player = nullptr;
    EnemyListPtr enemyList;

    void updatePlayer();

    void updateEnemies();

    void protectEnemiesPositions();
    
    void protectPlayerPosition();
    
    void playerCollisionDetection();

    void renderEnemies(sf::RenderWindow& window);
};

#endif