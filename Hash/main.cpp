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
        // Constructor.
        Hash()
        {
            table = new HashNode * [TABLE_SIZE];
            memset(table, 0, TABLE_SIZE * sizeof(HashNode*));
        }

        // Overloaded [] operator.
        int operator [](int key)
        {
            return (this->search(key));
        }

        // Returns hash key.
        int hash_key(int k)
        {
            return (k % TABLE_SIZE);
        }

        // Inserts a value given its key/hash.
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

        // Searches for a key and returns its value.
        int search(int key)
        {
            int h = hash_key(key);
            HashNode* current = table[h];

            if (current == 0)
            {
                printf("Element not found\n");
                return -1;
            }

            // While a matching key is not found.
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
    Hash hash;

    while (true)
    {
        int choice;
        printf("Select an action from list below:-\n\n1-Insert element\n2-Search element\n3-Exit\n");
        scanf("%d", &choice);

        if (choice == 1)
        {
            int key, value;
            printf("\n\nEnter key:\n");
            scanf("%d", &key);
            printf("Enter value:\n");
            scanf("%d", &value);
            hash.insert(key, value);
            printf("Inserted element\n\n");
        }
        else if (choice == 2)
        {
            int key;
            printf("Enter key:\n");
            scanf("%d", &key);
            printf("%d\n\n", hash[key]);
        }
        else if (choice == 3)
        {
            printf("\n\nTerminated program!\n\n");
            break;
        }
    }

    return 0;
}