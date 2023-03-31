#include<cstdio>
#include<cstring>

#define TABLE_SIZE 128

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
    private:
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

    void insert(int key, int value)
    {
        int h = hash_key(key);

        if (table[h])
        {
            HashNode* current = table[h];
            HashNode* previous = NULL;

            while (current)
            {
                previous = current;
                current = current->next;
            }

            previous->next = new HashNode(key, value);
        }

        else
        {
            HashNode* _new = new HashNode(key, value);
            table[h] = _new;
        }
    }

    int search(int key)
    {
        int h = hash_key(key);
        HashNode* current = table[h];

        if (current == 0)
        {
            printf("Element not found\n");
            return -1;
        }

        while (current->key != key)
        {
            current = current->next;

            if (!current)
            {
                printf("Element not found\n");
                return -1;
            }
        }

        printf("Element found\n");
        return current->value;
    }

};

int main()
{
    Hash h;

    while (true)
    {
        int choice;
        printf("Select action:-\n1-Insert element\n2-Search element\n3-Exit\n");
        scanf("%d", &choice);

        if (choice == 1)
        {
            int key, value;
            printf("Enter key:\n");
            scanf("%d", &key);
            printf("Enter value:\n");
            scanf("%d", &value);
            h.insert(key, value);
        }

        else if (choice == 2)
        {
            int key;
            printf("Enter key:\n");
            scanf("%d", &key);
            printf("%d\n", h[key]);
        }

        else if (choice == 3)
        {
            break;
        }

        else
        {
            printf("Invalid option\n");
        }
    }

    return 0;
}