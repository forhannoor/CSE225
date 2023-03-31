#include "itemtype.h"

ItemType::ItemType()
{
    _value = 0;
}

RelationType ItemType::compared_to(ItemType i)
{
    if (_value < i._value)
    {
        return LESS;
    }
    else if (_value > i._value)
    {
        return GREATER;
    }
    else
    {
        return EQUAL;
    }
}

void ItemType::initialize(int number)
{
    _value = number;
}

void ItemType::print()
{
    printf("%d ", _value);
}