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
        void MakeEmpty();
        void Enqueue(ItemType);
        void Dequeue(ItemType&);
        bool IsEmpty();
        bool IsFull();
    private:
        NodeType<ItemType> *front;
        NodeType<ItemType> *rear;
};

#endif // QUEUETYPE_H