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


int calHeight(Node* node){
    if(node == NULL){
        return 0;
    }

    int leftSubtreeHeight = calHeight(node->left);
    int rightSubtreeHeight = calHeight(node->right);
    return max(leftSubtreeHeight, rightSubtreeHeight) + 1; 
}

//Time complexity of this function is O(n^2). Because this funciton is calling the fucntion calHeight
// n times and the time complexity of calHeight function is O(n).

int calDiameter(Node* node){
    if(node == NULL){
        return 0;
    }

    int lHeight = calHeight(node->left);
    int rHeight = calHeight(node->right);

    int diameter = lHeight + rHeight + 1;
    int lDiameter = calDiameter(node->left);
    int rDiameter = calDiameter(node->right);
    return max(diameter, max(lDiameter, rDiameter));
}



int calDiameterOptimal(Node* node, int* height){
    if(node == NULL){
        *height = 0;
        return 0;
    }

    int lh = 0; int rh = 0;
    int lDiameter = calDiameterOptimal(node->left, &lh);
    int rDiameter = calDiameterOptimal(node->right, &rh);

    int currDiameter = lh + rh + 1;
    *height = max(lh, rh) + 1;

    return max(currDiameter, max(lDiameter, rDiameter));
}




//Another optimal approach using pairs.

pair<int,int> dia(Node*root){
    if(root == NULL){
        pair<int, int>p;
        p.first = 0;
        p.second = 0;
        return p;
    }

    pair<int,int> leftAns = dia(root->left);
    pair<int,int> rightAns = dia(root->right);

    int lh = leftAns.first;
    int ld = leftAns.second;
    int rh = rightAns.first;
    int rd = rightAns.second;

    int height = max(lh, rh) + 1;
    int diameter = max((lh + rh + 1), max(ld, rd));

    pair<int, int >p;
    p.first = height;
    p.second = diameter;

    return p;
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    
    cout<<calDiameter(root);
    cout<<endl;
    int height = 0;
    cout<<calDiameterOptimal(root, &height);
    cout<<endl;

    pair<int, int>p = dia(root);
    cout<<"Height: "<<p.first<<" , Diameter: "<<p.second<<endl;
    return 0;
}