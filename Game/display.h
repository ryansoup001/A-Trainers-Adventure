#ifndef DISPLAY_H
#define DISPLAY_H

#include <iostream>
using namespace std;
class Display {
    public:
    /*
    const int PIXEL_PER_TILE = 1;
    const int WINDOW_LENGTH  = 50, WINDOW_WIDTH = 50;
    int map[WINDOW_WIDTH/PIXEL_PER_TILE][WINDOW_LENGTH/PIXEL_PER_TILE];
    */
    //initializes window for display
    Display() { 
        cout << "Made a window!\n";
    }
    void checkWindow() {
        cout << "Window is running\n";
    }
};
#endif