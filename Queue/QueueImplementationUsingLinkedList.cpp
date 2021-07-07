#include<iostream>
using namespace std;

class node{
    public:
    int data; 
    node* next;
    node(int val){
        data = val;
        next = NULL;
    }
};

class queue{
    node* rear; 
    node* front;

    public:
    queue(){
        rear = NULL;
        front = NULL;
    }

    void push(int val){
        node* n = new node(val);
        if(front == NULL){
            front = n;
            rear = n;
            return;
        }
        rear->next = n;
        rear = n;
    }

    void pop(){
        if(front == NULL){
            cout<<"Queue Underflow."<<endl;
            return;
        }
        node * todelete = front;
        front = front->next;

        delete todelete;
    }

    int peek(){
        if(front == NULL){
            cout<<"No element in the queue."<<endl;
            return -1;
        }
        return front->data;
    }

    bool isEmpty(){
        if(front == NULL){
            return true;
        }
        return false;
    }
};

int main(){
    queue obj;
    obj.push(1);
    obj.push(2);
    obj.push(3);
    obj.push(4);
    obj.push(5);

    cout<<obj.peek()<<endl;
    obj.pop();
    cout<<obj.peek()<<endl;
    obj.pop();
    cout<<obj.peek()<<endl;
    obj.pop();
    cout<<obj.peek()<<endl;
    obj.pop();
    cout<<obj.peek()<<endl;
    obj.pop();
    if(obj.isEmpty()){
        cout<<"Queue is empty.\n ";
    }
    else{
        cout<<"Queue is not empty.\n ";
    }
    return 0;
}