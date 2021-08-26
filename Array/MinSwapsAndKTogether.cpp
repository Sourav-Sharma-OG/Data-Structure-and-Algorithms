/*
Given an array of n positive integers and a number k. Find the minimum number of swaps required to bring all the numbers less than or equal to k together.

Example 1:

Input : arr[ ] = {2, 1, 5, 6, 3} and K = 3
Output : 1
Explanation:
To bring elements 2, 1, 3 together, swap element '5' with '3'
such that final array will be- arr[] = {2, 1, 3, 6, 5}
*/

#include<bits/stdc++.h>
using namespace std;

int minSwaps(int arr[], int n, int k){
    int count = 0;
    int minSwaps = INT_MAX;
    int bad = 0;

    //Calculating the no of elements less than or equal to k i.e count
    for(int i = 0; i<n; i++){
        if(arr[i] >= k){
            count++;
        }
    }

    //Calculate the no of elements in the window of count which are greater than k
    for(int i = 0; i<count; i++){
        if(arr[i] > k){
            bad++;
        }
    }

    minSwaps = min(minSwaps, bad);
    for(int i = 1; i <= n-count; i++){
        if(arr[i-1] > k){
            bad--;
        }
        if(arr[i+count-1] > k){
            bad++;
        }
        minSwaps = min(minSwaps, bad);
    }
    return minSwaps;
}

int main(){
    int arr[] = {2, 7, 9, 5, 8, 7, 4};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 6;
    cout<<minSwaps(arr, n, k);
    return 0;
}