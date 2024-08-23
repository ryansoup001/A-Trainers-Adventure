#include "gamestate.h"

GameState::GameState() {
        numStates = 0;
        gamestates[numStates] = "running";
        numStates++;
}
string GameState::getGameState() {
        return gamestates[0];
}
bool GameState::checkGameState(string state) {
        for (int i = 0; i < numStates; i++) {
            if (gamestates[i] == state)  {
                return true;
            }
       }
        return false;
}
void GameState::setGameState(string state, int priority) {
    /* 
    Sets the priority GameState to specified State
    Note: i dont know what i was trying to do here
    Throws out most recent GameState
    */
    if (numStates < 3) {
        for (int i = numStates; i > 1; i--) {
            gamestates[i] = gamestates[i - 1]; 
        }
    } 
    
    gamestates[priority] = state;
}
void GameState::setGameState(string state) {
    /* 
    Sets the first GameState to specified State
    Throws out most recent GameState
    */
    if (numStates < 3) {
        for (int i = numStates; i > 1; i--) {
            gamestates[i] = gamestates[i - 1]; 
        }
    } 
    
    gamestates[0] = state;
}
bool GameState::removeGameState() {
    gamestates[0] = "";
    gamestates[0] = gamestates[1];
    gamestates[1] = gamestates[2];
    return true;

}
bool GameState::stackGameState(string state) {
    string t;
    if (numStates >= 3) {
        return false;
    } else {
    for (int i = numStates; i > 0; i--) {
        if( i > 1) {
            gamestates[i] = gamestates[i - 1];
            gamestates[i - 1] = "";
        }
    }
    gamestates[0] = state;
    }
    return true;
}
void GameState::showgameStates() {
    for (int i = 0; i < numStates; i++) {
        cout << gamestates[i] << " ";
    } 
    cout << endl;
}