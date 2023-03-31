#ifndef QUEUETYPE_H
#define QUEUETYPE_H

#include <iostream>

template <class ItemType>
struct NodeType
{
    ItemType info;
    NodeType* next;
};

class FullQueue{};
class EmptyQueue{};

template <class ItemType>
class QueueType
{
    public:
        QueueType();
        ~QueueType();
        void make_empty();
        void enqueue(ItemType);
        void dequeue(ItemType&);
        bool is_empty();
        bool is_full();

    private:
        NodeType<ItemType>* front;
        NodeType<ItemType>* rear;
};

#endif