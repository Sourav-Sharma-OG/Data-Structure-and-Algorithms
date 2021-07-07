#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

void zigzagTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    stack<Node *> currentLevel;
    stack<Node *> nextLevel;
    bool lefToRight = true;

    currentLevel.push(root);

    while (!currentLevel.empty())
    {
        Node *temp = currentLevel.top();
        currentLevel.pop();

        if (temp != NULL)
        {
            cout << temp->data << " ";

            if (lefToRight)
            {
                if (temp->left != NULL)
                {
                    nextLevel.push(temp->left);
                }
                if (temp->right != NULL)
                {
                    nextLevel.push(temp->right);
                }
            }
            else
            {
                if (temp->right != NULL)
                {
                    nextLevel.push(temp->right);
                }
                if (temp->left != NULL)
                {
                    nextLevel.push(temp->left);
                }
            }
        }

        if (currentLevel.empty())
        {
            lefToRight = !lefToRight;
            swap(currentLevel, nextLevel);
        }
    }
}

int main()
{

    Node *root = new Node(12);
    root->left = new Node(9);
    root->right = new Node(15);
    root->left->left = new Node(5);
    root->left->right = new Node(10);

    zigzagTraversal(root);

    return 0;
}