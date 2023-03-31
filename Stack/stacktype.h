#ifndef STACKTYPE_H
#define STACKTYPE_H
#include <cstdio>
#include "itemtype.h"

class StackType
{
    private:
        ItemType _items[MAX_ITEMS];
        int _top;

    public:
        StackType();
        bool is_full();
        bool is_empty();
        void push(ItemType i);
        void pop();
        ItemType top();
        void print_stack();
        int sum_odd();
};

#endif