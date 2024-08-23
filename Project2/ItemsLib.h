#ifndef ItemsLIB_H
#define ItemsLIB_H
#include "Items.h"
class ItemLibrary {
    private:
        Item ItemsList[3] = {Item("Brass Knuckles", .5), Item("Axe" , .7), Item("War Hammer" , 2.4)};
    public:
        Item item(int index) {
            return ItemsList[index];
        }
        
};
#endif