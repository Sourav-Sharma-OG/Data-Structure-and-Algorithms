/*
Find the value of n raised to the power p.
*/

#include<iostream>
using namespace std;

int power(int n, int p){
    if(p == 0){
        return 1;
    }

    int pervPower = power(n, p-1);
    return n * pervPower;
}

int main(){
    int n , p;
    cin>>n>>p;
    cout<<power(n, p);
    return 0;
}