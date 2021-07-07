#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int val)
    {
        data = val;
        next = NULL;
    }
};

//Function to insert at the heaqd in te circular linked list.
void insertAtHead(node *&head, int val)
{
    node *n = new node(val);
    if (head == NULL)
    {
        n->next = n;
        head = n;
        return;
    }
    node *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = n;
    n->next = head;
    head = n;
}

void insertAtTail(node *&head, int val)
{
    node *n = new node(val);
    if (head == NULL)
    {
        insertAtHead(head, val);
        return;
    }
    node *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = n;
    n->next = head;
}

void deletionAtHead(node *&head)
{
    node *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    node *toDelete = head;
    temp->next = temp->next->next;
    head = head->next;
    delete toDelete;
}

void deletion(node *&head, int pos)
{
    if (pos == 1)
    {
        deletionAtHead(head);
        return;
    }
    node *temp = head;
    int count = 1;

    while (count != pos - 1)
    {
        temp = temp->next;
        count++;
    }
    node *toDelete = temp->next;
    temp->next = temp->next->next;
    delete toDelete;
}

void display(node *head)
{
    node *temp = head;
    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

void linearSearch(node* &head, int val)
{
    node* temp = head;
    do
    {
        if(temp->data == val)
        {
            cout<<val<<" is present in the linked list";
            return;
        }
        temp = temp->next;
    } while (temp != head);
    cout<<val<<" is not present in the linked list.";
    
}

int main()
{
    node *head = NULL;

    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    insertAtTail(head, 5);
    display(head);

    insertAtHead(head, 0);
    display(head);

    deletion(head,2);
    display(head);

    deletionAtHead(head);
    display(head);

    linearSearch(head, 3);


    return 0;
}