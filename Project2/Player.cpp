#include "Player.h"
    Player::Player() : Entity(){
        money = 0;
        Entity::setName("You");
        gotoStart();
    }
    Player::Player(int _m,int _h) : Entity(_h,4,"You"){
        money = _m;
        maxHealth = _h;
    }
    int Player::getMaxHealth() {
        return maxHealth;
    }
    void Player::addMoney(int add) {
        money += add;
    }
    void Player::setMoney(int m) {
        money = m;
    }
    int Player::getMoney() {return money;}
    void Player::gotoStart() {
        this->setLocation(STARTING_POS);
    }
    int Player::getRests() {
        return rests;
    }
    bool Player::advancePlr(Map map) {
            int advanceloc[2] = {this->getLocation()[0],this->getLocation()[1]};
            if (advanceloc[1] < map.getMaxRooms() - 1) {
                advanceloc[1] += 1;
            } else {
                advanceloc[0] += 1;
                advanceloc[1] = 0;
                if (advanceloc[0] >= map.getMaxFloors()) {
                    return false;
                }
            }
            this->setLocation(advanceloc);
            return true;
    }
    void Player::attack(Moves moves, Entity* target) {
    cout << this->getName()  << " used " << moves.getName() << " against " << target->getName() <<  endl;
    target->setHealth(target->getHealth() - (((static_cast<int>(this->getLvl() + helloCounter) * 2) ) + moves.getStrength() + (moves.getStrength() * equipped.getBoost()))); // (static_cast<int>(this->getLvl() * .4)
    cout << target->getName() << " now has " << target->getHealth() << " HP remaining." << endl;
}