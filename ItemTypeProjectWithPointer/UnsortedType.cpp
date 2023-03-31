#include "UnsortedType.h"

UnsortedType::UnsortedType()
{
    _length = 0;
    _list_data = NULL;
    _current_pos = NULL;
}

UnsortedType::~UnsortedType()
{
    NodeType* temp_ptr;

    while (_list_data != NULL)
    {
        temp_ptr = _list_data;
        _list_data = _list_data->_next;
        delete temp_ptr;
    }
}

void UnsortedType::make_empty()
{
    NodeType* temp_ptr;

    while(_list_data != NULL)
    {
        temp_ptr = _list_data;
        _list_data = _list_data->_next;
        delete temp_ptr;
    }

    _length = 0;
}

int UnsortedType::get_length()
{
    return _length;
}

bool UnsortedType::is_full()
{
    NodeType* location;

    try
    {
        location = new NodeType;
        delete location;
        return false;
    }
    catch(std::bad_alloc exception)
    {
        return true;
    }
}

ItemType UnsortedType::get_item(ItemType item, bool& found)
{
    found = false;
    bool can_search = false;
    NodeType* location;
    location = _list_data;
    can_search = (location != NULL);

    while(can_search && !found)
    {
        if(item.compared_to(location->_info) == GREATER || item.compared_to(location->_info) == LESS)
        {
            location = location->_next;
            can_search = (location != NULL);
        }
        else
        {
            found = true;
            item = location->_info;
        }
    }
}

void UnsortedType::insert_item(ItemType i)
{
    NodeType* location;
    location = new NodeType;
    location->_info = i;
    location->_next = _list_data;
}

void UnsortedType::delete_item(ItemType i)
{
    NodeType* location = _list_data;
    NodeType* temp_location;

    if(i.compared_to(location->_info) == EQUAL)
    {
        temp_location = location;
        _list_data = _list_data->_next;
    }
    else
    {
        while(i.compared_to((location->_next)->_info) != EQUAL)
        {
            location = location->_next;
            temp_location = location->_next;
            location->_next = (location->_next)->_next;
        }

        delete temp_location;
        --_length;
    }
}

void UnsortedType::reset_list()
{
    _current_pos = NULL;
}

ItemType UnsortedType::get_next_item()
{
    ItemType item;

    if(_current_pos == NULL)
        _current_pos = _list_data;
    else
        _current_pos = _current_pos->_next;

    item = _current_pos->_info;
    return item;
}