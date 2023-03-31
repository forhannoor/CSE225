#include "unsortedtype.h"

UnsortedType::UnsortedType()
{
    length = 0;
    currentPos = -1;
}

void UnsortedType::MakeEmpty()
{
 	length = 0;
}

bool UnsortedType::IsFull()
{
    return (length == MAX_ITEMS);
}

int UnsortedType::LengthIs()
{
    return length;
}

void UnsortedType::ResetList()
{
    currentPos = -1;
}

void UnsortedType::GetNextItem(ItemType &i)
{
    i = info [++currentPos] ;
}