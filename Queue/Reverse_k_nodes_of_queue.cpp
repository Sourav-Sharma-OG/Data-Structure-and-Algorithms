/*
Given an integer K and a queue of integers, we need to reverse the order of the first K elements of the queue, leaving the other elements in the same relative order.

Only following standard operations are allowed on queue.

enqueue(x) : Add an item x to rear of queue
dequeue() : Remove an item from front of queue
size() : Returns number of elements in queue.
front() : Finds front item.
Example 1:

Input:
5 3
1 2 3 4 5

Output: 
3 2 1 4 5

Explanation: 
After reversing the given input from the 3rd position the resultant output will be 3 2 1 4 5.

Example 2:

Input:
4 4
4 3 2 1

Output: 
1 2 3 4

Explanation: 
After reversing the given input from the 4th position the resultant output will be 1 2 3 4.
*/  

#include<iostream>
#include<queue>
#include<stack>

using namespace std;

queue<int> reverseKnodes(queue<int>q, int k){
    stack<int>st;
    int count = q.size() - k;

    while(!q.empty()){
        st.push(q.front());
        q.pop();
    }

    while(!st.empty()){
        q.push(st.top());
        st.pop();
    }

    while(count--){
        st.push(q.front());
        q.pop();
    }

    while(!st.empty()){
        q.push(st.top());
        st.pop();
    }
    return q;    
}

int main(){
    queue<int>q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    queue<int>ans = reverseKnodes(q,3);
    cout<<"Original queue:"<<endl;
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;

    cout<<"Reversed Queue: "<<endl;
    while(!ans.empty()){
        cout<<ans.front()<<" ";
        ans.pop();
    }

    return 0;
}