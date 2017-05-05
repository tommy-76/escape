#include "Logger.h"

#include <iostream>
#include <ctime>

Logger::Logger()
{
}

Logger::~Logger()
{}

void Logger::info(const std::string& message)
{
    printTime();
    std::cout << message << std::endl;
}

void Logger::info(const sf::Vector2i& pos)
{
    printTime();
    std::cout << "x=" << pos.x << ", y=" << pos.y << std::endl;
}

void Logger::info(const sf::Vector2f& pos)
{
    printTime();
    std::cout << "x=" << pos.x << ", y=" << pos.y << std::endl;
}

void Logger::printTime()
{
    auto timer = time(NULL);
    auto locTime = std::localtime(&timer);
    std::cout << "[" << locTime->tm_hour << ":" << locTime->tm_min << ":" << locTime->tm_sec << "] ";
}