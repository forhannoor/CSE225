#include "QueueType.cpp"

int main()
{
    QueueType<int> q;
    q.Enqueue(1);
    q.Enqueue(2);
    q.Enqueue(3);
    q.Enqueue(4);
    cout<<q.Dequeue();
    cout<<q.Dequeue();
    cout<<q.Dequeue();
    cout<<q.Dequeue();
    return 0;
}