#include<iostream>
#include<queue>
using namespace std;


int main(){
    priority_queue<int, vector<int>> pq;
    pq.push(5);
    pq.push(2);
    pq.push(7);
    pq.push(1);

    cout<<pq.top()<<endl;
    pq.pop();

    cout<<pq.top()<<endl;
    pq.pop();

    cout<<pq.top()<<endl;
    pq.pop();

    cout<<pq.top()<<endl;
    pq.pop();


    priority_queue<int, vector<int>, greater<int>> pqm;
    pqm.push(25);
    pqm.push(16);
    pqm.push(55);
    pqm.push(51);

    cout<<endl;
    cout<<pqm.top()<<endl;
    pqm.pop();

    cout<<pqm.top()<<endl;
    pqm.pop();

    cout<<pqm.top()<<endl;
    pqm.pop();

    cout<<pqm.top()<<endl;
    pqm.pop();


    return 0;
}