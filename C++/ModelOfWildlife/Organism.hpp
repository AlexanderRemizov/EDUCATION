#ifndef Organism_hpp
#define Organism_hpp
#include <vector>
#include <iostream>

class Organism
{
public:
    int x;
    int y;
    int age;
    const char who;
    Organism();
    Organism(int, int, char);
    virtual void live(std::vector<Organism*> &);
    virtual void reproduction(std::vector<Organism*> &);
    virtual ~Organism();
    void dead(int, int);
};
#endif
