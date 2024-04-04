#include <iostream>
#include <string>
using namespace std;
class GameState {
    public:
    string gamestates[3];
    //determines what index in gamestates to put new stacked state
    int numStates;
    GameState();
    string getGameState();
    bool checkGameState(string state);
    bool removeGameState();
    void setGameState(string state, int index);
    bool stackGameState(string state);
};