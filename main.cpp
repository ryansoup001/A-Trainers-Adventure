#include <iostream>
#include "gamestate.h"
#include "display.h"
#include <string>
using namespace std;
int main() {
    GameState gamestate;
    Display window;
    const char CONTINUE = 'Y';
    string userIn = "";
    while (userIn != "Y") {
        cout << "Enter \'"<< CONTINUE << "\' to exit the simulation" << endl;
        // render space

        // get input
        window.checkWindow();
        // update vairables
        cin >> userIn;
        if (toupper(userIn[0]) == CONTINUE){
            break;
        }
    }
    return 0;
}

