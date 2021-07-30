#include<bits/stdc++.h>
using namespace std;
int dp[1001][1001];

int knapsack(int wt[], int val[], int W, int n){
    if(n == 0 || W == 0){
        return 0;
    }

    if(dp[n][W] != -1){
        return dp[n][W];
    }

    if(wt[n-1] <= W){
        return dp[n][W] = max(val[n-1] + knapsack(wt, val, W - wt[n-1], n-1),
                    knapsack(wt, val, W, n-1));
    }
    else{
        return knapsack(wt, val ,W, n-1);
    }
}

int main(){
    memset(dp, -1, sizeof(dp));
    int wt[] = {1,3,4,5};
	int val[] = {1,4,5,7};
	int n = sizeof(wt)/sizeof(wt[0]);
	int W = 7;
	
	cout<<knapsack(wt, val, W, n);

}