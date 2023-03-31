#include "QueueType.cpp"
#include <cstdio>

int main()
{
    QueueType<int> q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    printf("%d\n", q.dequeue());
    printf("%d\n", q.dequeue());
    printf("%d\n", q.dequeue());
    printf("%d\n", q.dequeue());
    return 0;
}