#include <iostream>
#include "Events.h"
#include <chrono>
#include <fstream>
#include <thread>
#include "Map.h"
#include "Player.h"
using namespace std;
int main() {
    Events state;
    Display print;

    Player plr(50 , 100000000); // Starting money and Health
    Player* plrAddr = &plr; 
    Entity entity = Entity(); // set Enemy to an empty entity

    Map map;
    Room currentDungeon = map.getDungeon(plr.getStart());
    Treasure treasure = currentDungeon.getTreasure();

    ofstream outFile;
    ifstream inFile;
    
    int input,input2,input3;
    int dungeonCount = 0;
    string filename;

    state.startGame();

    while (state.running) 
    { 
        //Prompt then waits for input
        if (dungeonCount > 10) {
            cout << "\nCongrats You Won!\n" << endl;
        }
        if (state.getState() == "title") {
            print.titlePrompt();
            cin >> input;
            switch (input)
            {
            case 1:
                print.promptLoadfile();
                cin >> input2;
                switch (input2) {
                    case 1:
                        do {
                            print.promptSaveFileName();
                            cin >> filename;
                            inFile.open(filename);
                            if (inFile.is_open()) {
                                int data[5];
                                //PARSE THE FILE TO SAVE INFO
                                for (int i = 0; i < 5; i++)
                                    inFile >> data[i];
                                plr.setHealth(data[3]);
                                cout << "Setting Health as " << data[3] << endl;
                                plr.setLevel(data[0]);
                                cout << "Setting Level as " << data[0] << endl;
                                plr.setLocation(data[1],data[2]);
                                cout << "Setting loc as " << data[1] << "," << data[2] << endl;
                                plr.setRests(data[4]);
                                cout << "Setting Rests as " << data[4] << endl;
                            } else {
                                cout << "No Save file found" << endl;
                                cout << "Enter a another save file?\n1. Yes\nPress any other key to continue" << endl;
                                cin >> input3;
                            }
                        } while(input3 == 1 && state.getState() != "dungeon");

                }
                state.setState("dungeon");
                break;
            case 2:
                // settings
                cout << "What, you thought you could get actual settings in a computer science project?" << endl;
                cout << "The goal is to clear 10 dungeons now play the game you dolt." << endl;
                break;
            case 3:
                state.running = false;
                cout << "Ending Game.." << endl;
                // quit Game
                return 0;
                break;
            //TODO make a store //no shop prolly
            }
            state.setPreviousState("title");
        } else if (state.getState() == "dungeon") { 
            currentDungeon = map.getDungeon(plr.getLocation());
            print.dungeonPrompt(currentDungeon.hasEnemy(), plr.getLocation()[0] + 1, plr.getLocation()[1] + 1);

            if (state.getPreviousState() != "dungeon") {
                state.enterDungeon(currentDungeon);
                continue;
            }

            cin >> input;
            switch(input)
            {
            case 1:
                // go Forth
                if (!currentDungeon.hasEnemy()) {
                    if(plr.advancePlr(map)) { 
                        cout << "You have traversed the dungeon " << endl;
                        dungeonCount++;
                        currentDungeon = map.getDungeon(plr.getLocation());
                        treasure = currentDungeon.getTreasure();
                        entity = currentDungeon.getEntity();
                        state.setPreviousState("cleared");
                        //set Health to full every 4 rooms traversed
                        if (dungeonCount % 4 == 0) { 
                            plr.setHealth(plr.getMaxHealth());
                        }
                        continue;
                    } else {
                        state.setState("title");
                        plr.gotoStart();
                        continue;
                    }

                } else {
                    cout << "You attempt to go forth but ..." << endl;
                    state.battle(currentDungeon);
                }
                break;

            case 2:
                // inspect the room (treasure)
                state.inspectDungeon(&currentDungeon,plrAddr,&entity, &treasure);
                break;
            case 3:
                // (SAVE)Camp for the Day 
                cout << "Enter save file name: " << endl;
                cin >> filename;
                outFile.open(filename);
                if (outFile.is_open()) {
                    outFile << /*"Player Lvl: " <<*/ plr.getLvl() << endl; 
                    outFile << /*"Player Location [" <<*/ plr.getLocation()[0] << " " << plr.getLocation()[1] << endl;
                    outFile << /*"Player Health: " << */plr.getHealth() << endl;
                    outFile << /*"# of rest's remaining: " <<*/ plr.getRests() << endl; 
                    outFile.close();
                } else {
                    cout << "ERROR: File could not be opened" << endl;
                }
                
                break;
            case 4:
            //Rest refills your health
                if (plr.getRests() > 0) {
                    plr.setRests(plr.getRests() - 1);
                    cout << "You have rested you have " << plr.getRests() << " remaining." << endl;
                } else {
                    cout << "You have no rests remaining." << endl;
                }
                break;
            default:
                //print status
                cout << "You idle . . \n" << endl;
                break;
            }
            state.setPreviousState("dungeon");
        } else if (state.getState() == "battle") {
            if (state.getPreviousState() != state.getState()) {
                entity = currentDungeon.getEntity();
            }
            // Enemy = &enemy;
            print.battleStatus(entity, plr);
            if (state.getTurn() == 1){
                currentDungeon.getEntity().attack(entity.getMoveAt(0), plrAddr);
                state.changeTurn();
            }
            if (plr.getHealth() <= 0 || entity.getHealth() <= 0) {
                if (plr.getHealth() <= 0) {
                    state.setState("title");
                    plr.setMoney(0);
                    cout << "You lost all your money" << endl;
                    //set Health to full
                } else {
                    state.setState("dungeon");
                    plr.setLevel(plr.getLvl() + ((rand() % 3) + 1));
                    cout << "You have leveled up!!" << endl;
                    map.clearRoom(plr.getLocation());
                }
                continue;
            } 
            print.moveDisplay(plr);
            cin >> input;
            switch (input)
            {
            case 1:
                // use move 1
                plr.attack(plr.getMoveAt(0), &entity);
                state.changeTurn();
                break;
            case 2:
                // use move 2
                plr.attack(plr.getMoveAt(1), &entity);
                state.changeTurn();
                break;
            case 3:
                // move 3
                plr.attack(plr.getMoveAt(2), &entity);
                state.changeTurn();
                break;
            case 4:
                plr.attack(plr.getMoveAt(3), &entity);
                state.changeTurn();
                break;
            case 5:
                //Run away you lose ur prgoress 
                if (rand() % 2 == 0) {
                    cout << "You Ran Away!" << endl;
                    state.setState("title");
                }
                break;
            default:
                //print status
                cout << "INVALID INPUT" << endl;
                break;
            }
            if (plr.getHealth() <= 0 || entity.getHealth() <= 0) {
                if (plr.getHealth() <= 0) {
                    state.setState("title");
                    plr.setMoney(0);
                    cout << "You lost all your money" << endl;
                } else {
                    state.setState("dungeon");
                    plr.setLevel(plr.getLvl() + ((rand() % 3) + 1));
                    cout << "You have leveled up!!" << endl;
                    //clear dungeon
                    map.clearRoom(plr.getLocation());
                }
                continue;
            } 
            state.setPreviousState("battle");
        }
    }
    
    return 0;
}