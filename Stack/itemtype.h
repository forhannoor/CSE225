#ifndef ITEMTYPE_H
#define ITEMTYPE_H

#include <iostream>
using namespace std;

const int MAX_ITEMS = 5;

class ItemType
{
    private:
        int value;

    public:
        ItemType();
        int getValue();
        void initialize(int v);
        void print();
};

#endif // ITEMTYPE_H