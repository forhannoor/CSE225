#include "stacktype.h"

int main()
{
    StackType s;
    ItemType i;
    i.initialize(5);
    s.push(i);
    i.initialize(7);
    s.push(i);
    i.initialize(4);
    s.push(i);
    i.initialize(2);
    s.push(i);
    s.print_stack();
    i.initialize(3);
    s.push(i);
    s.print_stack();
    s.pop();
    s.print_stack();
    s.pop();
    s.print_stack();
    s.top().print();
    printf("%d\n", s.sum_odd());
    return 0;
}