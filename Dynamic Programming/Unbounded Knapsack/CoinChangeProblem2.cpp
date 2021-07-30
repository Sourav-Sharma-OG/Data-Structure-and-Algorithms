/*
Given a value V, if we want to make change for V cents, and we have infinite supply of each of C = { C1, C2, .. , Cm} valued coins, what is the minimum number of coins to make the change? If it’s not possible to make change, print -1.

Examples:  

Input: coins[] = {25, 10, 5}, V = 30
Output: Minimum 2 coins required
We can use one coin of 25 cents and one of 5 cents 

Input: coins[] = {9, 6, 5, 1}, V = 11
Output: Minimum 2 coins required
We can use one coin of 6 cents and 1 coin of 5 cents
*/

#include<bits/stdc++.h>
using namespace std;

int minNoOfCoins(int coins[], int n, int sum){
    int dp[n+1][sum+1];

    //Init the first row with INT_MAX - 1 
    //--> If we have 0 coins in the coins array, then we need Infinite no. to coins to make sum.

    for(int i = 0; i<=sum; i++)
        dp[0][i] = INT_MAX - 1;
    
    //Init the first column except [0][0] with 0, because if the sum is 0, then we don't need any coin.

    for(int i = 1; i<=n; i++)
        dp[i][0] = 0;

    //Init the second row 
    //--> If the  ith coins is completely divisible by j then we store j / coins[i] at the second row 
    //--> Else we store INT_MAX - 1 at that particular index.
    //--> E.g-> coins[i] = 3 and j value is 1, then we can never make 1 with a 3 rupee coin. So we fill INT_MAX - 1 there.

    for(int i = 1, j = 1; j<=sum; j++){
        if(j % coins[i-1] == 0){
            dp[i][j] = j / coins[i-1];
        }
        else{
            dp[i][j] = INT_MAX - 1;
        }
    }

    //Filling rest of the matrix.

    for(int i = 2; i<=n; i++){
        for(int j = 1; j <= sum; j++){
            if(coins[i-1] <= j){
                dp[i][j] = min(1 + dp[i][j - coins[i-1]], dp[i-1][j]);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    return dp[n][sum];
}

int main(){
    int coins[] = {25, 10, 5};
    int V = 30;
    int M = sizeof(coins)/sizeof(coins[0]);
    cout<<minNoOfCoins(coins, M, V);
}