#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int val){
        left = right = NULL;
        data = val;
    }
};

Node* constructBST(int arr[], int low, int high){
    if(low > high){
        return NULL;
    }

    int mid = (low + high) / 2;
    Node* root = new Node(arr[mid]);
    root->left = constructBST(arr, low, mid-1);
    root->right = constructBST(arr, mid+1, high);

    return root;
}

void printInorder(Node* root){
    if(root == NULL){
        return;
    }

    printInorder(root->left);
    cout<<root->data<<" ";
    printInorder(root->right);
}

void printPreorder(Node* root){
    if(root == NULL){
        return;
    }

    cout<<root->data<<" ";
    printPreorder(root->left);
    printPreorder(root->right);
}

int main(){
    int inorder[] = {1,2,3,4,5,6,7};
    int n = sizeof(inorder)/sizeof(inorder[0]);
    Node* root = constructBST(inorder, 0, n-1);
    cout<<"Inorder: ";
    printInorder(root);

    cout<<"\nPreorder: ";
    printPreorder(root);
}