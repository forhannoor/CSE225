#include "queuetype.h"

template <class ItemType>
QueueType<ItemType>::QueueType()
{
    front = rear = NULL;
}

template <class ItemType>
QueueType<ItemType>::~QueueType()
{
    MakeEmpty();
}

template <class ItemType>
void QueueType<ItemType>::MakeEmpty()
{
    NodeType<ItemType> *temp;

    while(front != NULL)
    {
        temp = front;
        front = front->next;
        delete temp;
    }

    rear = NULL;
}

template <class ItemType>
void QueueType<ItemType>::Enqueue(ItemType i)
{
    if(IsFull())
    {
        throw FullQueue();
    }

    else
    {
        NodeType<ItemType> *location;
        location = new NodeType<ItemType>;
        location->info = i;
        location->next = NULL;

        if(rear == NULL)
            front = location;

        else
            rear->next = location;

        rear = location;
    }
}

template <class ItemType>
void QueueType<ItemType>::Dequeue(ItemType &i)
{
    if(IsEmpty())
    {
        throw EmptyQueue();
    }

    else
    {
        NodeType<ItemType> *temp;
        temp = front;
        i = front->info;
        front = front->next;

        if(front == NULL)
            rear == NULL;

        delete temp;
    }
}

template <class ItemType>
bool QueueType<ItemType>::IsEmpty()
{
    return (front == NULL);
}

template<class ItemType>
bool QueueType<ItemType>::IsFull()
{
    NodeType<ItemType>* location;
    try
    {
        location = new NodeType<ItemType>;
        delete location;
        return false;
    }
    catch(bad_alloc& exception)
    {
        return true;
    }
}