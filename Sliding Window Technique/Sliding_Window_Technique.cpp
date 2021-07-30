/*
This technique shows how a nested for loop in some problems can be converted to a single for loop to reduce the time complexity.
Let’s start with a problem for illustration where we can apply this technique – 

Given an array of integers of size ‘n’.
Our aim is to calculate the maximum sum of ‘k’ 
consecutive elements in the array.

Input  : arr[] = {100, 200, 300, 400}
         k = 2
Output : 700

Input  : arr[] = {1, 4, 2, 10, 23, 3, 1, 0, 20}
         k = 4 
Output : 39
We get maximum sum by adding subarray {4, 2, 10, 23}
of size 4.

Input  : arr[] = {2, 3}
         k = 3
Output : Invalid
There is no subarray of size 3 as size of whole
array is 2.
*/



#include<bits/stdc++.h>
using namespace std;

int calMaxSumOfSubarraySizeK(int arr[], int n, int k){
    int sum = 0;
    for(int i = 0; i<k; i++){
        sum += arr[i];
    }

    int maxSum = sum;
    for(int i = k; i<n; i++){
        sum += arr[i] - arr[i-k];

        maxSum = max(sum, maxSum);
    }

    return maxSum;
}

int main(){

    int arr[] = {1, 4, 2, 10, 23, 3, 1, 0, 20};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 4;

    int ans = calMaxSumOfSubarraySizeK(arr, n, k);
    cout<<"Maximum sumbarray sum of size "<<k<<" is :"<<ans<<endl;
    return 0;
}