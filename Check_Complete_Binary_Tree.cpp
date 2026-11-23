#include <iostream>
#include <queue>
using namespace std;

class Node 
{
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) 
    {
        data = value;
        left = NULL;
        right = NULL;
    }
};

bool isCompleteBinaryTree(Node* root) 
{
    if (root == NULL) 
    {
        return true;
    }

    queue<Node*> q;
    q.push(root);

    bool flag = false;

    while (!q.empty()) 
    {
        Node* current = q.front();
        q.pop();

        if (current->left) 
        {
            if (flag) 
            {
                return false;
            }
            q.push(current->left);
        }
        else 
        {
            flag = true;
        }

        if (current->right) 
        {
            if (flag) 
            {
                return false;
            }
            q.push(current->right);
        }
        else 
        {
            flag = true;
        }
    }

    return true;
}

int main() 
{
    Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);

    if (isCompleteBinaryTree(root)) 
    {
        cout << "The Binary Tree is Complete.";
    }
    else 
    {
        cout << "The Binary Tree is Not Complete.";
    }

    return 0;
}