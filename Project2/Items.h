#ifndef ITEMS_H
#define ITEMS_H
#include <iostream>
using namespace std;
class Item
{
private:
    string name;
    float boost; 
public:
    Item() {
        name = "";
        boost = 1;
    }

    Item(string n, float b) {
        name = n;
        boost = b;
    }
    string getName() {return name;}
    float getBoost() {return boost;}
};
#endif