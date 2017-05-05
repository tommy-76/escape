#ifndef REGISTRY_H
#define REGISTRY_H

#include <string>
#include <SFML/System/Time.hpp>

#include "Collider.h"

class Logger;
class InputDevice;
class Asset;
class Randomizer;

struct Registry
{
	int screenWidth = 800;
	int screenHeight = 600;
	
	int frameLimit = 60;
    
    bool playerCollision = false;
	
	std::string title;
	
	sf::Time frameTime;
    
    Logger* log = nullptr;
    InputDevice* inputDevice = nullptr;
    Asset* asset = nullptr;
    Randomizer* randomizer = nullptr;
    gp::Collider* collider = nullptr;
};

#endif