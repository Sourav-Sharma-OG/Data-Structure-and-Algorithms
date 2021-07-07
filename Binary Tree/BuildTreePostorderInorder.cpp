#include<iostream>
using namespace std;

struct Node{
    int data; 
    struct Node* left;
    struct Node* right;

    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

int search(int inorder[], int start, int end, int val){
    for(int i = start; i<=end; i++){
        if(inorder[i] == val){
            return i;
        }
    }
    return -1;
}

Node* buildTree(int postorder[], int inorder[], int start, int end){
    static int idx = end;
    if(start > end){
        return NULL;
    }
    int val = postorder[idx];
    idx--;
    Node* node = new Node(val);
    if(start == end){
        return node;
    }
    int pos = search(inorder, start ,end, val);
    node->right = buildTree(postorder, inorder, pos+1, end);
    node->left = buildTree(postorder, inorder, start, pos-1);

    return node;
}

void printInorder(Node* root){
    if(root == NULL){
        return;
    }

    printInorder(root->left);
    cout<<root->data<<" ";
    printInorder(root->right);
}

int main(){
    int inorder[] = {4,2,1,5,3};
    int postorder[] = {4,2,5,3,1};
    int end = (sizeof(inorder)/sizeof(inorder[0])) - 1;
    Node* root = buildTree(postorder, inorder, 0, end);
    printInorder(root);
    return 0;
}