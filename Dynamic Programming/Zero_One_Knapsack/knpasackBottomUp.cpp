#include<bits/stdc++.h>
using namespace std;

int knapsack(int wt[], int val[], int W, int n){
    //Creating dp matrix.
    int dp[n+1][W+1];

    for(int i = 0; i<= n; i++){
        for(int j = 0; j<= W; j++){
            if(i == 0 || j == 0){
                dp[i][j] = 0;
            }

            else if(wt[i-1] <= j){
                dp[i][j] = max(val[i-1] + dp[i-1][j-wt[i-1]], dp[i-1][j]);
            }

            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][W];
}

int main(){
    int wt[] = {1,3,4,5};
	int val[] = {1,4,5,7};
	int n = sizeof(wt)/sizeof(wt[0]);
	int W = 7;
	
	cout<<knapsack(wt, val, W, n);
}