/*
Given two strings str1 and str2, the task is to find the length of the shortest string that has both str1 and str2 as subsequences.

Examples : 

Input:   str1 = "geek",  str2 = "eke"
Output: 5
Explanation: 
String "geeke" has both string "geek" 
and "eke" as subsequences.

Input:   str1 = "AGGTAB",  str2 = "GXTXAYB"
Output:  9
Explanation: 
String "AGXGTXAYB" has both string 
"AGGTAB" and "GXTXAYB" as subsequences.
*/

#include<bits/stdc++.h>
using namespace std;

int shortestCommonSupersequence(string s1, string s2){
    int m = s1.length();
    int n = s2.length();

    int dp[m+1][n+1];
    for(int i = 0; i<=m; i++){
        for(int j = 0; j<=n; j++){
            if(i == 0 || j == 0){
                dp[i][j] = 0;
            }

            else if(s1[i-1] == s2[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }

            else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    return (m + n - dp[m][n]);
}

int main(){
    string str1 = "geek";
    string str2 = "eke";
    cout<<shortestCommonSupersequence(str1, str2);
}