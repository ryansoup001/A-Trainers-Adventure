#include <iostream>
#include <string>
using namespace std;
class GameState {
    public:
    string gamestates[3];
    //determines what index in gamestates to put new stacked state
    int stIndex = 0;
    GameState() {
        gamestates[0] = "running";
        stIndex++;
    }
    string getGameState() {
        return gamestates[0];
    }
    bool checkGameState(string state) {
        for (int i = 0; i < sizeof(gamestates)/sizeof(*gamestates); i++) {
            if (gamestates[i] == state)  {
                return true;
            }
       }
        return false;
    }
    void setGameState(string state) {
         for (int i = 0; i < sizeof(gamestates)/sizeof(*gamestates); i++) {
            gamestates[i] = "\0";
        }
        gamestates[0] = state;
    }
    void stackGameState(string state) {
    }
};