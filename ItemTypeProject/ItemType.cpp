#include "ItemType.h"

ItemType::ItemType()
{
    value = 0;
}

RelationType ItemType::ComparedTo(ItemType otherItem)
{
    if(value > otherItem.value)
    {
        return GREATER;
    }

    else if(value < otherItem.value)
    {
        return LESS;
    }

    return EQUAL;
}

void ItemType::Print(std::ofstream &o)
{
    o << value << "\n";
}

void ItemType::Initialize(int number)
{
    value = number;
}