#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics/RenderWindow.hpp>
#include <memory>
#include <vector>

#include "Player.h"

class Registry;
class PlayScene;
class FailScene;
class HudScene;
class Enemy;

using EnemyPtrList = std::vector<std::shared_ptr<Enemy>>;

class Game
{
    public:
        explicit Game(Registry* regPtr);
        Game(const Game& src) = delete;
        ~Game();
        
        void initialize();
        
        void update();
        
        void render(sf::RenderWindow& window);
        
        void onClose();
        
    private:
        
        enum class State {MENU, PLAY, FAIL, WIN};
        
        Game::State state;
        Player player;
        Registry* reg = nullptr;

        std::unique_ptr<PlayScene> playScene;
        std::unique_ptr<FailScene> failScene;
        std::unique_ptr<HudScene> hudScene;
        EnemyPtrList enemyList;
        
        void initPlayer();
        void initEnemies();
        void initPlayScene();
        void initFailScene();
        void initHudScene();
        
        void playUpdate();
};

#endif