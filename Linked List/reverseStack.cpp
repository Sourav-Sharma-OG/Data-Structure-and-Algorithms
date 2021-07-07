#include<iostream>
#include<stack>
using namespace std;

void insertionAtBottom(stack<int> &st,int ele)
{
    if(st.empty())
    {
        st.push(ele);
        return;
    }

    int topElement = st.top();
    st.pop();
    insertionAtBottom(st, ele);
    
    st.push(topElement);
}

void reverseStack(stack<int> &st)
{
    if(st.empty())
    {
        return;
    }

    int ele = st.top();
    st.pop();
    reverseStack(st);
    insertionAtBottom(st, ele);
}


int main()
{
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);

    // cout<<"Original stack is:- "<<endl;
    // while(! st.empty())
    // {
    //     cout<<st.top()<<endl;
    //     st.pop();
    // }

    cout<<"\nReversed stack is:- "<<endl;
    reverseStack(st);
    while(! st.empty())
    {
        cout<<st.top()<<endl;
        st.pop();
    }
}