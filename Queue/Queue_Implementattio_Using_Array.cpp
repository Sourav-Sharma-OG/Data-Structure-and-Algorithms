/*
Queue: Queue is a linear data structre that store elelments in the first in first out fashion.
*/

#include<iostream>
using namespace std;

#define n 20

class queue{
    int *arr; 
    int front;
    int back;

    public:
    queue(){
         arr = new int[n];
         front = -1; 
         back = -1;
    }

    void push(int x){
        if(back == n-1){
            cout<<"Queue Overflow."<<endl;
        }
        back++;
        arr[back] = x;

        if(front == -1){
            front++;
        }
    }

    void pop(){
        if(front == -1 || front > back){
            cout<<"No element in the queue: Deletion not possible.";
        }
        front++;
    }

    int peek(){
        if(front == -1 || front > back){
            cout<<"No element in the queue: Deletion not possibel:";
            return -1;
        }

        return arr[front];
    }

    bool empty(){
        if(front == -1 || front > back){
            return true;
        }
        return true;
    }
};

int main(){
    queue obj;
    obj.push(1);
    obj.push(2);
    obj.push(3);
    obj.push(4);
    obj.push(5);

    cout<<"Element at the front of queue:- "<<obj.peek()<<endl;
    obj.pop();
    cout<<"After doing pop() operation , element at the front of the queue:- "<<obj.peek()<<endl;
    cout<<obj.empty();

    return 0;
}