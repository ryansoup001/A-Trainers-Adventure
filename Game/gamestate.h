#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <iostream>
#include <string>
using namespace std;
class GameState {
    private:
    string gamestates[3];
    //determines what index in gamestates to put new stacked state
    int numStates;
    public:
    GameState();
    string getGameState();
    bool checkGameState(string state);
    bool removeGameState();
    void setGameState(string state, int priority);
    void setGameState(string state);
    bool stackGameState(string state);
    void showgameStates();
};

#endif