#ifndef QUEUETYPE_H
#define QUEUETYPE_H
#include "stacktype.cpp"

template <class ItemType>
class QueueType
{
    private:
        StackType<ItemType> BLACK;
        StackType<ItemType> WHITE;

    public:
        QueueType();
        ~QueueType();
        void enqueue(ItemType item);
        ItemType dequeue();
};

#endif