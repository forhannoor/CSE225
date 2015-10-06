#ifndef UNSORTEDTYPE_H
#define UNSORTEDTYPE_H

#include "ItemType.h"

const int MAX_ITEMS = 5;

struct NodeType
{
    ItemType info;
    NodeType *next;
};

class UnsortedType
{
    private:
        NodeType *listData;
        int length;
        NodeType *currentPos;

    public:
        UnsortedType();
        ~UnsortedType();
        void MakeEmpty();
        int GetLength();
        bool isFull();
        ItemType GetItem(ItemType item, bool &found);
        void InsertItem(ItemType i);
        void DeleteItem(ItemType i);
        void ResetList();
        ItemType GetNextItem();
};

#endif // UNSORTEDTYPE_H