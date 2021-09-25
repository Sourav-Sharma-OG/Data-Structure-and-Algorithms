/*
Given two strings s and t. Find the minimum number of operations that need to be performed on str1 to convert it to str2. The possible operations are:
->Insert
->Remove
->Replace
Example 1:
Input: 
s = "geek", t = "gesek"
Output: 1
Explanation: One operation is required 
inserting 's' between two 'e's of str1.
Example 2:
Input : 
s = "gfg", t = "gfg"
Output: 
0
Explanation: Both strings are same.
*/

#include<bits/stdc++.h>
using namespace std;

int helper(string s, string t, int i , int j, vector<vector<int>> &dp){
    if(dp[i][j] != -1){
        return dp[i][j];
    }

    if(i == 0){
        return dp[i][j] = j;
    }

    if(j == 0){
        return dp[i][j] = i;
    }

    if(s[i-1] == t[j-1]){
        return dp[i][j] = helper(s, t, i-1, j-1, dp);
    }
    else{
        return dp[i][j] = min(helper(s, t, i-1, j-1, dp) + 1,
         min(helper(s, t, i-1, j, dp) + 1, helper(s, t, i, j-1, dp) + 1));
    }
}

int minOperations(string s, string t){
    vector<vector<int>>dp(s.length() + 1, vector<int>(t.length() + 1, -1));
    return helper(s, t, s.length(), t.length(), dp);
}

int main(){
    string s = "geek";
    string t = "gesek";
    cout<<minOperations(s, t);
    return 0;
}