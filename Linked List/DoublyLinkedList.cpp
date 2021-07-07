#include<iostream>
using namespace std;

class node
{
    public:
    int data;
    node* next;
    node* prev;

    node(int val)
    {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

void insertionAtHead(node* &head, int val)
{
    node* n = new node(val);
    n->next = head;
    if(head != NULL)
    {
    head->prev = n;
    }
    head = n;
}

void insertionAtTail(node* &head, int val)
{
    if(head == NULL)
    {
        insertionAtHead(head, val);
        return;
    }
    node* n = new node(val);
    node* temp = head;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = n;
    n->prev = temp;
}

void display(node* head)
{
    cout<<"NULL <=> ";
    node* temp = head;
    while(temp != NULL)
    {
        cout<<temp->data<<" <=> ";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

void deletionAtHead(node* &head)
{
    node* toDelete = head;
    head = head->next;
    head->prev = NULL;

    delete toDelete;
}

void deletion(node* &head, int pos)
{
    if(pos == 1)
    {
        deletionAtHead(head);
        return ;
    }
    node* temp = head;
    int count = 1;
    while(temp != NULL && count != pos)
    {
        temp = temp->next;
        count ++;
    }
    temp->prev->next = temp->next;

    if(temp->next != NULL)
    {
    temp->next->prev = temp->prev;
    }

    delete temp;
}

int length(node* head)
{
    node* temp = head;
    int l = 1;
    while(temp != NULL)
    {
        l++;
        temp = temp->next;
    }
    return l;
}

node* appendKnodes(node* &head, int k)
{
    node* newHead;
    node* newTail;
    node* tail = head;

    int l = length(head);
    k = k%l;
    int count = 1;

    while(tail->next != NULL)
    {
        if(count == l-k)
        {
            newTail = tail;
        }
        if(count == l-k+1)
        {
            newHead = tail;
        }
        tail = tail->next;
        count ++;
    }
    newTail->next = NULL;
    tail->next = head;

    return newHead;
}

int main()
{
    node* head = NULL;

    insertionAtTail(head, 1);
    insertionAtTail(head, 2);
    insertionAtTail(head, 3);
    insertionAtTail(head, 4);
    insertionAtTail(head, 5);
    insertionAtTail(head, 6);
    insertionAtTail(head, 7);
    insertionAtTail(head, 8);
    insertionAtTail(head, 9);

    cout<<"Created Linked list is:- "<<endl;
    display(head);
    cout<<endl<<"After deletion:- "<<endl;
    deletion(head,9);
    display(head);

    cout<<endl<<"After appending k nodes:- "<<endl;
    node* newHead = appendKnodes(head, 5);
    display(newHead);

    return 0;
}