#include "UnsortedType.h"

UnsortedType::UnsortedType()
{
    length = 0;
    currentPos = -1;
}

void UnsortedType::MakeEmpty()
{
    length = 0;
    currentPos = -1;
}

int UnsortedType::GetLength()
{
    return length;
}

bool UnsortedType::isFull()
{
    return (length == MAX_ITEMS);
}

void UnsortedType::GetItem(ItemType &item, bool &found)
{
    found = false;

    for(int i = 0; i < length; i++)
    {
        if(info[i].ComparedTo(item) == EQUAL)
        {
            item = info[i];
            found = true;
            break;
        }
    }
}

void UnsortedType::InsertItem(ItemType i)
{
    currentPos++;

    if(currentPos < length)
    {
        info[currentPos] = i;
    }
}

void UnsortedType::DeleteItem(ItemType i)
{
    int location = 0;

    while(info[location].ComparedTo(i) != EQUAL)
    {
        location++;
    }

    info[location] = info[length - 1];
    length--;
}

void UnsortedType::ResetList()
{
    currentPos = -1;
}

ItemType UnsortedType::GetNextItem()
{
    currentPos++;
    return info[currentPos];
}