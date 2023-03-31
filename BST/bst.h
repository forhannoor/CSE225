#ifndef BST_H
#define BST_H

#include <iostream>
#include "queuetype.h"

template <class ItemType>
struct Node
{
    int info;
    Node *left;
    Node *right;
};

template <class ItemType>
class BST
{
    private:
        Node<ItemType> *root;

    public:
        BST();
        ~BST();
        void makeEmpty();
        bool isEmpty();
        bool isFull();
        int length();
        ItemType retrieve(ItemType item);
        void insertItem(ItemType item);
        void deleteItem(ItemType item);
        void print();
        Node<ItemType> getRoot();
};

#endif