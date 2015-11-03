#include "QueueType.h"

template <class ItemType>
QueueType<ItemType>::QueueType(){}

template <class ItemType>
QueueType<ItemType>::~QueueType(){}

template <class ItemType>
void QueueType<ItemType>::Enqueue(ItemType item)
{
    BLACK.Push(item);
}

template <class ItemType>
ItemType QueueType<ItemType>::Dequeue()
{
    ItemType i;

    if(WHITE.IsEmpty())
    {
        while(! BLACK.IsEmpty())
        {
            ItemType temp = BLACK.Top();
            BLACK.Pop();
            WHITE.Push(temp);
        }
    }

    i = WHITE.Top();
    WHITE.Pop();

    return i;
}