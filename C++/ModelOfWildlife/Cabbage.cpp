#include "Cabbage.hpp"

Cabbage::Cabbage(int x_, int y_, char who_): Organism(x_, y_, who_)
{}

void Cabbage::live(std::vector<Organism*> &Allorganisms)
{
    if (age == maxLifeC) {
        for (int i = 0; i < Allorganisms.size(); ++i) {
            if((Allorganisms[i] -> who == 'C') && (Allorganisms[i] -> x == x) &&
               (Allorganisms[i] -> y == y)) {
                Allorganisms.erase(Allorganisms.begin() + i);
                break;
            }
        }
    }
    else {
        age++;
        if ((age % ageForRepC == 0) && (age < maxLifeC)) {
            reproduction(Allorganisms);
        }
    }
}

void Cabbage::reproduction(std::vector<Organism*> &allOrganisms)
{
    struct coordinates
    {
        int x;
        int y;
    };
    std::vector <coordinates> coord;
    for (int i = -radReproductionC; i <= radReproductionC; ++i) {
        for (int j = -radReproductionC; j <= radReproductionC; ++j) {
            if (((x + i) >= 0) && ((x + i) < lenField) && ((y + j) >= 0) &&
                ((y + j) < widField)) {
                int count = 0;
                for (Organism* org: allOrganisms) {
                    if ((org -> x != (x + i)) || (org -> y != (y + j))) {
                        count++;
                    }
                }
                if (count==allOrganisms.size()){
                    coordinates newCoord = {x + i, y + j};
                    coord.push_back(newCoord);
                }
            }
        }
    }
    if (!coord.empty()) {
        int newcoord = rand() % coord.size();
        int newx=coord[newcoord].x;
        int newy=coord[newcoord].y;
        allOrganisms.push_back(new Cabbage(newx, newy, 'C'));
    }
}

