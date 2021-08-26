/*
Given a string s, return the longest palindromic substring in s.
Example 1:
Input: s = "babad"
Output: "bab"
Note: "aba" is also a valid answer.
Example 2:
Input: s = "cbbd"
Output: "bb"
*/

#include<bits/stdc++.h>
using namespace std;

string longestPalindromicSubstring(string s){
    int n = s.length();
    if(n == 1){
        return s;
    }
    
    bool dp[n][n];

    int maxI, maxJ;

    for(int gap = 0; gap < n; gap++){
        for(int i = 0, j = gap; j<n; i++, j++){
            if(gap == 0){
                dp[i][j] = true;
            }
            else if(gap == 1){
                if(s[i] == s[j]){
                    dp[i][j] = true;
                }
                else{
                    dp[i][j] = false;
                }
            }
            else{
                if(s[i] == s[j] && dp[i+1][j-1] == true){
                    dp[i][j] = true;
                }
                else{
                    dp[i][j] = false;
                }
            }

            if(dp[i][j]){
                maxI = i;
                maxJ = j;
            }
        }
    }

    string result;
    for(int i = maxI; i<=maxJ; i++){
        result += s[i];
    }
    return result;
}

int main(){
    string s;
    cin>>s;
    cout<<longestPalindromicSubstring(s);
    return 0;
}