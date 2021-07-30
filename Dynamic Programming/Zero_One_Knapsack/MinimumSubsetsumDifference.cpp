/*
Given a set of integers, the task is to divide it into two sets S1 and S2 such that the absolute difference between their sums is minimum. 
If there is a set S with n elements, then if we assume Subset1 has m elements, Subset2 must have n-m elements and the value of abs(sum(Subset1) – sum(Subset2)) should be minimum.

Example: 

Input:  arr[] = {1, 6, 11, 5} 
Output: 1
Explanation:
Subset1 = {1, 5, 6}, sum of Subset1 = 12 
Subset2 = {11}, sum of Subset2 = 11   
*/

#include<bits/stdc++.h>
using namespace std;

vector<int> subsetSum(int arr[], int n, int sum){
    int dp[n+1][sum+1];

    for(int i = 0; i<=n; i++)
        dp[i][0] = 1;
    
    for(int i = 1; i<=sum; i++)
        dp[0][i] = 0;

    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=sum; j++){
            if(arr[i-1] <= j){
                dp[i][j] = dp[i-1][j] || dp[i-1][j - arr[i-1]];
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    vector<int>ans;
    for(int i = 0; i<=sum/2; i++){
        if(dp[n][i] == 1){
            ans.push_back(i);
        }
    }
    return ans;
}

int minSubsetsumDifference(int arr[], int n){
    int range = 0;
    for(int i = 0; i<n; i++){
        range += arr[i];
    }

    //Find all the values in the (0 - range) that are the subset sum of given array.
    vector<int>lastRow = subsetSum(arr, n, range);

    int minimum = INT_MAX;
    for(int i = 0; i<lastRow.size(); i++){
        int temp = range - (2 * lastRow[i]);
        minimum = min(minimum, temp);
    }

    return minimum;
}

int main(){
    int arr[] = {1, 6, 11, 5, 3, 8};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout<<minSubsetsumDifference(arr, n);
}