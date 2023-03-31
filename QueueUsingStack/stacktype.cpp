#include "stacktype.h"

template <class ItemType>
StackType<ItemType>::StackType()
{
    _top_ptr = NULL;
}

template <class ItemType>
StackType<ItemType>::~StackType()
{
    NodeType <ItemType>* temp;

    while(_top_ptr != NULL)
    {
        temp = _top_ptr;
        _top_ptr = _top_ptr->_next;
        delete temp;
    }
}

template <class ItemType>
void StackType<ItemType>::push(ItemType i)
{
    if(is_full())
    {
        throw FullStack();
    }
    else
    {
        NodeType<ItemType>* location;
        location = new NodeType<ItemType>;
        location->_info = i;
        location->_next = _top_ptr;
        _top_ptr = location;
    }
}

template <class ItemType>
void StackType<ItemType>::pop()
{
    if(is_empty())
    {
        throw EmptyStack();
    }
    else
    {
        NodeType<ItemType>* temp;
        temp = _top_ptr;
        _top_ptr = _top_ptr->_next;
        delete temp;
    }
}

template <class ItemType>
ItemType StackType<ItemType>::top()
{
    if(is_empty())
    {
        throw EmptyStack();
    }
    else
    {
        return _top_ptr->_info;
    }
}

template <class ItemType>
bool StackType<ItemType>::is_empty()
{
    return (_top_ptr == NULL);
}

template <class ItemType>
bool StackType<ItemType>::is_full()
{
    NodeType<ItemType>* location;

    try
    {
        location = new NodeType<ItemType>;
        delete location;
        return false;
    }
    catch(std::bad_alloc e)
    {
        return true;
    }
}