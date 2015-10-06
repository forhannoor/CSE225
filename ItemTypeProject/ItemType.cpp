#include "ItemType.h"

ItemType::ItemType()
{
    value = 0;
}

RelationType ItemType::ComparedTo(ItemType otherItem)
{
    if(value > otherItem.value)
        return GREATER;

    else if(value < otherItem.value)
        return LESS;

    return EQUAL;
}

void ItemType::Print(ofstream &o)
{
    o<<value<<endl;
}

void ItemType::Initialize(int number)
{
    value = number;
}