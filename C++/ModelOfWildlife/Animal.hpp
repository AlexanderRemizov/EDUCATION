#ifndef Animal_hpp
#define Animal_hpp
#include "Organism.hpp"

class Animal : public Organism
{
public:
    int satiety;
    Animal();
    Animal(int, int, char, int);
    virtual ~Animal();
    virtual void live(std::vector<Organism*> &) override;
    virtual void reproduction(std::vector<Organism*> &) override;
    virtual void randomWalk(std::vector<Organism*> &, int);
    virtual bool eat(std::vector<Organism*> &, int);
};

#endif
