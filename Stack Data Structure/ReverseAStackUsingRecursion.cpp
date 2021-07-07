/*
Write a program to reverse a stack using recursion. You are not allowed to use loop constructs like while, for..etc, and you can only use the following ADT functions on Stack S: 
isEmpty(S) 
push(S) 
pop(S)*/

#include<iostream>
#include<stack>

using namespace std;

void insertAtBottom(stack<int>&st, int ele){
    if(st.empty()){
        st.push(ele);
        return;
    }

    int topele = st.top();
    st.pop();
    insertAtBottom(st,ele);
    st.push(topele);
}

void reverseStack(stack<int> &st){
    if(st.empty()){
        return;
    }

    int ele = st.top();
    st.pop();
    reverseStack(st);
    insertAtBottom(st, ele);
}

int main(){
    stack<int>st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);

    cout<<"\n\nReversed Stack: "<<endl;

    reverseStack(st);
    while(!st.empty()){
        cout<<st.top()<<endl;
        st.pop();
    }
    return 0;
}