#include<bits/stdc++.h>
using namespace std;

int minOperations(string s, string t){
    int m = s.length();
    int n = t.length();

    int dp[m+1][n+1];
    
    for(int i = 0; i <= m; i++){
        for(int j = 0; j <= n; j++){
            if(i == 0){
                dp[i][j] = j;
            }
            else if(j == 0){
                dp[i][j] = i;
            }
            else if(s[i-1] == t[j-1]){
                dp[i][j] = dp[i-1][j-1];
            }
            else{
                dp[i][j] = 1 + min(dp[i-1][j-1], min(dp[i][j-1], dp[i-1][j]));
            }
        }
    }
    return dp[m][n];
}

int main(){
    string s = "geek";
    string t = "gesek";
    cout<<minOperations(s, t);
    return 0;
}