#ifndef UNSORTEDTYPE_H
#define UNSORTEDTYPE_H
#include "ItemType.h"

const int MAX_ITEMS = 5;

struct NodeType
{
    ItemType _info;
    NodeType* _next;
};

class UnsortedType
{
    private:
        NodeType* _list_data;
        int _length;
        NodeType* _current_pos;

    public:
        UnsortedType();
        ~UnsortedType();
        void make_empty();
        int get_length();
        bool is_full();
        ItemType get_item(ItemType item, bool& found);
        void insert_item(ItemType i);
        void delete_item(ItemType i);
        void reset_list();
        ItemType get_next_item();
};

#endif