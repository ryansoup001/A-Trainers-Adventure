#ifndef ROOM_H
#define ROOM_H
#include "Entity.h"
#include "Treasure.h"
class Room {
    private:
        Entity entity;
        Treasure treasure;
        //first number was coins second represents power third represents an item 
    public:
        Room();
        Room(Entity entity, int, int, int);
        bool hasEnemy();
        Entity getEntity();
        Treasure getTreasure();
        bool hasTreasure();
        void clearTreasure();
        void cleared();
};
#endif