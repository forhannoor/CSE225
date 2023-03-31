#ifndef ITEMTYPE_H
#define ITEMTYPE_H
#include<cstdio>

const int MAX_ITEMS = 5;
enum RelationType {LESS, GREATER, EQUAL};

class ItemType
{
    public:
        ItemType();
        RelationType ComparedTo(ItemType i);
        void Print();
        void Initialize(int number);

    private:
        int value;
};

#endif