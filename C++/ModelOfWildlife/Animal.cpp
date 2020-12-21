#include "Animal.hpp"
#include <iostream>

Animal::Animal(): Organism(-1, -1, '0'), satiety(-11)
{
    std::cout << "Animal()" << std::endl;
}

Animal::Animal(int _x, int _y, char _who, int _satiety): Organism(_x, _y, _who), satiety(_satiety)
{}

Animal::~Animal()
{}

void Animal::reproduction(std::vector<Organism*> &)
{}

void Animal::live(std::vector<Organism*> &)
{}

void Animal::randomWalk(std::vector<Organism*> &, int)
{}

bool Animal::eat(std::vector<Organism*> &, int)
{
    return false;
}
