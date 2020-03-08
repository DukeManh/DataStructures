#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;
};

Node *newNode(int data)
{
    Node *node = new Node();
    node->data = data;
    node->next = nullptr;
    node->prev = nullptr;
    return node;
}
void append(Node **head, int data)
{
    Node *tmp = newNode(data);
    tmp->prev = *head;

    if ((*head)->next != nullptr)
    {
        (*head)->next = tmp;
    }
    *head = tmp;
}
void printDLL(Node *head)
{
    while (head != nullptr)
    {
        cout << head->data;
        head = head->prev;
    }
}
int main()
{
    Node *head = new Node;
    append(&head, 15);
    append(&head, 45);
    append(&head, 98);
    printDLL(head);
}