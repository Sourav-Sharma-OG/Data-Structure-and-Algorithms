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


bool isBST(Node* root, Node* min = NULL, Node* max = NULL){
    if(root == NULL){
        return true;
    }

    if(min != NULL && root->data <= min->data){
        return false;
    }

    if(max != NULL &&  root->data >= max->data){
        return false;
    }

    bool isLeftValid = isBST(root->left, min, root);
    bool isRightValid = isBST(root->right, root, max);

    return (isLeftValid and isRightValid);
}


bool isBST1(Node* root, int min, int max){
    if(root == NULL){
        return true;
    }

    /** 
     * Here we are using and operator->if any one of the condition returns false then programs stops there and return false.
     * 1-> If root->data > Min value i.e -infinity for root.
     * 2-> If root->data < Max value i.e +infinity for root.
     * 3-> If left subtree is a BST where the root is root->left, min val is -infinity, and max value is root->data. 
     * 4-> If right subtree is a BST where the root is root->right, min val is root->data, and max value is +infinity. 
     */
    return (root->data > min && 
            root->data < max && 
            isBST1(root->left, min, root->data) && 
            isBST1(root->right, root->data, max));
}

static int prevv = INT_MIN;


bool isBST2(Node*root){
    if(root == NULL){
        return true;
    }

    if(isBST2(root->left) == false){
        return false;
    }

    if(root->data <= prevv){
        return false;
    }
    prevv = root->data;
    return isBST2(root->right);
}


int main(){
    Node* root = new Node(12);
    root->left = new Node(4);
    // root->right = new Node(11);

    if(isBST(root, NULL, NULL)){
        cout<<"Valid BST...";
    }
    else{
        cout<<"Invalid BST...";
    }

    cout<<endl;

    if(isBST1(root,INT_MIN, INT_MAX)){
        cout<<"Valid BST...";
    }
    else{
        cout<<"Invalid BST...";
    }


    cout<<endl;

    if(isBST2(root)){
        cout<<"Valid BST...";
    }
    else{
        cout<<"Invalid BST...";
    }

    return 0;   
}