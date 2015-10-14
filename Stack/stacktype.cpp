#include "stacktype.h"

StackType::StackType()
{
    top = -1;
}

bool StackType::isFull()
{
    return (top == MAX_ITEMS - 1);
}

bool StackType::isEmpty()
{
    return (top == -1);
}

void StackType::push(ItemType i)
{
    if(! isFull())
    {
        top++;
        items[top] = i;
    }
}

void StackType::pop()
{
    if(! isEmpty())
        top--;
}

ItemType StackType::Top()
{
    if(! isEmpty())
        return items[top];
}

void StackType::printStack()
{
    for(int i = top; i >= 0; i--)
        items[i].print();

    cout<<endl;
}

int StackType::sumOdd()
{
    int sum = 0;

    for(int i = top; i >= 0; i--)
        if(items[i].getValue() % 2 == 1)
            sum += items[i].getValue();

    return sum;
}