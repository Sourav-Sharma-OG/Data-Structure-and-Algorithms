/*
Given an integer N, find its factorial.

Example 1:

Input: N = 5
Output: 120
Explanation : 5! = 1*2*3*4*5 = 120
Example 2:

Input: N = 10
Output: 3628800
Explanation :
10! = 1*2*3*4*5*6*7*8*9*10 = 3628800
*/

#include<bits/stdc++.h>
using namespace std;

void multiply(int n, vector<int> &number){
    int carry = 0;
    for(int i = 0; i<number.size(); i++){
        int num = n * number[i];
        number[i] = (carry + num) % 10;
        carry = (carry + num) / 10;
    }

    while(carry){
        number.push_back(carry % 10);
        carry /= 10;
    }
}

vector<int>factorial(int n){
    vector<int>number;
    number.push_back(1);

    for(int i = 2; i<=n; i++){
        multiply(i, number);
    }
    reverse(number.begin(), number.end());
    return number;
}

int main(){
    int n;
    cin>>n;
    vector<int>fact = factorial(n);
    for(auto i : fact){
        cout<<i;
    }

    return 0;
}