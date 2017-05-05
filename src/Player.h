#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>

class Player 
{
public:
    Player();
    Player(const Player& orig) = delete;
    virtual ~Player();

    sf::Vector2f& getPosition();

    void setPosition(float xVal, float yVal);

    void setTexture(const sf::Texture& tex);
    
    void setSize(int size);

    int getSize();
    
    sf::CircleShape& getShape();
    
    void centerOrigin();
    
    void setColor(sf::Color colorVal);
    
    void updateView();

    void render(sf::RenderWindow& window);

private:
    sf::Vector2f position;
    sf::CircleShape shape;
    int size;

};

#endif /* PLAYER_H */

