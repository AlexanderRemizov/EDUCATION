#ifndef Wolf_hpp
#define Wolf_hpp
#include "Animal.hpp"
#include "Parameters.hpp"
#include <iostream>
using namespace Settings;

class Wolf : public Animal
{
public:
    Wolf();
    Wolf(int, int, char, int);
    virtual void live(std::vector<Organism*> &);
    virtual void reproduction(std::vector<Organism*> &);
    virtual void randomWalk(std::vector<Organism*> &, int);
    virtual bool eat(std::vector<Organism*> &, int);
private:
};

#endif

  
