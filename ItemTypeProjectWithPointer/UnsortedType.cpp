#include "UnsortedType.h"

UnsortedType::UnsortedType()
{
    length = 0;
    listData = NULL;
    currentPos = NULL;
}

UnsortedType::~UnsortedType()
{
    NodeType* tempPtr;

    while (listData != NULL)
    {
        tempPtr = listData;
        listData = listData->next;
        delete tempPtr;
    }
}

void UnsortedType::MakeEmpty()
{
    NodeType *tempPtr;

    while(listData != NULL)
    {
        tempPtr = listData;
        listData = listData->next;
        delete tempPtr;
    }

    length = 0;
}

int UnsortedType::GetLength()
{
    return length;
}

bool UnsortedType::isFull()
{
    NodeType *location;

    try
    {
        location = new NodeType;
        delete location;
        return false;
    }
    catch(bad_alloc exception)
    {
        return true;
    }
}

ItemType UnsortedType::GetItem(ItemType item, bool &found)
{
    found = false;
    bool moreToSearch = false;
    NodeType *location;
    location = listData;
    moreToSearch = (location != NULL);

    while(moreToSearch && !found)
    {
        if(item.ComparedTo(location->info) == GREATER || item.ComparedTo(location->info) == LESS)
        {
            location = location->next;
            moreToSearch = (location != NULL);
        }

        else
        {
            found = true;
            item = location->info;
        }
    }
}

void UnsortedType::InsertItem(ItemType i)
{
    NodeType *location;
    location = new NodeType;
    location->info = i;
    location->next = listData;
}

void UnsortedType::DeleteItem(ItemType i)
{
    NodeType *location = listData;
    NodeType *tempLocation;

    if(i.ComparedTo(location->info) == EQUAL)
    {
        tempLocation = location;
        listData = listData->next;
    }

    else
    {
        while(i.ComparedTo((location->next)->info) != EQUAL)
        {
            location = location->next;
            tempLocation = location->next;
            location->next = (location->next)->next;
        }

        delete tempLocation;
        length--;
    }
}

void UnsortedType::ResetList()
{
    currentPos = NULL;
}

ItemType UnsortedType::GetNextItem()
{
    ItemType item;

    if(currentPos == NULL)
        currentPos = listData;

    else
    {
        currentPos = currentPos->next;
    }

    item = currentPos->info;
    return item;
}