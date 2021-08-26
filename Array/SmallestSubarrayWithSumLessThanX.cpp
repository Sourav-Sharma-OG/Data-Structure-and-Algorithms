/*
Given an array of integers (A[])  and a number x, find the smallest subarray with sum greater than the given value.
Note: The answer always exists. It is guaranteed that x doesn't exceed the summation of a[i] (from 1 to N).
Example 1:
Input:
A[] = {1, 4, 45, 6, 0, 19}
x  =  51
Output: 3
Explanation:
Minimum length subarray is 
{4, 45, 6}
*/

#include<bits/stdc++.h>
using namespace std;

int minSubarrayLen(int arr[], int n, int x){
    int start = 0, end = 0;
    int minLen = INT_MAX;
    int currSum = 0;

    while(start < n){
        while(currSum <= x && start < n){
            currSum += arr[start++];
        }

        while(currSum > x && end < n){
            minLen = min(minLen, start - end);
            currSum -= arr[end++];
        }
    }

    return minLen > n ? 0 : minLen;
}

int main(){
    int arr[] = {1, 4, 45, 6, 0, 19};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 51;
    cout<<minSubarrayLen(arr, n, x);
}