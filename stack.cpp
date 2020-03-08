#include <iostream>
#define MAX_SIZE 1000
using namespace std;
class stack
{
    int top;

public:
    void push(int);
    int pop();
    int peek();
    stack() { top = -1; }
    int arr[MAX_SIZE];
    bool isEmpty();
};
bool stack::isEmpty()
{
    if (top < 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int stack::peek()
{
    return arr[top];
}
void stack::push(int num)
{
    if (top >= MAX_SIZE - 1)
    {
        cout << "Stackoverflow.com";
        return;
    }
    cout << num << " pushed to stack" << endl;
    arr[++top] = num;
}
int stack::pop()
{
    return (arr[top--]);
}
class specialStack : public stack
{
    stack mini;

public:
    void push(int);
    int pop();
    int min();
};

void specialStack::push(int x)
{
    if (isEmpty())
    {
        mini.push(x);
        stack::push(x);
    }
    else
    {
        stack::push(x);
        if (x < mini.peek())
        {
            mini.push(x);
        }
    }
}
int specialStack::min()
{
    return mini.peek();
}
int specialStack::pop()
{
    int x = stack::pop();
    mini.pop();
    return x;
}
int main()
{
    specialStack s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout << s.min() << endl;
    s.push(5);
    cout << s.min();
    return 0;
}