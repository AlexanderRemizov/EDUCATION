#ifndef Cabbage_hpp
#define Cabbage_hpp
#include "Organism.hpp"
#include "Parameters.hpp"
using namespace Settings;

class Cabbage : public Organism
{
public:
    Cabbage();
    Cabbage(int, int, char);
    virtual ~Cabbage() = default;
    virtual void reproduction(std::vector<Organism*> &) override;
    virtual void live(std::vector<Organism*> &) override;
private:
};

#endif

