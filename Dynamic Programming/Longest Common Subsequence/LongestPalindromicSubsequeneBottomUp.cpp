#include<bits/stdc++.h>
using namespace std;

int lps(string s){
    string s1 = s;
    reverse(s1.begin(), s1.end());

    int m = s.length();

    int dp[m+1][m+1];
    for(int i = 0; i<=m;i++){
        for(int j = 0; j<=m; j++){
            if(i == 0 || j == 0){
                dp[i][j] = 0;
            }
            
            else if(s[i-1] == s1[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }

            else{
                dp[i][j] = max(dp[i][j-1] ,dp[i-1][j]);
            }
        }
    }

    return dp[m][m];
}

int main(){
    string s = "geeksforgeeks";
    cout<<lps(s);
}