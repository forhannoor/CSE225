#ifndef ITEMTYPE_H
#define ITEMTYPE_H
#include <fstream>
#include <iostream>

enum RelationType {LESS, GREATER, EQUAL};

class ItemType
{
    private:
        int _value;

    public:
        ItemType();
        RelationType compared_to(ItemType other_item);
        void print(std::ofstream& ofs);
        void initialize(int number);
};

#endif