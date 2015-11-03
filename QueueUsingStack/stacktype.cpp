#include "stacktype.h"

template <class ItemType>
StackType<ItemType>::StackType()
{
    topPtr = NULL;
}

template <class ItemType>
StackType<ItemType>::~StackType()
{
    NodeType <ItemType> *temp;

    while(topPtr != NULL)
    {
        temp = topPtr;
        topPtr = topPtr->next;
        delete temp;
    }
}

template <class ItemType>
void StackType<ItemType>::Push(ItemType i)
{
    if(IsFull())
    {
        throw FullStack();
    }

    else
    {
        NodeType<ItemType> * location;
        location = new NodeType<ItemType>;
        location->info = i;
        location->next = topPtr;
        topPtr = location;
    }
}

template <class ItemType>
void StackType<ItemType>::Pop()
{
    if(IsEmpty())
    {
        throw EmptyStack();
    }

    else
    {
        NodeType<ItemType> * temp;
        temp = topPtr;
        topPtr = topPtr->next;
        delete temp;
    }
}

template <class ItemType>
ItemType StackType<ItemType>::Top()
{
    if(IsEmpty())
    {
        throw EmptyStack();
    }

    else
    {
        return topPtr->info;
    }
}

template <class ItemType>
bool StackType<ItemType>::IsEmpty()
{
    return (topPtr == NULL);
}

template <class ItemType>
bool StackType<ItemType>::IsFull()
{
    NodeType<ItemType> *location;

    try
    {
        location = new NodeType<ItemType>;
        delete location;
        return false;
    }
    catch(bad_alloc e)
    {
        return true;
    }
}