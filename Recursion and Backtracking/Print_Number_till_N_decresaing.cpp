/*
WAP to print number till n in decreasing order.
*/

#include<iostream>
using namespace std;

void printDec(int n){
    if(n == 0){
        cout<<n;
        return;
    }
    cout<<n<<" ";
    return printDec(n-1);
}

int main(){
    int n;
    cin>>n;
    printDec(n);
    return 0;
}