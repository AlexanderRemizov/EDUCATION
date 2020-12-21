#include "Goat.hpp"

Goat::Goat(): Animal(-1, -1, '0', -11)
{}

Goat::Goat(int x_, int y_, char who_, int satiety_): Animal(x_, y_, who_, satiety_)
{}

void Goat::live(std::vector<Organism*> &allOrganisms)
{
    if ((age == maxLifeG) || (satiety == minSatietyG)) {
        for (int i = 0; i < allOrganisms.size(); ++i) {
            if ((allOrganisms[i] -> who == 'G') && ((allOrganisms[i] -> x) == x) &&
                ((allOrganisms[i] -> y) == y)) {
                allOrganisms.erase(allOrganisms.begin() + i);
                break;
            }
        }
    }
    else {
        this -> age++;
        this -> satiety--;
        if (!danger(allOrganisms)) {
            if ((age % ageForRepG == 0) && (age < maxLifeG) && (satiety > satietyForRepG)) {
                reproduction(allOrganisms);
            }
            if (satiety > maxSatietyG) {
                randomWalk(allOrganisms, 0);
            }
            else {
                if (eat(allOrganisms, 2) == false) {
                    randomWalk(allOrganisms, 2);
                }
            }
        }
    }
}

void Goat::reproduction(std::vector<Organism*> &allOrganisms)
{
    struct coordinates
    {
        int x;
        int y;
    };
    std::vector <coordinates> coord;
    for (int i = -radReproductionG; i <= radReproductionG; ++i) {
        for (int j = -radReproductionG; j <= radReproductionG; ++j) {
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
        allOrganisms.push_back(new Goat(newx, newy, 'G', satiety));
    }
}

void Goat::randomWalk(std::vector<Organism*> &allOrganisms, int plus)
{
    struct coordinates
    {
        int x;
        int y;
    };
    std::vector <coordinates> coord;
    for (int i = -radWalkingG; i <= radWalkingG; ++i) {
        for (int j = -radWalkingG; j <= radWalkingG; ++j) {
            if (((x + i) >= 0) && ((x + i) < lenField) && ((y + j) >= 0) && ((y + j) < widField)) {
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

bool Goat::eat(std::vector<Organism*> &allOrganisms, int plus) {
    struct coordinates
    {
        int x;
        int y;
        int ind;
    };
    int k = 0;
    std::vector <coordinates> coord;
    for (Organism* org : allOrganisms) {
        for (int i = -radVisionG-plus; i <= radVisionG+plus; ++i) {
            for (int j = -radVisionG-plus; j <= radVisionG+plus; ++j) {
                if (((x + i) >= 0) && ((y + j) >= 0) && ((x + i) < lenField) && ((y + j) < widField)
                    && (org -> who == 'C') && (org -> x == (x + i)) && (org -> y == (y + j))) {
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
        this -> satiety = this -> satiety + plusSatietyG;
        return true;
    }
    return false;
}

bool Goat::danger(std::vector<Organism*> &allOrganisms)
{
    int kpp = 0, kpm = 0, kmp = 0, kmm = 0, k0p = 0, k0m = 0, kp0 = 0, km0 = 0;
    bool flag = false;
    for (Organism* org : allOrganisms) {
        for (int i = -radVisionG; i <= radVisionG; ++i) {
            for (int j = -radVisionG; j <= radVisionG; ++j) {
                if ((org -> x == x + i) && (org -> y == y + j) && (org -> who == 'W')) {
                    if ((i > 0) && (j > 0)) {
                        kpp++;
                    }
                    if ((i > 0) && (j < 0)) {
                        kpm++;
                    }
                    if ((i < 0) && (j > 0)) {
                        kmp++;
                    }
                    if ((i < 0) && (j < 0)) {
                        kmp++;
                    }
                    if ((i == 0) && (j < 0)) {
                        k0m++;
                    }
                    if ((i == 0) && (j > 0)) {
                        k0p++;
                    }
                    if ((j == 0) && (i < 0)) {
                        km0++;
                    }
                    if ((j == 0) && (i > 0)) {
                        kp0++;
                    }
                    flag = true;
                }
            }
        }
    }
    if (flag == false) {
        return false;
    }
    int plus = 2;
    if ((k0m == 0) && (kpm == 0) && (kp0 == 0) && (kpp == 0) && (k0p == 0)) {
        if (x + radWalkingG + plus < lenField) {
            x = x + radWalkingG + plus;
        }
        else {
            x = lenField - 1;
        }
    }
    else if ((km0 == 0) && (kmm == 0) && (k0m == 0) && (kpm == 0) && (kp0 == 0)) {
        if (y + radWalkingG + plus < widField) {
            y = y + radWalkingG + plus;
        }
        else {
            y = widField - 1;
        }
    }
    else if ((km0 == 0)&&(kmm == 0) && (k0m == 0) && (kmp == 0) && (k0p == 0)) {
        if (x - radWalkingG - plus >= 0) {
            x = x - radWalkingG - plus; 
        }
        else {
            x = 0;
        }
    }
    else if ((km0 == 0) && (kpp == 0) && (kp0 == 0) && (kmp == 0) && (k0p == 0)) {
        if (y - radWalkingG - plus >= 0) {
            y = y - radWalkingG - plus;
        }
        else {
            y = 0;
        }
    }
    return true;
}










