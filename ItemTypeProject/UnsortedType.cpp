#include "UnsortedType.h"

UnsortedType::UnsortedType()
{
    _length = 0;
    _current_pos = -1;
}

void UnsortedType::make_empty()
{
    _length = 0;
    _current_pos = -1;
}

int UnsortedType::get_length()
{
    return _length;
}

bool UnsortedType::is_full()
{
    return (_length == MAX_ITEMS);
}

void UnsortedType::get_item(ItemType& item, bool& found)
{
    found = false;

    for(int i = 0; i < _length && !found; ++i)
    {
        if(_info[i].compared_to(item) == EQUAL)
        {
            item = _info[i];
            found = true;
        }
    }
}

void UnsortedType::insert_item(ItemType i)
{
    ++_current_pos;

    if(_current_pos < _length)
    {
        _info[_current_pos] = i;
    }
}

void UnsortedType::delete_item(ItemType i)
{
    int location = 0;

    while(_info[location].compared_to(i) != EQUAL)
    {
        ++location;
    }

    _info[location] = _info[_length - 1];
    --_length;
}

void UnsortedType::reset_list()
{
    _current_pos = -1;
}

ItemType UnsortedType::get_next_item()
{
    ++_current_pos;
    return _info[_current_pos];
}