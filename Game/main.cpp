#include <iostream>
#include "gamestate.h"
#include "display.h"
#include <string>
using namespace std;

// g++ *.cpp -o "file_name"
// ./"file_name"
int main() {
    GameState gamestate;
    Display window;
    const char CONTINUE = 'Y';
    string userIn = "";
    while (gamestate.checkGameState("running")) {
        cout << "Enter \'"<< CONTINUE << "\' to exit the simulation" << endl;
        // render space
        // get input
        window.checkWindow();
        gamestate.showgameStates();
        // update vairables
        cin >> userIn;
        if (toupper(userIn[0]) == CONTINUE){
            break;
        }
    }
    return 0;
}

