#include "itemtype.h"

ItemType::ItemType()
{
    value = 0;
}

RelationType ItemType::ComparedTo(ItemType i)
{
    if (value < i.value)
        return LESS;
    else if (value > i.value)
        return GREATER;
    else return EQUAL;
}

void ItemType::Initialize(int number)
{
    value = number;
}

void ItemType::Print()
{
    cout << value << " ";
}