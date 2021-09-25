/*
Stickler the thief wants to loot money from a society having n houses in a single line. He is a weird person and follows a certain rule when looting the houses. According to the rule, he will never loot two consecutive houses. At the same time, he wants to maximize the amount he loots. The thief knows which house has what amount of money but is unable to come up with an optimal looting strategy. He asks for your help to find the maximum money he can get if he strictly follows the rule. Each house has a[i] amount of money present in it.

Example 1:

Input:
n = 6
a[] = {5,5,10,100,10,5}
Output: 110
Explanation: 5+100+5=110
Example 2:

Input:
n = 3
a[] = {1,2,3}
Output: 4
Explanation: 1+3=4
*/

#include<bits/stdc++.h>
using namespace std;

int helper(int arr[], int n, int idx, vector<int>&dp){
    if(idx >= n){
        return 0;
    }
    else if(dp[idx] != -1){
        return dp[idx];
    }

    return dp[idx] = max(arr[idx] + helper(arr, n, idx + 2, dp), helper(arr, n, idx + 1, dp));
}

int maxLoot(int arr[], int n){
    vector<int>dp(n, -1);
    return helper(arr, n, 0, dp);
}

int main(){
    int arr[] = {5,5,10,100,10,5};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout<<maxLoot(arr, n);
    return 0;
}