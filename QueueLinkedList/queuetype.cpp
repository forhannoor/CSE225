#include "queuetype.h"

template <class ItemType>
QueueType<ItemType>::QueueType()
{
    front = rear = NULL;
}

template <class ItemType>
QueueType<ItemType>::~QueueType()
{
    make_empty();
}

template <class ItemType>
void QueueType<ItemType>::make_empty()
{
    NodeType<ItemType>* temp;

    while(front != NULL)
    {
        temp = front;
        front = front->next;
        delete temp;
    }

    rear = NULL;
}

template <class ItemType>
void QueueType<ItemType>::enqueue(ItemType i)
{
    if(is_full())
    {
        throw FullQueue();
    }
    else
    {
        NodeType<ItemType>* location;
        location = new NodeType<ItemType>;
        location->info = i;
        location->next = NULL;

        if(rear == NULL)
        {
            front = location;
        }
        else
        {
            rear->next = location;
        }

        rear = location;
    }
}

template <class ItemType>
void QueueType<ItemType>::dequeue(ItemType &i)
{
    if(is_empty())
    {
        throw EmptyQueue();
    }
    else
    {
        NodeType<ItemType>* temp;
        temp = front;
        i = front->info;
        front = front->next;

        if(front == NULL)
        {
            rear == NULL;
        }

        delete temp;
    }
}

template <class ItemType>
bool QueueType<ItemType>::is_empty()
{
    return (front == NULL);
}

template<class ItemType>
bool QueueType<ItemType>::is_full()
{
    NodeType<ItemType>* location;

    try
    {
        location = new NodeType<ItemType>;
        delete location;
        return false;
    }
    catch(std::bad_alloc& exception)
    {
        return true;
    }
}