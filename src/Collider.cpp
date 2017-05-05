#include "Collider.h"

namespace gp
{

Collider::Collider()
{}

Collider::~Collider()
{}

bool Collider::checkCirclesCollision(sf::CircleShape& itemA, sf::CircleShape& itemB)
{
    float originDistance = 0;

    float xA = itemA.getPosition().x;
    float yA = itemA.getPosition().y;

    float xB = itemB.getPosition().x;
    float yB = itemB.getPosition().y;

    float radiusA = itemA.getRadius();
    float radiusB = itemB.getRadius();

    originDistance = sqrt((pow((xB - xA), 2) + pow((yB - yA), 2)));

    if ((radiusA + radiusB) >= originDistance) {
        return true;
    }

    return false;
}

}