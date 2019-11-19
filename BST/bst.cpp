#include "bst.h"

template <class ItemType>
BST<ItemType>::BST()
{
    root = NULL;
}

template <class ItemType>
BST<ItemType>::~BST()
{
    destroy(root);
}

template <class ItemType>
void destroy(BST<ItemType> *bst)
{
    if(bst != NULL)
    {
        destroy(bst->left);
        destroy(bst->right);
        delete bst;
        bst = NULL;
    }
}

template <class ItemType>
void BST<ItemType>::makeEmpty()
{
    destroy(root);
}

template <class ItemType>
bool BST<ItemType>::isEmpty()
{
    return (root == NULL);
}

template <class ItemType>
bool BST<ItemType>::isFull()
{
    BST<ItemType> *b;

    try
    {
        b = new BST();
        delete b;
        return false;
    }
    catch(std::bad_alloc e)
    {
        return true;
    }
}

template <class ItemType>
int BST<ItemType>::length()
{
    return countNode(root);
}

template <class ItemType>
int countNode(BST<ItemType> *b)
{
    if(b->getRoot() == NULL)
        return 0;

    else
        return countNode(b->getRoot()->left) + countNode(b->getRoot()->right) + 1;
}

template <class ItemType>
Node<ItemType> BST<ItemType>::getRoot()
{
    return root;
}

template <class ItemType>
ItemType BST<ItemType>::retrieve(ItemType i)
{
    return retrieveItem(root, i);
}

template <class ItemType>
ItemType retrieveItem(BST<ItemType> *b, ItemType i)
{
    ItemType x = NULL;

    if(b->getRoot() == NULL)
        return NULL;

    else if(i < b->info)
        return retrieveItem(b->left, i);

    else if(i > b->info)
        return retrieveItem(b->right, i);

    else
    {
        x = b->info;
        return x;
    }
}

template <class ItemType>
void Insert(BST<ItemType>*& tree, ItemType item)
{
    if (tree == NULL)
    {
        tree = new BST<ItemType>;
        tree->right = NULL;
        tree->left = NULL;
        tree->info = item;
    }

    else if (item < tree->info)
        Insert(tree->left, item);

    else
        Insert(tree->right, item);
}

template <class ItemType>
void BST<ItemType>::insertItem(ItemType item)
{
    Insert(root, item);
}