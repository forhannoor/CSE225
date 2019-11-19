#ifndef ITEMTYPE_H
#define ITEMTYPE_H

#include <fstream>
#include <iostream>

enum RelationType {LESS, GREATER, EQUAL};

class ItemType
{
    private:
        int value;

    public:
        ItemType();
        RelationType ComparedTo(ItemType otherItem);
        void Print(std::ofstream &o);
        void Initialize(int number);
};

#endif // ITEMTYPE_H