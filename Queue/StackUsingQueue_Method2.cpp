#include<bits/stdc++.h>
using namespace std;

class StacK{
    int N;
    queue<int>q1; 
    queue<int>q2;

    public:
    StacK(){
        N = 0;
    }

    void push(int val){
        q1.push(val);
        N++;
    }
    void pop(){
        if(q1.empty()){
            cout<<"Queue is already empty.";
            return;
        }

        while(q1.size() != 1){
            q2.push(q1.front());
            q1.pop();
        }
        q1.pop();
        queue<int>temp = q1;
        q1 = q2;
        q2 = temp;
        N--;
    }

    int top(){
        if(q1.empty()){
            cout<<"Queue is already empty.";
            return -1;
        }

        while(q1.size() != 1){
            q2.push(q1.front());
            q1.pop();
        }

        int ans  = q1.front();
        q1.pop();
        q2.push(ans);
        queue<int>temp = q1;
        q1 = q2;
        q2 = temp;

        return ans;
    }

    int size(){
        return N;
    }
};

int main(){
    StacK s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);

    cout<<"size: "<<s.size()<<endl;
    cout<<"s.top(): "<<s.top()<<endl;
    s.pop();

    cout<<"size: "<<s.size()<<endl;
    cout<<"s.top(): "<<s.top()<<endl;
    s.pop();

    cout<<"size: "<<s.size()<<endl;
    cout<<"s.top(): "<<s.top()<<endl;
    s.pop();

    cout<<"size: "<<s.size()<<endl;
    cout<<"s.top(): "<<s.top()<<endl;
    s.pop();

    cout<<"size: "<<s.size()<<endl;
    cout<<"s.top(): "<<s.top()<<endl;
    s.pop();


    return 0;
}