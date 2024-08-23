#ifndef ENTITY_H
#define ENTITY_H
#include <vector>
#include <iostream>
#include "moveLib.h"
using namespace std;
class Entity {
    private:
        int health;
        int lvl;
        int loc[2] = {0,0};
        moveLibrary accessMoves;
        Moves moves[4];
        string name;
        int hello = rand() % 4;
        bool enemy;
    public:
        Entity();
        Entity(int, int, int arr[2], string);
        Entity(int, int, string);

        bool getType() {return enemy;}
        int* getLocation() {return loc;}
        string getName() { return name;}
        Moves* getMoves() {return moves;} 
        Moves getMoveAt(int index) {return moves[index];}
        int getHealth(){return health;}
        int getLvl() {return lvl;}

        void setName(string);
        void setEnemy(bool);
        void setMove(Moves , int);
        void setLevel(int) ;
        void setHealth(int);
        void setLocation(int*);
        void setLocation(int,int);

        bool greet() {
            if (hello < 0) {
                return false;
            }
            cout << hello << endl;
            hello--;
            return true;
        }

        virtual void attack(Moves moves, Entity* target);

        bool operator == (const Entity& other) {
            return (this == &other);
        }
};

#endif