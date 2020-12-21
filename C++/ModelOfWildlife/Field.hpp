#ifndef Field_hpp
#define Field_hpp
#include "Organism.hpp"
#include "Cabbage.hpp"
#include "Goat.hpp"
#include "Wolf.hpp"
#include "Parameters.hpp"
#include <vector>
using namespace Settings;

class Field 
{
public:
    Field();
    void process();
private:
    char matrix[lenField][widField];
    std::vector<Organism*> organisms;
};

#endif /* Field_hpp */
