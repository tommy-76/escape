#ifndef COLLIDER_H
#define COLLIDER_H

#include <SFML/Graphics/CircleShape.hpp>

namespace gp
{
    
class Collider
{
    public:
        Collider();
        ~Collider();
        
        bool checkCirclesCollision(sf::CircleShape& itemA, sf::CircleShape& itemB);
};

}

#endif