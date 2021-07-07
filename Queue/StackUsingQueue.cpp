#include<bits/stdc++.h>
using namespace std;

class Stack{
    queue<int>q1;
    queue<int>q2;
    int N;

    public:
    Stack(){
        N = 0;
    }

    void push(int a){
        q2.push(a);
        N++;
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }
        queue<int>temp  = q1;
        q1 = q2;
        q2 = temp;
    }

    void pop(){
        q1.pop();
        N--;
    }

    int top(){
        return q1.front();
    }

    int size(){
        return N;
    }

};

int main(){
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    cout<<"Current Size: "<<s.size()<<endl;
    cout<<s.top()<<endl;
    s.pop();
    
    cout<<s.top()<<endl;
    s.pop();
    
    cout<<"Current Size: "<<s.size()<<endl;
    cout<<s.top()<<endl;
    s.pop();
    
    cout<<s.top()<<endl;
    s.pop();

    cout<<"Current Size: "<<s.size();
    return 0;
}