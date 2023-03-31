#ifndef STACKTYPE_H
#define STACKTYPE_H

#include "itemtype.h"
#include <cstdio>

class StackType
{
    private:
        ItemType items[MAX_ITEMS];
        int top;

    public:
        StackType();
        bool isFull();
        bool isEmpty();
        void push(ItemType i);
        void pop();
        ItemType Top();
        void printStack();
        int sumOdd();
};

#endif // STACKTYPE_H