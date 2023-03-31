#ifndef ITEMTYPE_H
#define ITEMTYPE_H
#include<cstdio>

const int MAX_ITEMS = 5;
enum RelationType {LESS, GREATER, EQUAL};

class ItemType
{
    public:
        ItemType();
        RelationType compared_to(ItemType i);
        void print();
        void initialize(int number);

    private:
        int _value;
};

#endif