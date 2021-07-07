#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left, *right;
    Node(int val){
        data = val;
        left = right = NULL;
    }
};

bool isIdentical(Node* root1, Node* root2){
    if(root1 == NULL && root2 == NULL){
        return true;
    }

    else if(root1 == NULL || root2 == NULL){
        return false;
    }

    else{
        bool condition1 = root1->data == root2->data;
        bool condition2 = isIdentical(root1->left, root2->left);
        bool condition3 = isIdentical(root1->right, root2->right);

        if(condition1 && condition2 && condition3){
            return true;
        }
        return false;
    }
}

int main(){
    Node* root1 = new Node(5);
    root1->left = new Node(4);
    root1->right = new Node(8);
    
    Node* root2 = new Node(5);
    root2->left = new Node(4);
    root2->right = new Node(8);

    if(isIdentical(root1, root2)){
        cout<<"Trees are identical..";
    }
    else{
        cout<<"Trees are not identical...";
    }

    return 0;
}