/*
Given a binary tree root, a Node X in the tree is named good if in the path from root to X there are no Nodes with a value greater than X.
Return the number of good Nodes in the binary tree.
Example 1:
Input: root = [3,1,4,3,null,1,5]
Output: 4
Explanation: Nodes in blue are good.
Root Node (3) is always a good Node.
Node 4 -> (3,4) is the maximum value in the path starting from the root.
Node 5 -> (3,4,5) is the maximum value in the path
Node 3 -> (3,1,3) is the maximum value in the path.
*/

#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data = val;
        left = right = NULL;
    }
};

void goodNodesUtil(Node* root, int max, int *count){
    if(root == NULL){
        return;
    }

    if(root->data >= max){
        max = root->data;
        *count += 1;
    }

    goodNodesUtil(root->left, max, count);
    goodNodesUtil(root->right, max, count);
}

int goodNodes(Node* root){
    if(root == NULL){
        return 0;
    }
    int count = 1;
    goodNodesUtil(root->left, root->data, &count);
    goodNodesUtil(root->right, root->data, &count);

    return count;
}

int main(){
    Node* root = new Node(3);
    root->left = new Node(3);
    // root->right = new Node(4);
    root->left->left = new Node(4);
    // root->right->left = new Node(1);
    root->left->right = new Node(2);

    cout<<goodNodes(root);
    return 0;
}