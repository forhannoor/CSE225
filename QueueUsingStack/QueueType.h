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
        void Enqueue(ItemType item);
        ItemType Dequeue();
};

#endif // QUEUETYPE_H