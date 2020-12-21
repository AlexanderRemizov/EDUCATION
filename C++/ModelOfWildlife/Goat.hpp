#ifndef Goat_hpp
#define Goat_hpp
#include "Animal.hpp"
#include "Parameters.hpp"
#include <iostream>
using namespace Settings;

class Goat : public Animal
{
public:
    Goat();
    Goat(int, int, char, int);
    virtual void live(std::vector<Organism*> &);
    virtual void reproduction(std::vector<Organism*> &);
    virtual void randomWalk(std::vector<Organism*> &, int);
    virtual bool eat(std::vector<Organism*> &, int);
    bool danger(std::vector<Organism*> &);
private:
    
};

#endif
