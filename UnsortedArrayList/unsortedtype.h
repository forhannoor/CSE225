#ifndef UNSORTEDTYPE_H
#define UNSORTEDTYPE_H
#include "itemtype.h"

class UnsortedType
{
    public :
        UnsortedType();
        void make_empty();
        bool is_full();
        int get_length();
        void reset_list();
        void get_next_item(ItemType& i);
        void insert_item(ItemType i);
        void retrieve_item(ItemType& i, bool& found);
        void delete_item(ItemType i);

    private:
        int _length;
        ItemType _info[MAX_ITEMS];
        int _current_pos;
};

#endif