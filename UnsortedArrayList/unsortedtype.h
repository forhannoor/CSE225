#ifndef UNSORTEDTYPE_H
#define UNSORTEDTYPE_H
#include "itemtype.h"

class UnsortedType
{
    public :
        UnsortedType();
        void MakeEmpty();
        bool IsFull();
        int LengthIs();
        void ResetList();
        void GetNextItem(ItemType &i);
        void InsertItem(ItemType i);
        void RetrieveItem(ItemType &i, bool &found);
        void DeleteItem(ItemType i);

    private:
        int length;
        ItemType info[MAX_ITEMS];
        int currentPos;
};

#endif // UNSORTEDTYPE_H