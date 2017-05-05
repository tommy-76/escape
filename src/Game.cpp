#include "Game.h"
#include "Registry.h"
#include "Logger.h"
#include "Asset.h"
#include "PlayScene.h"
#include "FailScene.h"
#include "Enemy.h"
#include "Randomizer.h"

#include <SFML/Graphics/Color.hpp>

Game::Game(Registry* regPtr) : state(Game::State::PLAY), reg(regPtr)
{}

Game::~Game()
{}

void Game::initialize()
{
    initPlayer();
    initEnemies();
    initFailScene();
    initPlayScene();
    playScene->setPlayer(&player);
    playScene->setEnemies(&enemyList);
}

void Game::update()
{
    switch (state) {
        case Game::State::MENU:
            break;
        case Game::State::PLAY:
            playUpdate();
            break;
        case Game::State::FAIL:
            break;
        case Game::State::WIN:
            break;
    }
}

void Game::render(sf::RenderWindow& window)
{
    switch (state) {
        case Game::State::MENU:
            break;
        case Game::State::PLAY:
            playScene->render(window);
            if (reg->playerCollision) {
                failScene->render(window);
            }
            break;
        case Game::State::FAIL:
            break;
        case Game::State::WIN:
            break;
    }
}

void Game::playUpdate()
{
    playScene->update(reg);
    if (reg->playerCollision) {
        failScene->update(reg);
    }
}

void Game::onClose()
{
    reg->log->info("On close");
}

void Game::initPlayer()
{
    player.setSize(16);
    player.setTexture(reg->asset->getTexture("bubble"));
    player.centerOrigin();
    player.setPosition(30, 30);
    reg->log->info("Player init");
}

void Game::initEnemies()
{
    for (int i = 0; i < 4; ++i) {
        std::shared_ptr<Enemy> enemy = std::make_shared<Enemy>();
        enemy->setSize(25);
        enemy->setTexture(reg->asset->getTexture("sponge"));
        enemy->centerOrigin();
        enemy->setPosition(reg->randomizer->getRandomInt(100, 500), reg->randomizer->getRandomInt(100, 450));
        enemyList.push_back(enemy);
    }

    reg->log->info("Enemy init");
}

void Game::initPlayScene()
{
    playScene.reset(new PlayScene(790, 520));
    playScene->setPosition(5, 75);
    reg->log->info("Play scene init");
}

void Game::initFailScene()
{
    failScene.reset(new FailScene(300, 250));
    failScene->setFont(reg->asset->getFont("main"));
    failScene->setButtonFont(reg->asset->getFont("button"));
    failScene->centerOrigin();
    failScene->setPosition(reg->screenWidth/2, reg->screenHeight/2);
    reg->log->info("Fail scene init");
}
