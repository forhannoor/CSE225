#ifndef STACKTYPE_H
#define STACKTYPE_H
#include <iostream>

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
        void push(ItemType item);
        void pop();
        ItemType top();
        bool is_empty();
        bool is_full();
    private:
        NodeType<ItemType>* _top_ptr;
};

#endif