#include "Entity.h"
Entity::Entity() {
    health = 50;
    enemy = false;
    lvl = 1;
    loc[0] = 0;
    loc[1] = 0;
    name = "Unknown";
 }
Entity::Entity(int h, int l, int arr[2], string n) {
    enemy = false;
    for (int i  = 0; i < 4; i++) {
        moves[i] = accessMoves.getMove(rand() % 5);
    }
    health = h;
    lvl = l;
    name = n;
    loc[0] = arr[0];
    loc[1] = arr[1];
}
Entity::Entity(int h, int l, string n) {
    enemy = false;
    for (int i  = 0; i < 4; i++) {
        moves[i] = accessMoves.getMove(rand() % 5);
    }
    health = h;
    lvl = l;
    name = n;
    loc[0] = 0;
    loc[1] = 0;
}
void Entity::attack(Moves moves, Entity* target) {
    cout << &target << endl;
    cout << this->getName()  << " used " << moves.getName() << " against " << target->getName() <<  endl;
    target->setHealth(target->getHealth() - ((static_cast<int>(this->getLvl() * .4)) + moves.getStrength())); // (static_cast<int>(this->getLvl() * .4)
    cout << target->getName() << " now has " << target->getHealth() << " HP remaining." << endl;
}
void Entity::setName(string n) {
    name = n;
}
void Entity::setMove(Moves m, int index) {
    moves[index] = m;
}
void Entity::setLevel(int newLevel)  {
    lvl = newLevel;
}
void Entity::setHealth(int h) {
    health = h;
}
void Entity::setLocation(int arr[2]) {
    loc[0] = arr[0];
    loc[1] = arr[1];
}
void Entity::setLocation(int f,int r) {
    loc[0] = f;
    loc[1] = r;
}
void Entity::setEnemy(bool ene) {
    enemy = ene;
}