#include "Organism.hpp"

Organism::Organism(int x_, int y_, char who_): x(x_), y(y_), age(0), who(who_)
{}

Organism::Organism(): x(-1), y(-1), age(-1), who('0')
{}

void Organism::live(std::vector<Organism*> &)
{}

void Organism::reproduction(std::vector<Organism*> &)
{}

Organism::~Organism()
{}

void Organism::dead(int x_, int y_)
{}

