#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int val){
        data = val;
        next = NULL;
    }
};

void insertAtTail(Node* &head, int val)
{
    Node* n = new Node(val);

    if(head == NULL)
    {
        head = n;
        return;
    }

    Node* temp = head;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = n;
}

Node* reverseList(Node* head){
    Node* prevPtr = NULL;
    Node* currPtr = head;
    Node* nextPtr;

    while(currPtr != NULL){
        nextPtr = currPtr->next;
        currPtr->next = prevPtr;
        prevPtr = currPtr;
        currPtr = nextPtr;
    }
    return prevPtr;
}

void printLinkedList(Node* head){
    while(head != NULL){
        cout<<head->data<<"->";
        head = head->next;
    }
    cout<<"NULL"<<endl<<endl;
}

int main(){
    Node* head = NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    insertAtTail(head, 5);

    printLinkedList(head);
    Node* newHead = reverseList(head);
    printLinkedList(newHead);

    return 0;  
}