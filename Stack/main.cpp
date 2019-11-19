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
    s.printStack();
    i.initialize(3);
    s.push(i);
    s.printStack();
    s.pop();
    s.printStack();
    s.pop();
    s.printStack();
    s.Top().print();
    printf("%d\n", s.sumOdd());
    return 0;
}