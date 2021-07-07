#include<iostream>
using namespace std;

#define n 100

class Stack{
    int *arr;
    int top;
    public:

    Stack(){
        arr = new int[n];
        top = -1;
    }

    void push(int val){
        if(top == n-1){
            cout<<"Stack Overflow";
            return;
        }
        top++;
        arr[top] = val;
    }

    void pop(){
        if(top == -1){
            cout<<"Stack Underflow.";
            return;
        }
        top--;
    }

    int Top(){
        if(top == -1){
            cout<<"Stack Underflow. No element present in the stack.";
            return -1;
        }
        return arr[top];
    }

    bool empty(){
        if(top == -1){
            return true;
        }
        return false;
    }
};

int main(){
    Stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    st.push(6);

    cout<<st.Top()<<endl;
    st.pop();

    cout<<st.Top()<<endl;
    st.pop();

    cout<<st.Top()<<endl;
    st.pop();

    cout<<st.Top()<<endl;
    st.pop();

    cout<<st.Top()<<endl;
    st.pop();

    cout<<st.Top()<<endl;
    st.pop();

    cout<<st.Top()<<endl;
    st.pop();

    cout<<st.empty();
    
    return 0;
}