#ifndef ITEMTYPE_H
#define ITEMTYPE_H
#include <cstdio>

const int MAX_ITEMS = 5;

class ItemType
{
    private:
        int value;

    public:
        ItemType();
        int get_value();
        void initialize(int v);
        void print();
};

#endif