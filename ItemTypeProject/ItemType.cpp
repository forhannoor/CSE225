#include "ItemType.h"

ItemType::ItemType()
{
    _value = 0;
}

RelationType ItemType::compared_to(ItemType other_item)
{
    if(_value > other_item._value)
    {
        return GREATER;
    }
    else if(_value < other_item._value)
    {
        return LESS;
    }

    return EQUAL;
}

void ItemType::print(std::ofstream& ofs)
{
    ofs << _value << "\n";
}

void ItemType::initialize(int number)
{
    _value = number;
}