#ifndef DISPLAY_H
#define DISPLAY_H
#include <iostream>
#include "Player.h"
#include "Room.h"
using namespace std;
class Display {
    private:
    public:
        void promptLoadfile();
        void titlePrompt();
        void promptSaveFileName();
        void promptChangeItem(Item,Item);
        void dungeonPrompt(bool, int ,int);
        void emptyDungeonPrompt();
        void attackedBy(Entity);
        void setScreen(string);
        void getScreen(string);
        void foundTreasure(ItemLibrary, Treasure);
        void battleStatus(Entity opp , Player plr);
        void moveDisplay(Player plr);
};
#endif