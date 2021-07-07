/*
Algorithm: We print the level order traversal with the help of a queue.

1. Push the root to the rear end of the queue.
2. Push NULL after the root node.
3.Repeat the process untill the queue is not empty.
4.Store the front element of the queue and the pop the front.
5.If the front of the queue is not null
    -->Print the data of front.
    -->Check if left and right of front exists or not
        -->If yes the push them to the rear end of the queue.
6.Else if front of the queue is null and queue is not empty
    -->push null to the rear of queue.
7.Step 3 while loop ends when the queue become empty.
8.Exit.
*/

#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int val){
        left = NULL;
        right = NULL;
        data = val;
    }
};


void printLevelOrder(Node* root){
    if(root == NULL)
        return;
    
    queue<Node*>q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* node = q.front();
        q.pop();

        if(node != NULL){
            cout<<node->data<<" ";
            if(node->left)
                q.push(node->left);

            if(node->right)
                q.push(node->right);
        }
        else if(!q.empty()){
            q.push(NULL);
        }
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

    printLevelOrder(root);
    return 0;
}