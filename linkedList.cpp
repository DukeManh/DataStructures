#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

Node *newNode(int data)
{
    Node *node = new Node();
    node->data = data;
    node->next = nullptr;
    return node;
}

void printList(Node *head)
{
    while (head)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

void insert(Node *head, int key, int data)
{
    Node *prev = head;
    while (prev->data != key)
    {
        prev = prev->next;
    }
    Node *node = newNode(data);
    node->next = prev->next;
    prev->next = node;
}

void push(Node **head_ref, int new_data)
{
    /* 1. allocate node */
    Node *new_node = new Node();

    /* 2. put in the data */
    new_node->data = new_data;

    /* 3. Make next of new node as head */
    new_node->next = (*head_ref);

    /* 4. move the head to point to the new node */
    (*head_ref) = new_node;
}

void deleteNode(Node **head, int key)
{
    Node *tmp = (*head), *prev;
    if (tmp->data == key)
    {
        (*head) = tmp->next;
        delete tmp;
        return;
    }

    while (tmp && tmp->data != key)
    {
        prev = tmp;
        tmp = tmp->next;
    }

    if (!tmp)
        return;

    prev->next = tmp->next;
    delete tmp;
}

void reverse(Node *head)
{
    Node *curr, *next, *prev = nullptr;
    curr = head;
    while (curr)
    {
        next = curr->next;
        curr->next = prev;

        prev = curr;
        curr = next;
    }
    Node *newHead = prev;
    printList(newHead);
}
int len(Node *head)
{
    if (!head)
        return 0;
    return 1 + len(head->next);
}
void swap(int key1, int key2, Node **head)
{
    Node *node1 = *head, *prev1 = nullptr, *node2 = *head, *prev2 = nullptr;

    while (node1 && node1->data != key1)
    {
        prev1 = node1;
        node1 = node1->next;
    }
    while (node2 && node2->data != key2)
    {
        prev2 = node2;
        node2 = node2->next;
    }
    if (!node1 || !node2 || node1 == node2)
    {
        return;
    }

    if (prev1) //node 1 is not head
        prev1->next = node2;
    else
        *head = node2;

    if (prev2) //node 2 is not head
        prev2->next = node1;
    else
        *head = node1;

    Node *tmp = node1->next;
    node1->next = node2->next;
    node2->next = tmp;
}
int main()
{
    Node *head = newNode(15);
    head->next = newNode(45);
    head->next->next = newNode(71);
    printList(head);
    insert(head, 45, 46);
    printList(head);
    push(&head, 0);
    printList(head);
    deleteNode(&head, 46);
    printList(head);
    printList(head);
}