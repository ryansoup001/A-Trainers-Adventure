#ifndef ENEMY_H
#define ENEMY_H
#include "Entity.h"
class Enemy: public Entity {
    private:
    public:
    Enemy();
    Enemy(int, int, int*, string);
    bool getType();
};
#endif