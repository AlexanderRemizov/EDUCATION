#include "Field.hpp"
#include <iostream>
using namespace std;

Field::Field()
{
    for (int i = 0; i < Settings::lenField; ++i) {
        for (int j = 0; j < Settings::widField; ++j) {
            matrix[i][j] = '_';
        }
    }
}

void Field::process()
{
    char mass[lenField][widField];
    memset(mass, 0, lenField * widField);
    int count=0;
    while (count<CountC) {
        int x = rand() % lenField;
        int y = rand() % widField;
        if (mass[x][y]==0) {
            mass[x][y]=1;
            organisms.push_back(new Cabbage(x, y, 'C'));
            count++;
        }
    }
    count=0;
    while (count<CountG) {
        int x = rand() % lenField;
        int y = rand() % widField;
        if (mass[x][y]==0) {
            mass[x][y]=1;
            organisms.push_back(new Goat(x, y, 'G', 6));
            count++;
        }
    }
    count=0;
    while (count<CountW) {
        int x = rand() % lenField;
        int y = rand() % widField;
        if (mass[x][y]==0) {
            mass[x][y]=1;
            organisms.push_back(new Wolf(x, y, 'W', 10));
            count++;
        }
    }
    int iteration = 0;
    cout << "start" << endl;
    memset(matrix, '_', lenField * widField);
    for (int i = 0; i < organisms.size(); ++i) {
        if ((organisms[i] -> who == 'G')) {
            matrix[organisms[i] -> x][organisms[i] -> y] = 'K';
        }
        else if ((organisms[i] -> who == 'C')) {
            matrix[organisms[i] -> x][organisms[i] -> y] = '@';
        }
        else if ((organisms[i] -> who == 'W')) {
            matrix[organisms[i] -> x][organisms[i] -> y] = 'W';
        }
    }
    for (int i = 0; i < lenField; ++i) {
        for (int j = 0; j < widField; ++j) {
            std::cout << matrix[i][j];
        }
        std::cout << std::endl;
    }
    
    while(!organisms.empty()) {
        iteration++;
        int c = 0;
        int g = 0;
        int w = 0;
        cout << "iteration: " << iteration << endl;
        for (int i = 0; i < organisms.size(); ++i) {
            organisms[i] -> live(organisms);
            if (organisms[i] -> who == 'C') {
                c++;
            }
            else if (organisms[i] -> who == 'G') {
                g++;
            }
            else {
                w++;
            }
        }
        memset(matrix, '_', lenField * widField);
        for (int i = 0; i < organisms.size(); ++i) {
            if ((organisms[i] -> who == 'G')) {
                matrix[organisms[i] -> x][organisms[i] -> y] = 'K';
            }
            else if ((organisms[i] -> who == 'C')) {
                matrix[organisms[i] -> x][organisms[i] -> y] = '@';
            }
            else if ((organisms[i] -> who == 'W')) {
                matrix[organisms[i] -> x][organisms[i] -> y] = 'W';
            }
        }
        for (int i = 0; i < lenField; ++i) {
            for (int j = 0; j < widField; ++j) {
                std::cout << matrix[i][j];
            }
            std::cout << std::endl;
        }
        cout << "Cabbage: " << c << "   Goat: " << g << "    Wolf: " << w << endl;
        if ((c == 0) || (g == 0) || (w == 0)) {
            cout << "The End(FIN)" << endl;
            break;
        }
        std::cout << std::endl;
    }
}
