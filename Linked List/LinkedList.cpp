#include<iostream>
using namespace std;

//...................................................................................................................................
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
//...................................................................................................................................


//...................................................................................................................................
void search(node* head, int key)
{
    node* temp = head;

    while(temp != NULL)
    {
        if(temp->data == key)
        {
            cout<<key<<" is present in the linked list."<<endl;
            return;
        }
        temp = temp->next;
    }
    cout<<key<<" is not present in the linked list."<<endl;
}
//...................................................................................................................................



//...................................................................................................................................
//Function to insert a element at the end of the linked list.
void InsertAtTail(node* &head , int val)
{
    node* n = new node(val);     // Creates a new node 'n' and assign 'val' to its data part and 'NULL' to next part.

    if(head == NULL)            //Base Condition: When linked list is empty, then insert at the Head.
    {
        head = n;
        return;
    }

    node* temp = head;
    while(temp->next != NULL)   //Traversing the linked list till the node having "next as NULL".
    {
        temp = temp->next;
    }
    temp->next = n;             //Inserting  node at the end of the linked list.
}
//...................................................................................................................................


//...................................................................................................................................
//Function to insert a node at the begining of the linked list.
void InsertionAtHead(node* &head, int val)
{
    node* n = new node(val);
    n->next = head;         //new node 'n' points to the first node.
    head = n;               //Creating new head.
}
//...................................................................................................................................


//...................................................................................................................................
//Function to delete the head node.
void deletionAtHead(node* &head)
{
    node* temp = head;
    head = head->next;

    delete temp;
}
//...................................................................................................................................


//...................................................................................................................................
//Function to delete a node from the linked list
void deletion(node* &head, int val)
{
    if(head == NULL)
    {
        cout<<"Underflow Condition. Linked list is already empty.";
    }

    if(head->next == NULL)
    {
        deletionAtHead(head);
    }
    node* temp = head;
    while(temp->next->data != val)
    {
        temp = temp->next;
    }

    node* toDelete = temp->next;
    temp->next = temp->next->next;

    delete toDelete;
}
//...................................................................................................................................



//...................................................................................................................................
//Function to display all elments of the linked list.
void display(node* head)        //Here we use 'node* head' because we dont need to modify the values.
{
    node* temp = head;
    while(temp != NULL)
    {
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}
//...................................................................................................................................


//...................................................................................................................................
//Function to reverse the linked list using Iterative Method.
node* reverse(node* &head)
{
    node* prevPtr = NULL;
    node* currPtr = head;
    node* nextPtr;

    while(currPtr != NULL)
    {
        nextPtr = currPtr->next;

        currPtr->next = prevPtr;

        prevPtr = currPtr;
        currPtr = nextPtr;
    }
    return prevPtr;
}
//...................................................................................................................................


//...................................................................................................................................
//Function to reverse the linked list using the Recursive method.
node* reverseRecursive(node* &head)
{
    if(head == NULL || head->next == NULL)
    {
        return head;
    }

    node* newHead = reverseRecursive(head->next);

    head->next->next = head;
    head->next = NULL;

    return newHead;
}

//...................................................................................................................................


//...................................................................................................................................
int main()
{
    node* head = NULL;
    InsertAtTail(head, 1);
    InsertAtTail(head, 2);
    InsertAtTail(head, 3);
    InsertAtTail(head, 4);

    cout<<"Inserting elements at the end of linked list:"<<endl;
    display(head);
    cout<<endl;

    InsertionAtHead(head,10);
    InsertionAtHead(head,20);
    cout<<"Inserting elements at the begining of linked list:"<<endl;

    display(head);
    cout<<endl;

    search(head , 4);
    search(head , 50);
    cout<<endl;

    deletion(head, 3);
    cout<<"After deletion of 3 from the linked list:"<<endl;
    display(head);
    cout<<endl;

    deletionAtHead(head);
    cout<<"After deletion of head node linked list:"<<endl;
    display(head);
    cout<<endl;

    // cout<<"Linked List after reversing by Iterative method:"<<endl;
    // node* newNode = reverse(head);
    // display(newNode);
    // cout<<endl;


    cout<<"Linked List after reversing by Recursive method:"<<endl;
    node* newNode1 = reverseRecursive(head);
    display(newNode1);


    return 0;
}
//...................................................................................................................................

