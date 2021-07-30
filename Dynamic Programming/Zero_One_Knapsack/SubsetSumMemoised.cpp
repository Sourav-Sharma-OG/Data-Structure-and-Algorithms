
#include<bits/stdc++.h>
using namespace std;

int dp[1000][1000];

bool isSubsetSum(int arr[], int n, int sum){
    if(sum == 0){
        return true;
    }

    if(n <= 0){
        return false;
    }

    if(dp[n-1][sum] != -1){
        return dp[n-1][sum];
    }

    if(arr[n-1] <= sum){
        return dp[n-1][sum] = isSubsetSum(arr, n-1, sum - arr[n-1]) || isSubsetSum(arr, n-1, sum);
    }
    else{
        return dp[n-1][sum] = isSubsetSum(arr, n-1, sum);
    }
}

int main(){
    memset(dp, -1, sizeof(dp));
    int set[] = {3, 34, 4, 12, 5, 2};
    int sum = 9;
    int n = sizeof(set)/sizeof(set[0]);


    cout<<isSubsetSum(set, n, sum);

}