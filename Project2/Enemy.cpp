#include "Enemy.h"
Enemy::Enemy() : Entity() {
    Entity::setEnemy(true);
}
Enemy::Enemy(int _h, int _l, int loc[2], string _n) : Entity(_h,_l,loc,_n) {
    Entity::setEnemy(true);
}
bool Enemy::getType() {
   return Entity::getType();
}