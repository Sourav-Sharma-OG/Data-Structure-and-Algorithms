/*
Given a queue of integers of even length, rearrange the elements by interleaving the first half of the queue with the second half of the queue.

Only a stack can be used as an auxiliary space.

Examples:

Input :  1 2 3 4
Output : 1 3 2 4

Input : 11 12 13 14 15 16 17 18 19 20
Output : 11 16 12 17 13 18 14 19 15 20

Algorithm:
Following are the steps to solve the problem:
1.Push the first half elements of queue to stack.
2.Enqueue back the stack elements.
3.Dequeue the first half elements of the queue and enqueue them back.
4.Again push the first half elements into the stack.
5.Interleave the elements of queue and stack.
*/

#include<iostream>
#include<queue>
#include<stack>

using namespace std;

queue<int> interleave(queue<int>&q){
    int mid = q.size() / 2;
    stack<int>st;

    //Pushing the first half the elements to the stack.
    for(int i = 0; i<mid; i++){
        st.push(q.front());
        q.pop();
    }

    //Enqueuing back all the stack elements.
    while(!st.empty()){
        q.push(st.top());
        st.pop();
    }

    //Dequeuing the first half of the elements and Enqueuing them to the end of the queue.
    for(int i = 0; i<mid; i++){
        q.push(q.front());
        q.pop();
    }

    //Again pushing the first half to the stack.
    for(int i = 0; i<mid; i++){
        st.push(q.front());
        q.pop();
    }

    //Interleave the elements of queue and stack.
    while(!st.empty()){
        q.push(st.top());
        st.pop();
        q.push(q.front());
        q.pop();
    }

    return q;
}

int main(){
    queue<int> q;
    q.push(11);
    q.push(12);
    q.push(13);
    q.push(14);
    q.push(15);
    q.push(16);
    q.push(17);
    q.push(18);
    q.push(19);
    q.push(20);
    interleave(q);
    int length = q.size();
    for (int i = 0; i < length; i++) {
        cout << q.front() << " ";
        q.pop();
    }
    return 0;
}