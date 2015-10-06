#ifndef UNSORTEDTYPE_H
#define UNSORTEDTYPE_H

#include "ItemType.h"

const int MAX_ITEMS = 5;

class UnsortedType
{
    private:
        ItemType info[MAX_ITEMS];
        int length;
        int currentPos;

    public:
        UnsortedType();
        void MakeEmpty();
        int GetLength();
        bool isFull();
        void GetItem(ItemType &i, bool &found);
        void InsertItem(ItemType i);
        void DeleteItem(ItemType i);
        void ResetList();
        ItemType GetNextItem();
};

#endif // UNSORTEDTYPE_H