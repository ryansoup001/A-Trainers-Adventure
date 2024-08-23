#include "Events.h"
void Events::startGame() {
    running = true;
    state = "title";
    previousState = "";
}
void Events::setState(string st) {
    previousState = state; 
    state = st;
}
void Events::inspectDungeon(Room* dungeon, Player* plr, Entity* ally, Treasure* treasure) {
    /* the original arguments for this function was going to be only the dungeon pointer but because of it being unable to change certain memory adresses the result above happened*/
    if (!treasure->is_empty()) {
        display.foundTreasure(itemLib,*treasure);
        // Add treasure stats here
        plr->addMoney(treasure->coins);
        plr->setLevel(plr->getLvl() + treasure->strength);
        if (plr->getItem().getBoost() != 1) {
            int in;
            display.promptChangeItem(itemLib.item(treasure->itemCode), plr->getItem());
            cin >> in;
            switch(in) {
                case 1:
                    //YES
                    plr->setItem(itemLib.item(treasure->itemCode));
                    break;
                default:
                    //NO
                    break;
            }
        } else {
            plr->setItem(itemLib.item(treasure->itemCode));
        }
        treasure->coins = 0;
        treasure->strength = 0;
        treasure->itemCode = -1;
    } else if (ally->getName() != "Unknown" && !dungeon->hasEnemy()){
        //EASTER EGG

        if (ally->greet()) {
        cout << dungeon->getEntity().getName() << " says Hello!" << endl;
        plr->helloCounter++;
        } else {
            cout << ally->getName() << " got tired of your antics and left.." << endl;
            //dungeon->cleared();
            ally->setName("Unknown");
        }
    } else {
        cout << "This room is empty..." << endl;
    }
}
void Events::enterDungeon(Room dungeon) {
    if (dungeon.hasEnemy()) {
        setState("battle");
        battle(dungeon);
    } else {
        previousState = "dungeon";
        cout << "This room seems safe ... " << endl;
    }
}
void Events::battle(Room dungeon) {
    turn = rand() % 2;
    display.attackedBy(dungeon.getEntity());
}
void Events::changeTurn() {
    if (turn == 0) {
        turn = 1;
    } else {
        turn = 0;
    }
}
void Events::gameOver() {
    running = false;
    state = "";
}
string Events::getState() {
    return state;
}
int Events::getTurn() {
    return turn;
}
string Events::getPreviousState() {
    return previousState;
}
void Events::setPreviousState(string _s) {
    previousState = _s;
}
void Events::setTurn(int t) {
    turn = t;
}