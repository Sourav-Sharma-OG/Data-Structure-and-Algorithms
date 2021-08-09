/**
 * Minimum number of deletions to make a string palindrome
Given a string of size ‘n’. The task is to remove or delete the minimum number of characters from the string so that the resultant string is a palindrome. 

Note: The order of characters should be maintained. 

Examples : 

Input : aebcbda
Output : 2
Remove characters 'e' and 'd'
Resultant string will be 'abcba'
which is a palindromic string

Input : geeksforgeeks
Output : 8
 */


#include<bits/stdc++.h>
using namespace std;

int minNoOfDel(string s){
    string s1 = s;
    reverse(s1.begin(), s1.end());

    int m = s.length();

    int dp[m+1][m+1];

    for(int i = 0; i<=m; i++){
        for(int j = 0; j<=m; j++){
            if(i == 0 || j == 0){
                dp[i][j] = 0;
            }

            else if(s[i-1] == s1[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }

            else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    return m - dp[m][m];
}

int main(){
    string s = "geeksforgeeks";
    cout<<minNoOfDel(s);

    return 0;
}
