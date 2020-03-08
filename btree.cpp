#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

class btree
{
public:
    btree();
    ~btree();
    void insert(int key);
    Node *search(int key);
    void destroyTree();
    void print();

private:
    Node *root;
    void insert(int key, Node *leaf);
    Node *search(int key, Node *leaf);
    void print(Node *leaf);
    void destroyTree(Node *leaf);
};

btree::btree()
{
    root = NULL;
}

btree::~btree()
{
    destroyTree();
}

void btree::insert(int key, Node *leaf)
{
    if (leaf->data > key)
    {
        if (leaf->left != NULL)
        {
            insert(key, leaf->left);
        }
        else
        {
            leaf->left = new Node;
            leaf->left->data = key;
            leaf->left->left = NULL;
            leaf->left->right = NULL;
            cout << "insert" << key << " success" << endl;
        }
    }
    else
    {
        if (leaf->right != NULL)
        {
            insert(key, leaf->right);
        }
        else
        {
            leaf->right = new Node;
            leaf->right->data = key;
            leaf->right->left = NULL;
            leaf->right->right = NULL;
        }
    }
}

void btree::insert(int key)
{
    if (root == NULL)
    {
        root = new Node;
        root->data = key;
        root->left = NULL;
        root->right = NULL;
    }
    else
    {
        insert(key, root);
    }
}

Node *btree::search(int key, Node *leaf)
{
    if (leaf != NULL)
    {
        if (leaf->data == key)
        {
            return leaf;
        }
        else if (leaf->data > key)
        {
            return search(key, leaf->left);
        }
        else
        {
            return search(key, leaf->right);
        }
    }
    else
    {
        return NULL;
    }
}

Node *btree::search(int key)
{
    return search(key, root);
}

void btree::destroyTree()
{
    destroyTree(root);
}

void btree::destroyTree(Node *leaf)
{
    if (leaf != NULL)
    {
        destroyTree(leaf->left);
        destroyTree(leaf->right);
        delete (leaf);
    }
}

void btree::print()
{
    print(root);
}
void btree::print(Node *leaf)
{
    if (leaf != NULL)
    {
        cout << leaf->data << ",";
        print(leaf->right);
        print(leaf->left);
    }
}

int main()
{
    //btree tree;
    btree *tree = new btree();

    tree->insert(10);
    tree->insert(6);
    tree->insert(14);
    tree->insert(5);
    tree->insert(8);
    tree->insert(11);
    tree->insert(18);
    tree->print();
    delete tree;
}