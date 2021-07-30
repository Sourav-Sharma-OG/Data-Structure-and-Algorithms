#include<bits/stdc++.h>
using namespace std;

int subsetsWithSumK(int arr[], int n, int k){
    int dp[n + 1][k + 1];

    for(int i = 0; i<=n; i++)
        dp[i][0] = 1;
    
    for(int i = 1; i<=k; i++)
        dp[0][i] = 0;

    for(int i = 1; i<=n; i++){
        for(int j = 1;j<=k; j++){
            if(arr[i-1] <= j){
                dp[i][j] = dp[i-1][j] + dp[i-1][j - arr[i-1]];
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    return dp[n][k];
}

int main(){
    int arr[] = {2,3,5,6,8,10};
    int n = sizeof(arr) / sizeof(arr[0]);
    int sum = 10;

    cout<<subsetsWithSumK(arr, n, sum);

}