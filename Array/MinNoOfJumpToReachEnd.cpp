/*
Given an array of N integers arr[] where each element represents the max number of steps that can be made forward from that element. Find the minimum number of jumps to reach the end of the array (starting from the first element). If an element is 0, then you cannot move through that element.
Note: Return -1 if you can't reach the end of the array.


Example 1:

Input:
N = 11 
arr[] = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9} 
Output: 3 
Explanation: 
First jump from 1st element to 2nd 
element with value 3. Now, from here 
we jump to 5th element with value 9, 
and from here we will jump to last. 
*/

#include<bits/stdc++.h>
using namespace std;

int minNoOfSteps(vector<int> arr){
    int n = arr.size();
    int dp[n];
    dp[n-1] = 0;
    int min;

    for(int i = n-2; i>=0; i--){
        if(arr[i] == 0){
            dp[i] = INT_MAX;
        }

        else if(arr[i] + i >= n-1){
            dp[i] = 1;
        }

        else{
            min = INT_MAX;
            for(int j = i+1; j<=arr[i] + i; j++){
                if(dp[j] < min){
                    min = dp[j];
                }
            }

            if(min != INT_MAX){
                dp[i] = min + 1;
            }
            else{
                dp[i] = min; //INT_MAX
            }
        }
    }

    return dp[0] == INT_MAX ? -1 : dp[0];
}

int main(){
    vector<int> arr = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9};
    cout<<minNoOfSteps(arr);
    return 0;
}