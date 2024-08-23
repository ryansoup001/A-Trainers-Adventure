#include "Room.h"
Room::Room() {
    treasure = Treasure();
}
Room::Room(Entity ent, int _coins, int _strength, int item) {
    entity = ent;
    treasure = Treasure(_coins, _strength, item);
}
void Room::cleared() {
    entity = Entity();
    //It's more optimal to set entity to NULL but C++ doesnt have any function like  
}
bool Room::hasEnemy() {
    if (entity.getType() == true) {
        return true;
    } 
    return false;
}
bool Room::hasTreasure() {
    if(treasure.coins == 0 && treasure.strength == 0 && treasure.itemCode == -1)  {
         return false;
    }
    cout << treasure.strength << endl;
    cout << treasure.itemCode << endl;
    cout << treasure.coins << endl;
    return true;
}
Entity Room::getEntity() {
    return entity;
}
Treasure Room::getTreasure() {
    return treasure;
}
void Room::clearTreasure() {
    treasure.coins = 0;
    treasure.itemCode = -1;
    treasure.strength = 0;
    
}