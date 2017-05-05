#ifndef RANDOMIZER_H
#define RANDOMIZER_H

#include <random>

class Randomizer
{
public:
    Randomizer();
    virtual ~Randomizer();
    Randomizer(const Randomizer& rhs) = delete;
    Randomizer& operator=(const Randomizer& rhs) = delete;

    int getRandomInt(int begin, int end);

    std::mt19937& getGenerator();

private:
    std::mt19937 generator;

};

#endif // RANDOMIZER_H
