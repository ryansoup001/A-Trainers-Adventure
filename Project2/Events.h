#ifndef EVENTS_H
#define EVENTS_H
#include <iostream>
#include "Map.h"
#include "Player.h"
#include "Display.h"
using namespace std;
 

class Events {
    private:
    string state;
    int turn; // 0 is always player 1 is enemy 
    Display display;
    string previousState;
    ItemLibrary itemLib;
    public:
        bool running = true;
        void inspectDungeon(Room*,Player*, Entity*, Treasure*);
        string getPreviousState();
        void startGame();
        void enterDungeon(Room);
        void setState(string);
        void gameOver();
        void changeTurn();
        string getState();
        int getTurn();
        void setTurn(int);
        void battle(Room);
        void recieveInputs(int);
        void setPreviousState(string);
};
#endif