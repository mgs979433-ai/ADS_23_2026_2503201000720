#include <iostream>
using namespace std;

struct Node 
{
    int data;
    Node *left, *right;
    
    Node(int val) 
    {
        data = val;
        left = right = NULL;
    }
};

// Insert node
Node* insert(Node* root, int val) 
{
    if (root == NULL)
        return new Node(val);

    if (val < root->data)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);

    return root;
}

// Minimum value
Node* findMin(Node* root) 
{
    while (root && root->left)
        root = root->left;
    return root;
}

// Maximum value
Node* findMax(Node* root) 
{
    while (root && root->right)
        root = root->right;
    return root;
}

// Successor
Node* successor(Node* root, int key) 
{
    Node *succ = NULL;
    while (root) 
    {
        if (key < root->data) 
        {
            succ = root;
            root = root->left;
        }
        else
            root = root->right;
    }
    return succ;
}

// Predecessor
Node* predecessor(Node* root, int key) 
{
    Node *pred = NULL;
    while (root) 
    {
        if (key > root->data) 
        {
            pred = root;
            root = root->right;
        }
        else
            root = root->left;
    }
    return pred;
}

int main() 
{
    Node* root = NULL;

    int a[] = {50, 30, 70, 20, 40, 60, 80};
    for (int x : a)
        root = insert(root, x);

    cout << "Minimum: " << findMin(root)->data << endl;
    cout << "Maximum: " << findMax(root)->data << endl;

    int key = 50;

    Node* s = successor(root, key);
    Node* p = predecessor(root, key);

    cout << "Successor: ";
    if (s) cout << s->data;
    else cout << "None";

    cout << "\nPredecessor: ";
    if (p) cout << p->data;
    else cout << "None";

    return 0;
}
