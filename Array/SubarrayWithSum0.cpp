/*
Given an array of positive and negative numbers. Find if there is a subarray (of size at-least one) with 0 sum.
Example 1:
Input:
5
4 2 -3 1 6
Output: 
Yes
Explanation: 
2, -3, 1 is the subarray with sum 0.

  sum=3
    !
    [4] 2 -3 1 6

     sum = 3  ------> Already present in set--: RETURN true.
    <------->    
    [4 2 -3 1] 6

*/

#include<bits/stdc++.h>
using namespace std;

bool found(int arr[], int n){
    unordered_set<int> check;
    int sum = 0;

    for(int i = 0; i< n; i++){
        sum += arr[i];
        if(sum == 0 || check.find(sum) != check.end()){
            return true;
        }
        check.insert(sum);
    }
    return false;
}

int main(){
    int arr[] = {4, 2, -3, 1, 6};
    int n = sizeof(arr)/sizeof(arr[0]);
    if(found(arr, n)){
        cout<<"Subarray with sum 0 exists.";
    }
    else{
        cout<<"Subarray with 0 doesn't exist.";
    }

    return 0;
}