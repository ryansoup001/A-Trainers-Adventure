#include <iostream>
#include "gamestate.h"
using namespace std;
int main() {
    GameState gamestate;
    while (gamestate.checkGameState("running")) {
        cout << "Hello World" << endl;
        break;
    }
    return 0;
}

