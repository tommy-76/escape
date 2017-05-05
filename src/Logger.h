#ifndef ES_LOGGER
#define ES_LOGGER

#include <string>
#include <SFML/System/Vector2.hpp>

class Logger
{
public:
    Logger();
    ~Logger();

    void info(const std::string& message);
    void info(const sf::Vector2i& pos);
    void info(const sf::Vector2f& pos);

private:
    void printTime();
};

#endif