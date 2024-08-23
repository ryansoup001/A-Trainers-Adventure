#include "Display.h"

void Display::dungeonPrompt(bool enemy, int floor, int room) {
    cout << "You are on floor "<< floor << " dungeon " << room << endl;
    if (!enemy) {
        cout << "What will you do?\n1.Continue forward\n2. Inspect the dungeon\n3. Rest\n" << endl;
    }
}
void Display::emptyDungeonPrompt() {
    cout << "\nIt seems to be empty..." << endl;
}
void Display::promptSaveFileName() {
    cout << "Enter the save file name: ";
}
void Display::promptLoadfile() {
    cout << "Will you 1. load a save file 2. or play without pre-existing data?" << endl;
}
void Display::promptChangeItem(Item i1, Item i2) {
    cout << "You have found a " << i1.getName() << " will you swap it out for your " << i2.getName() << endl;
}
void Display::foundTreasure(ItemLibrary itemLib,Treasure treasure) {
    cout << "You have found Treasure!!" << endl << "You got: \n" << treasure.coins << " coins\nA " << itemLib.item(treasure.itemCode).getName() << endl << "and " << treasure.strength << " strength" << endl;   
}
void Display::titlePrompt() {
    cout << "Welcome to Duengon Madness..." << endl;
    cout << "Will you 1.Play Game 2. Settings 3.or Exit Game" << endl;
}
void Display::battleStatus(Entity opp , Player plr) {
    cout << "You are fighting " << opp.getName()  << endl;
    cout << "You have " << plr.getHealth() << " HP remaining" << endl;
    cout << opp.getName() << " has " << opp.getHealth() << " HP remaining" << endl;
}
void Display::moveDisplay(Player plr) {
    cout << "What will you do?" << endl; 
    for(int i = 0; i < 4; i++) {
    cout << (i + 1 )<<".Use " << plr.getMoveAt(i).getName() << "   " << plr.getMoveAt(i).getStrength() << " Base Power\n" << endl;
    }
}
void Display::attackedBy(Entity opp) {
    cout << "You have been attacked by " << opp.getName() << "!" << endl; 
}

