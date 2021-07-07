#include<iostream>
using namespace std;

#define n 100

class stack
{
    int* arr;
    int top;

    public:
    stack()
    {
        arr = new int[n];
        top = -1;
    }

    void push(int x)
    {
        if(top == n-1)
        {
            cout<<"Stack Overflow."<<endl;
            return;
        }
        top++;
        arr[top] = x;
    }

    void pop()
    {
        if(top == -1)
        {
            cout<<"Stack Underflow."<<endl;
            return;
        }
        top--;
    }

    int Top()
    {
        if(top == -1)
        {
            cout<<"No element in Stack."<<endl;
            return -1;
        }
        return arr[top];
    }

    bool empty()
    {
        if(top == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

int main()
{
    stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    st.push(6);

    cout<<"Top elements is ";
    cout<<st.Top()<<endl;
    st.pop();

    cout<<"After pop() top element is ";
    cout<<st.Top()<<endl;
    st.pop();
    st.pop();
    st.pop();
    st.pop();
    st.pop();
    st.pop();
    st.pop();
    cout<<"After pop() all the elements ";
    cout<<st.empty()<<endl;

    return 0;

}