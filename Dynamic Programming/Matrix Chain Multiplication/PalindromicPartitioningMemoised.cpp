#include<bits/stdc++.h>
using namespace std;
int dp[501][501];

bool isPalindrome(string s, int i, int j){
    while(i < j){
        if(s[i] != s[j]){
            return false;
        }

        i++;
        j--;
    }
    return true;
}

int palindromicPartitions(string s, int i, int j){
    if(dp[i][j] != -1){
        return dp[i][j];
    }

    if(i >= j || isPalindrome(s, i , j)){
        return dp[i][j] = 0;
    }

    int ans = INT_MAX;
    for(int k = i; k<=j-1; k++){
        int tempAns = palindromicPartitions(s, i, k) + palindromicPartitions(s, k+1, j) + 1;

        ans = min(ans, tempAns);
    }

    return dp[i][j] = ans;
}

int main(){
    memset(dp, -1, sizeof(dp));
    string s = "geek";
    cout<<palindromicPartitions(s, 0, s.length() - 1);

    return 0;
}