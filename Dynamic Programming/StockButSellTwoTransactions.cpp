/*
You are given an array prices where prices[i] is the price of a given stock on the ith day.

Find the maximum profit you can achieve. You may complete at most two transactions.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

 

Example 1:

Input: prices = [3,3,5,0,0,3,1,4]
Output: 6
Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.
*/

#include<bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> &arr){
    int n = arr.size();
    
    //Storing the maximum profit by taking care of least buying price.
    //i.e we will buy at least selling price and try to sell at each and every day
    //and store that value which will give us highest profit.
    int curPl = 0;
    int leastBP = arr[0];
    int maxFromLeft[n];
    maxFromLeft[0] = 0;

    for(int i = 1; i<n; i++){
        if(arr[i] < leastBP){
            leastBP = arr[i];
        }
        curPl = arr[i] - leastBP;
        if(curPl > maxFromLeft[i-1]){
            maxFromLeft[i] = curPl;
        }
        else{
            maxFromLeft[i] = maxFromLeft[i-1];
        }
    }

    //Now we store the max profit by taking care of max selling price.
    //i.e we will sell the stock when the price is maximum and then try to find the min buying day.
    //i.e we will check for each and every day and store  the max  profit.
    int curPr = 0;
    int maxSP = arr[n-1];
    int maxFromRight[n];
    maxFromRight[n-1] = 0;

    for(int i = n-2;i >= 0; i--){
        if(arr[i] > maxSP){
            maxSP = arr[i];
        }
        curPr = maxSP - arr[i];
        if(curPr > maxFromRight[i+1]){
            maxFromRight[i] = curPr;
        }
        else{
            maxFromRight[i] = maxFromRight[i+1];
        }
    }

    int maxProfit = INT_MIN;
    for(int i = 0; i<n; i++){
        maxProfit = max(maxProfit, maxFromLeft[i] + maxFromRight[i]);
    }

    return maxProfit;
}

int main(){
    vector<int>prices = {3, 3, 5, 0, 0, 3, 1, 4};
    cout<<maxProfit(prices);
    cout<<endl;
}