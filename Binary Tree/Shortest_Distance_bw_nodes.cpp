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

//Utility function to find the Lowest Common Ancestor of both values n1 and n2.
Node* LCA(Node* root, int n1, int n2){
    if(root == NULL){
        return NULL;
    }

    if(root->data == n1 || root->data == n2){
        return root;
    }

    Node* left = LCA(root->left, n1, n2);
    Node* right = LCA(root->right, n1, n2);

    if(left && right){
        return root;
    }

    if(left == NULL && right == NULL){
        return NULL;
    }

    if(left != NULL){
        return left;
    }

    return right;
}


//Utility funciton to calculate the distnace of a value(node->data) from the root node.
int findDistnace(Node* root, int key, int dist){
    if(root == NULL){
        return -1;
    }
    if(root->data == key){
        return dist;
    }

    int left = findDistnace(root->left, key, dist + 1);
    if(left != -1){
        return left;
    }
    return findDistnace(root->right, key, dist + 1);
}


//Main Function to find the shortest distance bw two nodes.
int distBwNodes(Node* root, int n1, int n2){
    //Step 1-> Find the Loweset common Ancestor of both values.
    Node* lca = LCA(root, n1, n2);

    //Step 2-> Find the distance of value from the LCS Node.
    int d1 = findDistnace(lca, n1, 0);
    int d2 = findDistnace(lca, n2, 0);

    //Step 3-> Return the sum of both distances.
    return d1 + d2;
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->right->left->left = new Node(8);

    cout<<distBwNodes(root, 8, 7);

    return 0;
}