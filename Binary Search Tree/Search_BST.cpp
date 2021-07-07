#include <iostream>
using namespace std;

struct Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

Node *searchInBST(Node *root, int key)
{
    if (root == NULL)
    {
        return NULL;
    }

    if (root->data == key)
    {
        return root;
    }

    else if (key < root->data)
    {
        return searchInBST(root->left, key);
    }

    return searchInBST(root->right, key);
}

void printInorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

int main()
{
    Node *root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(7);
    root->left->left = new Node(2);
    root->left->right = new Node(4);
    root->right->left = new Node(6);
    root->right->right = new Node(8);
    root->left->left->left = new Node(1);

    printInorder(root);

    cout << endl;

    if (searchInBST(root,555) == NULL)
    {
        cout << "Key does'nt exitst.";
    }
    else
    {
        cout << "Key Exists.";
    }

    return 0;
}