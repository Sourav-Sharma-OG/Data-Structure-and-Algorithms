#include<bits/stdc++.h>
using namespace std;

int lcs(string s1, string s2){
    int x = s1.length();
    int y = s2.length();

    int dp[x+1][y+1];
    for(int i = 0; i<=x; i++){
        for(int j = 0; j<=y; j++){
            if(i == 0 || j == 0){
                dp[i][j] = 0;
            }

            else if(s1[i] == s2[j]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }

            else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    return dp[x][y];
}

int main(){
    string s1 = "abcdaf";
    string s2 = "acbcf";
    cout<<lcs(s1, s2);
}