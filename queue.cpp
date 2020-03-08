#include <iostream>
using namespace std;

class Queue
{
    int rear;
    int front;
    int capacity;
    int size;
    int *arr;

public:
    Queue(int cap);
    void enQueue(int num);
    int deQueue();
    bool isEmpty();
    bool isFull();
};
Queue::Queue(int cap)
{
    size = 0;
    capacity = cap;
    front = 0;
    rear = cap - 1;
    arr = new int[capacity];
}
void Queue::enQueue(int num)
{
    if (isFull())
    {
        cout << "Stackoverflow" << endl;
        return;
    }

    rear = (rear + 1) % capacity;
    arr[rear] = num;
    size++;
    cout << num << " is enqueued" << endl;
}
int Queue::deQueue()
{
    if (isEmpty())
    {
        cout << "Queue is empty" << endl;
        return -1;
    }

    int num = arr[front];
    front = (front + 1) % capacity;
    size--;
    return num;
}
bool Queue::isEmpty()
{
    if (size == 0)
    {
        return true;
    }
    return false;
}
bool Queue::isFull()
{
    if (size == capacity)
    {
        return true;
    }
    return false;
}
void report(Queue queue)
{
    cout << "Queue: " << endl;
    cout << "Empty: " << queue.isEmpty() << endl;
    cout << "Full: " << queue.isFull() << endl;
    while (!queue.isEmpty())
    {
        int num = queue.deQueue();
        cout << num << " ";
    }
    cout << endl;
}
int main()
{
    Queue queue1(5);
    queue1.enQueue(5);
    queue1.enQueue(234);
    queue1.enQueue(324);
    queue1.enQueue(123);
    queue1.enQueue(546);
    queue1.enQueue(398);
    report(queue1);
    queue1.deQueue();
    queue1.deQueue();
    queue1.deQueue();
    queue1.deQueue();
    queue1.deQueue();
    queue1.deQueue();
    report(queue1);
}
