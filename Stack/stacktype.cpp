#include "stacktype.h"

StackType::StackType()
{
    _top = -1;
}

bool StackType::is_full()
{
    return (_top == MAX_ITEMS - 1);
}

bool StackType::is_empty()
{
    return (_top == -1);
}

void StackType::push(ItemType i)
{
    if(! is_full())
    {
        _items[++_top] = i;
    }
}

void StackType::pop()
{
    if(! is_empty())
    {
        --_top;
    }
}

ItemType StackType::top()
{
    if(! is_empty())
    {
        return _items[_top];
    }
}

void StackType::print_stack()
{
    for(int i = _top; i >= 0; --i)
    {
        _items[i].print();
    }

    printf("\n");
}

int StackType::sum_odd()
{
    int sum = 0;

    for(int i = _top; i >= 0; --i)
    {
        if(_items[i].get_value() % 2 == 1)
        {
            sum += _items[i].get_value();
        }
    }

    return sum;
}