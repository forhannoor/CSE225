#ifndef STACKTYPE_H
#define STACKTYPE_H

#include <iostream>
using namespace std;

template <class ItemType>
struct NodeType
{
    ItemType info;
    NodeType* next;
};

class FullStack{};
class EmptyStack{};

template <class ItemType>
class StackType
{
    public:
        StackType();
        ~StackType();
        void Push(ItemType);
        void Pop();
        ItemType Top();
        bool IsEmpty();
        bool IsFull();
    private:
        NodeType<ItemType>* topPtr;
};

#endif // STACKTYPE_H