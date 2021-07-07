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


int maxPathSumUtil(Node* root, int &ans){
    if(root == NULL){
        return 0;
    }

    int leftSum = maxPathSumUtil(root->left, ans);
    int rightSum = maxPathSumUtil(root->right, ans);

    int nodeMax = max(max(root->data, leftSum + rightSum + root->data), max(leftSum+root->data, rightSum + root->data));

    ans = max(ans, nodeMax);

    int singlePathSum = max(root->data, max(root->data + leftSum, root->data + rightSum));

    return singlePathSum;
}


int maxPathSum(Node* root){
    int ans = INT_MIN;
    maxPathSumUtil(root, ans);
    return ans;
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->right = new Node(5);

    int ans = maxPathSum(root);
    cout<<ans;
    return 0;
}