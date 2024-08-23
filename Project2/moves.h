#ifndef MOVES_H
#define MOVES_H
#include <iostream> 
using namespace std;
class Moves {
        string name;
        int strength;
    public:
    Moves() {
        name = "    ";
        strength = 0;
    }
    Moves(string n, int s) {
        name = n;
        strength = s;
    }
        string getName() {return name;}
        int getStrength() {return strength;}
        void operator = (Moves move) {
            name = move.getName();
            strength = move.getStrength();
        }
};
#endif