#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = right = NULL;
    }
};


void topView(Node* root, int hDis, int level, map<int,pair<int, int>>&mp){
    if(root == NULL){
        return;
    }

    if(mp.count(hDis) == 0 || level < mp[hDis].second){
        mp[hDis] = make_pair(root->data, level);
    }

    topView(root->left, hDis - 1, level + 1, mp);
    topView(root->right, hDis + 1, level + 1, mp);
}

void bottomView(Node* root, int hDis, int level, map<int, pair<int, int>>&mp){
    if(root == NULL){
        return;
    }

    if(mp.count(hDis) == 0 || level >= mp[hDis].second){
        mp[hDis] = make_pair(root->data, level);
    }

    bottomView(root->left, hDis - 1, level + 1, mp);
    bottomView(root->right, hDis + 1, level + 1, mp);
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    map<int, pair<int, int>>mp;
    cout<<"Top View of Binary Tree: ";
    topView(root, 0, 0, mp);
    for(auto i: mp){
        cout<<i.second.first<<" ";
    }
    cout<<endl;
    mp.clear();

    cout<<"Bottom View of Binary Tree: ";
    bottomView(root, 0, 0, mp);
    for(auto i : mp){
        cout<<i.second.first<<" ";
    }
    return 0;
}