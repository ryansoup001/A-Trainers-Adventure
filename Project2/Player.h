#ifndef PLAYER_H
#define PLAYER_H
#include "Entity.h"
#include "Map.h"
#include "ItemsLib.h"
class Player : public Entity{
    private: 
    int money;
    int rests = 3;
    int maxHealth;
    int STARTING_POS[2] = {0,0};
    Item equipped;
    public: 
        int helloCounter = 0; 
        Player();
        Player(int _m,int _h);
        void addMoney(int);
        void setRests(int r) {
            rests = r;
        }
        void setItem(Item i) {
            cout << "You have picked up the item " << i.getName() << endl; 
            equipped = i;
        }
        void setMoney(int);
        void attack(Moves moves, Entity* target);
        int* getStart() {return STARTING_POS;}
        void gotoStart();
        int getRests();
        int getMaxHealth();
        Item getItem() {return equipped;}
        int getMoney();
        Player getplr() {return *this;}
        bool advancePlr(Map);
};
#endif