#include "QueueType.cpp"
#include <iostream>

int main()
{
    QueueType<int> q;
    q.Enqueue(1);
    q.Enqueue(2);
    q.Enqueue(3);
    q.Enqueue(4);
    std::cout<<q.Dequeue();
    std::cout<<q.Dequeue();
    std::cout<<q.Dequeue();
    std::cout<<q.Dequeue();
    return 0;
}