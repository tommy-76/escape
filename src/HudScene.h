#ifndef HUDSCENE_H
#define HUDSCENE_H

#include "AbstractScene.h"

class Registry;

class HudScene : public AbstractScene
{
    public:
        explicit HudScene(int widthVal, int heightVal, Registry* registry);
        virtual ~HudScene();

        virtual void updateLayout();

        virtual void render(sf::RenderWindow& window);

        virtual void update();

    private:
        sf::RectangleShape background;
        sf::Text fpsLabel;
        sf::Text fpsValue;

        void initFPS();
};

#endif