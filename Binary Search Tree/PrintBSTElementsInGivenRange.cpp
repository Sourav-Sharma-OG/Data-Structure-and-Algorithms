/*
Given a Binary Search Tree and a range [low, high]. Find all the numbers in the BST that lie in the given range.
Note: Element greater than or equal to root go to the right side.

Example 1:

Input:
       17
     /    \
    4     18
  /   \
 2     9 
l = 4, h = 24
Output: 4 9 17 18 
Example 2:

Input:
       16
     /    \
    7     20
  /   \
 1    10
l = 13, h = 23
Output: 16 20 
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

void printRange(Node* root, int low, int high, vector<int>& ans){
    if(root == NULL){
        return;
    }

    printRange(root->left, low, high, ans);

    if(root->data >= low and root->data <= high){
        ans.push_back(root->data);
    }

    printRange(root->right, low, high, ans);
}

int main(){
    Node* root = new Node(16);
    root->left = new Node(7);
    root->right = new Node(20);
    root->left->left = new Node(1);
    root->left->right = new Node(10);

    int low = 13;
    int high = 23;

    vector<int>ans;
    printRange(root, low, high, ans);

    for(auto it : ans){
        cout<<it<<" ";
    }
    return 0;
}