#ifndef MOVELIB_H
#define MOVELIB_H
#include "moves.h"
class moveLibrary {
    private:
        Moves movesList[5] = {Moves("Slap", 30), Moves("Punch" , 45), Moves("Scratch" , 35), Moves("Kick" , 30) , Moves("Bite" , 40)};
    public:
        Moves getMove(int index) {
            return movesList[index];
        }
        
};
#endif