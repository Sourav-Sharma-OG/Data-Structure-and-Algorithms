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

bool getPath(Node* root, int key, vector<int>&v){
    if(root == NULL){
        return false;
    }

    v.push_back(root->data);
    if(root->data == key){
        return true;
    }

    if(getPath(root->left, key, v) || getPath(root->right, key, v)){
        return true;
    }

    v.pop_back();
    return false;
}

int getLCA(Node* root, int n1, int n2){
    vector<int>path1, path2;

    if(!getPath(root, n1, path1) || !getPath(root, n2, path2)){
        return -1;
    }

    int pathChange;
    for(pathChange = 0; pathChange <path1.size() && path2.size(); pathChange++){
        if(path1[pathChange] != path2[pathChange]){
            break;
        }
    }

    return path1[pathChange-1];
}


Node* getLCA_Simple(Node* root, int n1, int n2){
    if(root == NULL){
        return NULL;
    }
    if(root->data == n1 || root->data ==  n2){
        return root;
    }

    Node* leftPart = getLCA_Simple(root->left,n1,n2);
    Node* rightPart = getLCA_Simple(root->right,n1,n2);

    if(leftPart && rightPart){
        return root;
    }

    if(leftPart == NULL && rightPart == NULL){
        return NULL;
    }
    if(leftPart){
        return leftPart;
    }

    return rightPart;
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

    int ans = getLCA(root, 8, 7);
    
    if(ans == -1){
        cout<<"LCA do not exist.";
    }
    else{
        cout<<"LCA : "<<ans;
    }


    cout<<endl;
    Node* temp = getLCA_Simple(root, 8, 7);
    
    if(temp == NULL){
        cout<<"LCA do not exist.";
    }
    else{
        cout<<"LCA : "<<temp->data;
    }

    return 0;

}