#ifndef TREASURE_H
#define TREASURE_H
class Treasure {
    //TODO: make getters and setters
    public:
    int coins = 0;
    int strength = 0;
    int itemCode = -1;
    Treasure() {
    }
    Treasure(int _coins,int _strength, int _item) {
        coins = _coins;
        strength = _strength;
        itemCode = _item;
    }
    bool is_empty(){
        if(coins == 0 && strength == 0 && itemCode == -1)  {
         return true;
        } else {
            return false;
        }
    }
};
#endif