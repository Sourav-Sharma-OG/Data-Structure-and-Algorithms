/*
After winning yesterday's match against Australia, Hardik Pandya thought of cooking up a problem. As he is a "champ" and contributes heavily in almost all the wins of India, with all the amount he collects as the man of the match and with the earning of this season's IPL, he bought a new house.

The house looks like a grid of size N(1-indexed). This house consists of NxN rooms. Each of these rooms contain gold plated watches gifted to him by Neeta Ambani. For each room, the room number is equal to the sum of the row number and column number. That means that the first room number is 2 inspite of being 1. 

The number of watches present in the room makes up to the absolute difference betweent the sum of even digits and the sum of odd digits in its room number. 

For example, if the room number is 2134, then the number of gold plated watchs kept in that room will be |(2+4)-(1+3)| = 2

You are given the size of the grid N and you have to print the number of watches Neeta gifted Hardik.

Constraints:
1<=T<=100000
1<=N<=1000000

Input: 

The first line of input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The only line of each test case contains a single integer N.

Output:

For each line, print the answer on a separate line.
*/


#include<bits/stdc++.h>
using namespace std;

void calWatch(int roomNo, int &ans){
    int even = 0;
    int odd = 0;
    while(roomNo){
        int curr = roomNo % 10;
        roomNo /= 10;
        if(curr % 2 == 0){
            even += curr;
        }
        else{
            odd += curr;
        }
    }
    ans += abs(even - odd);
}

int totalWatches(int n){
    int ans = 0;
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=n; j++){
            int roomNo = i + j;
            calWatch(roomNo, ans);
        }
    }
    return ans;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        cout<<totalWatches(n);
        cout<<endl;
    }
    return 0;
}