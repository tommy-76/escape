#include "Randomizer.h"

#include <ctime>

Randomizer::Randomizer()
{
    generator.seed(time(nullptr));
}

Randomizer::~Randomizer()
{
}

int Randomizer::getRandomInt(int begin, int end)
{
    std::uniform_int_distribution<int> distro(begin, end);
    return distro(generator);
}

std::mt19937& Randomizer::getGenerator()
{
    return generator;
}
