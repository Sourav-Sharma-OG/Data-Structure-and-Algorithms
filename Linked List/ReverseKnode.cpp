#include<iostream>
using namespace std;

class node
{
    public:
    int data;
    node* next;

    node(int val)
    {
        data = val;
        next = NULL;
    }
};

void insertAtTail(node* &head, int val)
{
    node* n = new node(val);

    if(head == NULL)
    {
        head = n;
        return;
    }

    node* temp = head;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = n;
}

void display(node* head)
{
    node* temp = head;
    while(temp !=  NULL)
    {
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

node* reverseKnodes(node* &head, int k)
{
    node* prevPtr = NULL;
    node* currPtr = head;
    node* nextPtr;
    int count = 0;

    while(currPtr != NULL && count<k)
    {
        nextPtr = currPtr->next;
        currPtr->next = prevPtr;
        prevPtr = currPtr;
        currPtr = nextPtr;
        count ++;
    }

    if(nextPtr != NULL)
    {
        head->next = reverseKnodes(nextPtr, k);
    }
    return prevPtr;
}


int main()
{
    node* head = NULL;

    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    insertAtTail(head, 5);
    insertAtTail(head, 6);
    insertAtTail(head, 7);
    insertAtTail(head, 8);
    insertAtTail(head, 9);

    display(head);
    cout<<endl;

    int k;
    cout<<"Enter value of k:- ";
    cin>>k;
    node* newHead =reverseKnodes(head, k);
    display(newHead);
    return 0;
}