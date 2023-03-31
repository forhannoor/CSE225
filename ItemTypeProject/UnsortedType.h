#ifndef UNSORTEDTYPE_H
#define UNSORTEDTYPE_H
#include "ItemType.h"

const int MAX_ITEMS = 5;

class UnsortedType
{
    private:
        ItemType _info[MAX_ITEMS];
        int _length;
        int _current_pos;

    public:
        UnsortedType();
        void make_empty();
        int get_length();
        bool is_full();
        void get_item(ItemType& i, bool& found);
        void insert_item(ItemType i);
        void delete_item(ItemType i);
        void reset_list();
        ItemType get_next_item();
};

#endif