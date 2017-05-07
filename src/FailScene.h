#ifndef FAILSCENE_H
#define FAILSCENE_H

#include "AbstractScene.h"

#include <SFML/Graphics.hpp>
#include <memory>

class TextButton;

class FailScene : public AbstractScene
{
    public:
        explicit FailScene(int widthVal, int heightVal);
        virtual ~FailScene();
        
        virtual void render(sf::RenderWindow& window);
        
        virtual void update(Registry* reg);
        
        void setFont(const sf::Font& font);
        
        void setButtonFont(const sf::Font& font);
        
        void centerOrigin();
        
        virtual void updateLayout();

    private:
        sf::RectangleShape background;
        sf::Text message;
        std::unique_ptr<TextButton> restartBtn;
        std::unique_ptr<TextButton> menuBtn;
        
        void initMessage();
        void initButtons();
};

#endif