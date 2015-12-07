#include<iostream>
#include<string.h>
#define TABLE_SIZE 128

using namespace std;


class HashNode
{
public:
    int key;
    int value;
    HashNode* next;
    HashNode(int k, int v):key(k), value(v), next(NULL){}
};

class Hash
{

    HashNode** table;
public:
    Hash()
    {
        table = new HashNode*[TABLE_SIZE];
        memset(table, 0, TABLE_SIZE*sizeof(HashNode*));
    }
    int operator[](int key)
    {
        return (this->search(key));
    }

    int hash_key(int k)
    {
        return (k % TABLE_SIZE);
    }

    void insert(int k, int v)
    {
        int h = hash_key(k);
        if (table[h])
        {
            HashNode* current = table[h];
            HashNode* previous = NULL;
            while (current)
            {
                previous = current;
                current = current->next;
            }
            previous->next = new HashNode(k, v);
        }
        else
        {
            HashNode* _new = new HashNode(k, v);
            table[h] = _new;
        }
    }

    int search(int k)
    {
        int h = hash_key(k);
        HashNode* current = table[h];
        if (current == 0)
        {
            cout<<"Element not found\n";
            return -1;
        }
        while (current->key != k)
        {
            current = current->next;
            if (!current)
            {
                cout<<"Element not found\n";
                return -1;
            }
        }
        cout<<"Element found\n";
        return current->value;
    }

};



int main()
{
    Hash h;
    while (true)
    {
        cout<<"Select action:-\n1-Insert element\n2-Search element\n3-Exit\n";
        int n;
        cin>>n;
        if (n == 1)
        {
            int key, value;
            cout<<"Enter key:\n";
            cin>>key;
            cout<<"Enter value:\n";
            cin>>value;
            h.insert(key, value);
        }
        else if (n == 2)
        {
            int key;
            cout<<"Enter key:\n";
            cin>>key;
            cout<<h[key]<<"\n";
        }
        else if (n == 3)
        {
            break;
        }
        else
        {
            cout<<"Invalid option\n";
        }
    }
    return 0;
}