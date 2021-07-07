/*

1   2   3   4   5

5   4   3   2   1

*/


#include<bits/stdc++.h>
using namespace std;

queue<int> rev(queue<int>q){
    stack<int>st;

    while(!q.empty()){
        st.push(q.front());
        q.pop();
    }

    while(!st.empty()){
        q.push(st.top());
        st.pop();
    }
    return q;
}

void print(queue<int>q){
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;
}

int main(){
    queue<int>q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    print(q);
    queue<int>temp = rev(q);
    print(temp);
    return 0;
}