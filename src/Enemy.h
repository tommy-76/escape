#ifndef ENEMY_H
#define ENEMY_H

#include <SFML/Graphics.hpp>

class Enemy
{
    public:
        Enemy();
        Enemy(const Enemy& src) = delete;
        ~Enemy();

        sf::Vector2f& getPosition();

        void setPosition(float xVal, float yVal);

        void setSize(int size);

        int getSize();
        
        sf::CircleShape& getShape();

        void centerOrigin();

        void setColor(sf::Color colorVal);

        void setTexture(const sf::Texture& tex);
        
        void updateView();

        void render(sf::RenderWindow& window);

    private:
        sf::Vector2f position;
        sf::CircleShape shape;
        int size;
};

#endif