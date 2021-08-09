#include<bits/stdc++.h>
using namespace std;

string printLcs(string x, string y){
    int a = x.length();
    int b = y.length();

    int dp[a+1][b+1];

    for(int i = 0; i<=a; i++){
        for(int j = 0; j<=b; j++){
            if(i == 0 || j == 0){
                dp[i][j] = 0;
            }

            else if(x[i-1] == y[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }

            else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    int i = a; int j = b;
    string ans = "";

    while(i > 0 && j > 0){
        if(x[i-1] == y[j-1]){
            ans += x[i-1];
            i--;
            j--;
        }

        else if(dp[i][j-1] > dp[i-1][j]){
            j--;
        }
        else{
            i--;
        }
    }

    reverse(ans.begin(), ans.end());
    return ans;
}

int main(){
    string x = "acbcf";
    string y = "abcdaf";
    cout<<printLcs(x, y);

}