#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data = val;
        left = right =NULL;
    }
};

void getVerticalOrder(Node* root, int hDis, map<int, vector<int>>&map){
    if(root == NULL){
        return;
    }

    map[hDis].push_back(root->data);
    getVerticalOrder(root->left, hDis - 1, map);
    getVerticalOrder(root->right, hDis + 1, map);
}

int main(){
    Node* root = new Node(10);
    root->left = new Node(7);
    root->right = new Node(4);
    root->left->left = new Node(3);
    root->left->right = new Node(11);
    root->right->left = new Node(14);
    root->right->right = new Node(6);

    map<int, vector<int>>mp;
    int hDis = 0;
    getVerticalOrder(root, hDis, mp);

    map<int,vector<int>>::iterator it;
    for(it = mp.begin(); it != mp.end(); ++it){
        for(int i = 0; i < (it->second).size(); i++){
            cout<<(it->second)[i]<<" ";
        }
    }

    return 0;
}