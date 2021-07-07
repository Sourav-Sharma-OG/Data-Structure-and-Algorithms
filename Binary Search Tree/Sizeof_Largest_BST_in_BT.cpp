#include <iostream>
#include <climits>
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

//Creating a Utility structure.
struct Info
{
    int size;
    int max;
    int min;
    int ans;
    bool isBST;
};

Info sizeOfLargestBST_inBT(Node *root)
{

    //If the  given root does not exist
    if (root == NULL)
    {
        return {0, INT_MIN, INT_MAX, 0, true};
    }

    //If current node is a leaf node
    if (root->left == NULL && root->right == NULL)
    {
        return {1, root->data, root->data, 1, true};
    }

    //Recursively traverse for the left and right subtree
    Info leftSubtree = sizeOfLargestBST_inBT(root->left);
    Info rightSubtree = sizeOfLargestBST_inBT(root->right);

    //Check for the current Node.
    Info curr;
    curr.size = (1 + leftSubtree.size + rightSubtree.size);

    /**
     * Checking the BST properties for current Node.....
     * If the left subtree of current node is BST
     * and the right subtree of current node is BST
     * and the max of left subtree is less than the value of current node data
     * and the min of right subtree is less than  the value of current node data.
     */
    if (leftSubtree.isBST && rightSubtree.isBST && leftSubtree.max < root->data && rightSubtree.min > root->data)
    {
        //Updata the Info for current node.
        curr.max = max(leftSubtree.max, max(rightSubtree.max, root->data));
        curr.min = min(leftSubtree.min, min(rightSubtree.min, root->data));
        curr.ans = curr.size;
        curr.isBST = true;
        return curr;
    }

    //Else if the current root node does not hold the properties of BST.
    curr.ans = max(leftSubtree.ans, rightSubtree.ans);
    curr.isBST = false; 
    return curr;
}

int main()
{
    Node *root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->left->left = new Node(3);
    root->left->right = new Node(7);
    root->right->left = new Node(13);
    root->right->right = new Node(17);

    Info ans = sizeOfLargestBST_inBT(root);
    cout << "Size of Largest BST is given Binary Tree is :" << ans.ans << endl;
    return 0;
}