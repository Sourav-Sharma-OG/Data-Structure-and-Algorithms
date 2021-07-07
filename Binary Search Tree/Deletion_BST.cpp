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

Node *inorderSucc(Node *root)
{
    Node *curr = root;
    while (curr && curr->left != NULL)
    {
        curr = curr->left;
    }
    return curr;
}

Node *deletionInBST(Node *root, int key)
{
    if(root == NULL){
        return NULL;
    }
    
    if (key < root->data)
    {
        root->left = deletionInBST(root->left, key);
    }
    else if (key > root->data)
    {
        root->right = deletionInBST(root->right, key);
    }

    else
    {
        if (root->left == NULL)
        {
            Node *temp = root->right;
            free(root);
            return temp;
        }

        else if (root->right == NULL)
        {
            Node *temp = root->left;
            free(root);
            return temp;
        }

        Node *temp = inorderSucc(root->right);
        root->data = temp->data;
        root->right = deletionInBST(root->right, temp->data);
    }
    return root;
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

    root = deletionInBST(root, 5);
    cout << endl;
    printInorder(root);

    return 0;
}