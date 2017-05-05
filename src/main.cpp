#include "Registry.h"
#include "Logger.h"
#include "InputDevice.h"
#include "Asset.h"
#include "Randomizer.h"
#include "Game.h"
#include "Collider.h"

#include <SFML/Graphics.hpp>

int main()
{
    Logger log;
    InputDevice device;
    Asset asset;
    Randomizer randomizer;
    gp::Collider collider;

    // Load assets
    asset.loadTexture("bubble", "img/bubble32x31.png");
    asset.loadTexture("sponge", "img/sponge_bob50x50.png");
    asset.loadFont("main", "font/cf.ttf");
    asset.loadFont("button", "font/elite.ttf");
    
	Registry reg;
	reg.title = "Escape";
    reg.log = &log;
    reg.inputDevice = &device;
    reg.asset = &asset;
    reg.randomizer = &randomizer;
    reg.collider = &collider;
    
    Game game(&reg);
	
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
	sf::RenderWindow window(sf::VideoMode(reg.screenWidth, reg.screenHeight), reg.title, sf::Style::Close, settings);
    window.setFramerateLimit(reg.frameLimit);
	
	sf::Event event;
	sf::Clock clock;
    game.initialize();

	// Main loop
	while (window.isOpen()) {
		reg.frameTime = clock.restart();
        device.readMouse(window);
        while (window.pollEvent(event)) {
            if (sf::Event::Closed == event.type) {
                game.onClose();
                window.close();
            }
        }
        game.update();
        window.clear(sf::Color::Black);
        game.render(window);
        window.display();
	}
	
	return 0;
}