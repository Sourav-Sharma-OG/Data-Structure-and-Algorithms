#include<iostream>
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

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void callPointers(Node* root, Node** first, Node** mid, Node** last, Node** prev){
    if(root == NULL){
        return;
    }

    callPointers(root->left, first, mid, last, prev);
    
    //If prev node exists and the data of the current node is less than the data of prev node. i.e contradictory to the  inorder sequence...
    if(*prev && root->data < (*prev)->data){

        //If this condition is occuring for the very first time. i.e in this case all the pointers except prev are NULL.
        if(!*first){
            *first = *prev;
            *mid = root;
        }

        //Else if this condition is occuring for the second time..
        else{
            *last = root;
        }
    }

    *prev = root;
    callPointers(root->right, first, mid, last, prev);
}

void restoreBST(Node* root){
    Node *first, *mid, *last, *prev;
    
    first = mid = last = prev = NULL;
    callPointers(root, &first, &mid, &last, &prev);

    //Case 1  -> When the nodes data are not adjacent to each other in inorder sequence...
    if(first && last){
        swap(&(first->data), &(last->data));
    }

    //Case 2   -> When the nodes data is adjacent to each other in inorder sequence...
    else if(first && mid){
        swap(&(first->data), &(mid->data));
    }
}

void inorder(Node* root){
    if(root == NULL){
        return;
    }

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int main(){
    Node* root = new Node(10);
    root->left = new Node(15);
    root->right = new Node(5);
    root->left->left = new Node(1);
    root->left->right = new Node(7);
    root->right->left = new Node(13);
    root->right->right = new Node(17);

    inorder(root);

    restoreBST(root);

    cout<<endl<<endl;
    inorder(root);

    return 0;
}