#include "Wolf.hpp"
using namespace std;

Wolf::Wolf(): Animal(-1, -1, '0', -11)
{}

Wolf::Wolf(int x_, int y_, char who_, int satiety_): Animal(x_, y_, who_, satiety_)
{}

void Wolf::live(std::vector<Organism*> &allOrganisms)
{
    if ((age == maxLifeW) || (satiety == minSatietyW)) {
        for (int i = 0; i < allOrganisms.size(); ++i) {
            if ((allOrganisms[i] -> who == 'W') && ((allOrganisms[i] -> x) == x) &&
                ((allOrganisms[i] -> y) == y)) {
                allOrganisms.erase(allOrganisms.begin() + i);
                break;
            }
        }
    }
    else {
        this -> age++;
        this -> satiety--;
        if ((age % ageForRepW == 0) && (age < maxLifeW) && (satiety > satietyForRepW)) {
            reproduction(allOrganisms);
        }
        if (satiety > maxSatietyW) {
            randomWalk(allOrganisms, 0);
        }
        else {
            if (eat(allOrganisms, 0) == false) {
                randomWalk(allOrganisms, 0);
            }
        }
    }
}

void Wolf::reproduction(std::vector<Organism*> &allOrganisms)
{
    struct coordinates
    {
        int x;
        int y;
    };
    std::vector <coordinates> coord;
    for (int i = -radReproductionW; i <= radReproductionW; ++i) {
        for (int j = -radReproductionW; j <= radReproductionW; ++j) {
            if (((x + i) >= 0) && ((x + i) < lenField) && ((y + j) >= 0) &&
                ((y + j) < widField)) {
                int count = 0;
                for (Organism* org: allOrganisms) {
                    if ((org -> x != (x + i)) || (org -> y != (y + j))) {
                        count++;
                    }
                }
                if (count==allOrganisms.size()) {
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
        allOrganisms.push_back(new Wolf(newx, newy, 'W', satiety));
    }
}

void Wolf::randomWalk(std::vector<Organism*> &allOrganisms, int plus)
{
    struct coordinates
    {
        int x;
        int y;
    };
    std::vector <coordinates> coord;
    for (int i = -radWalkingW; i <= radWalkingW; ++i) {
        for (int j = -radWalkingW; j <= radWalkingW; ++j) {
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
        this -> x = newx;
        this -> y = newy;
    }
}

bool Wolf::eat(std::vector<Organism*> &allOrganisms, int plus)
{
    struct coordinates
    {
        int x;
        int y;
        int ind;
    };
    int k = 0;
    std::vector <coordinates> coord;
    for (Organism* org : allOrganisms) {
        for (int i = -radVisionW; i <= radVisionW; ++i) {
            for (int j = -radVisionW; j <= radVisionW; ++j) {
                if (((x + i) >= 0) && ((y + j) >= 0) && ((x + i) < lenField) &&
                    ((y + j) < widField) && (org -> who == 'G') &&
                    (org -> x == (x + i)) && (org -> y == (y + j))) {
                    coordinates newCoord = {x + i, y + j, k};
                    coord.push_back(newCoord);
                }
            }
        }
        k++;
    }
    if (!coord.empty()) {
        int newcoord = rand() % coord.size();
        int newx=coord[newcoord].x;
        int newy=coord[newcoord].y;
        int ind=coord[newcoord].ind;
        allOrganisms.erase(allOrganisms.begin() + ind);
        this -> x = newx;
        this -> y = newy;
        this -> satiety = this -> satiety + plusSatietyW;
        return true;
    }
    return false;
}










