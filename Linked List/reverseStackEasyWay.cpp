#include<iostream>
#include<stack>
using namespace std;

void reverseStack(stack<int>st1)
{
    stack<int>st2;
    if(st1.empty())
    {
        return;
    }

    while(!st1.empty())
    {
        int ele = st1.top();
        st2.push(ele);
        st1.pop();
    }
    while (!st2.empty())
    {
        cout<<st2.top()<<endl;
        st2.pop();
    }
}

int main()
{
    stack<int>st1;
    st1.push(1);
    st1.push(2);
    st1.push(3);
    st1.push(4);
    st1.push(5);

    // cout<<"Original Stack is:- "<<endl;
    // while(!st1.empty())
    // {
    //     cout<<st1.top()<<endl;
    //     st1.pop();
    // }
    cout<<"\nReversed stack is:- "<<endl;

    reverseStack(st1);

}