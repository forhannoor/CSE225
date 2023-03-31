#include "unsortedtype.h"

UnsortedType::UnsortedType()
{
    _length = 0;
    _current_pos = -1;
}

void UnsortedType::make_empty()
{
 	_length = 0;
}

bool UnsortedType::is_full()
{
    return (_length == MAX_ITEMS);
}

int UnsortedType::get_length()
{
    return _length;
}

void UnsortedType::reset_list()
{
    _current_pos = -1;
}

void UnsortedType::get_next_item(ItemType& i)
{
    i = _info[++_current_pos];
}