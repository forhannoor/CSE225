#include "QueueType.h"

template <class ItemType>
QueueType<ItemType>::QueueType(){}

template <class ItemType>
QueueType<ItemType>::~QueueType(){}

template <class ItemType>
void QueueType<ItemType>::enqueue(ItemType item)
{
    BLACK.push(item);
}

template <class ItemType>
ItemType QueueType<ItemType>::dequeue()
{
    ItemType i;

    if(WHITE.is_empty())
    {
        while(! BLACK.is_empty())
        {
            ItemType temp = BLACK.top();
            BLACK.pop();
            WHITE.push(temp);
        }
    }

    i = WHITE.top();
    WHITE.pop();
    return i;
}