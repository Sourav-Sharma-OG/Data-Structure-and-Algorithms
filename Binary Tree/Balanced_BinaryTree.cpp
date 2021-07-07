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

int height(Node* root){
    if(root == NULL){
        return 0;
    }

    int lHeight = height(root->left);
    int rHeight = height(root->right);

    return max(lHeight, rHeight) + 1;
}

//This funciton is using the utility funciton to calculate the height of the nodes.
//So we are traversing each and every node of the tree, and also calculating the height of each and
//every node. So the overall time complexity of this function is O(n^2).
bool isBalanced(Node* root){
    if(root == NULL){
        return true;
    }

    if((isBalanced(root->left) == false) || isBalanced(root->right) == false)
    {
        return false;
    }

    int lHeight = height(root->left);
    int rHeight = height(root->right);

    if(abs(lHeight - rHeight) <= 1){
        return true;
    }
    else{
        return false;
    }
}


//Optimal function with time complexity-->O(n).
bool isBal(Node* root, int* height){
    if(root == NULL){
        return true;
    }
    int lh = 0, rh = 0;

    if((isBal(root->left, &lh) == false) || isBal(root->right, &rh) == false){
        return false;
    }

    *height = max(lh, rh) + 1;
    if(abs(lh - rh) <= 1){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    // root->right->right->right = new Node(8);
    // root->right->right->right->right = new Node(9);


    if(isBalanced(root)){
        cout<<"Balanced.";
    }
    else{
        cout<<"Not Balanced.";
    }

    cout<<endl;
    int height = 0;
    if(isBal(root, &height)){
        cout<<"Balanced.";
    }
    else{
        cout<<"Not Balanced.";
    }

    return 0;
}