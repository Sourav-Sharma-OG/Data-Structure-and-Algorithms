/*
Given two strings ‘X’ and ‘Y’, find the length of the longest common substring. 

Examples : 

Input : X = “GeeksforGeeks”, y = “GeeksQuiz” 
Output : 5 
Explanation:
The longest common substring is “Geeks” and is of length 5.

Input : X = “abcdxyz”, y = “xyzabcd” 
Output : 4 
Explanation:
The longest common substring is “abcd” and is of length 4.

Input : X = “zxabcdezy”, y = “yzabcdezx” 
Output : 6 
Explanation:
The longest common substring is “abcdez” and is of length 6.

*/
#include<bits/stdc++.h>
using namespace std;

int longestCommonSubstr(string x, string y){
    int a = x.length();
    int b = y.length();

    int dp[a+1][b+1];
    int maxVal = 0;

    for(int i = 0; i<=a; i++){
        for(int j = 0; j<=b; j++){
            if(i == 0 || j == 0){
                dp[i][j] = 0;
            }

            else if(x[i-1] == y[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
                maxVal = max(maxVal, dp[i][j]);
            }
            else{
                dp[i][j] = 0;
            }
        }
    }

    return maxVal;
}

int main(){
    string x = "GeeksforGeeks";
    string y = "Geeks";
    cout<<longestCommonSubstr(x, y);
}