#ifndef MAP_H
#define MAP_H
#include <iostream> 
using namespace std;
#include <chrono>
#include "Room.h"
#include "Enemy.h"
#include <cmath>
/*
This Class is something similar to a Room Manager.
*/
class Map {
    private:
        int advanceloc[2];
        int rooms;
        int floors;
        vector<vector<bool>> cleared;
        vector<vector<Room>> allRooms;
    public:
        Map(int _r = 4 , int _f = 4) {
            rooms =_r;
            floors = _f;
            srand(static_cast<unsigned int>(time(0)));
            for (int i = 0; i < floors; i++) {
                vector<Room> temp;
                vector<bool> tempB;
                allRooms.push_back(temp);
                cleared.push_back(tempB);
                for (int j = 0; j < rooms; j++) {
                    if (rand() % 3 == 1) {
                        allRooms[i].push_back(Room(randomEntity(i,j),rand() % 100, rand() % 3, rand() % 3));
                    } else {
                        allRooms[i].push_back(Room(randomEntity(i,j),0,0,-1));
                    }
                    cleared[i].push_back(false);
                }
            }
        }
        int getMaxRooms() {
            return rooms;
        }
        int getMaxFloors() {
            return floors;
        }
        Entity randomEntity(int floor, int room) {
            int randNum = rand() % 5;
            int loc[2] = {floor,room};
            if (randNum == 0){
                return (Entity(100, static_cast<int>(ceil(floor * (rand() % 9))),loc,"Charlie")); //TODO get random name Generator
            } else if (randNum < 4) {
                return Enemy(100, static_cast<int>(ceil(floor * (rand() % 9))),loc,"Not Charlie");
            } 
            return Entity();
        }
        Room getDungeon(int* loc) {
            return allRooms[loc[0]][loc[1]];
        }
        void clearRoom(int* loc) {
            allRooms[loc[0]][loc[1]].cleared();
        }
};

#endif