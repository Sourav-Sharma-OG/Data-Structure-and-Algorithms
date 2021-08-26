/*
Given an array of positive integers. We need to make the given array a ‘Palindrome’. The only allowed operation is”merging” (of two adjacent elements). Merging two adjacent elements means replacing them with their sum. The task is to find the minimum number of merge operations required to make the given array a ‘Palindrome’.
To make any array a palindrome, we can simply apply merge operation n-1 times where n is the size of the array (because a single-element array is always palindromic, similar to single-character string). In that case, the size of array will be reduced to 1. But in this problem, we are asked to do it in the minimum number of operations.
Example : 
Input : arr[] = {15, 4, 15}
Output : 0
Array is already a palindrome. So we do not need any merge operation.
Input : arr[] = {1, 4, 5, 1}
Output : 1
We can make given array palindrome with minimum one merging (merging 4 and 5 to make 9)
Input : arr[] = {11, 14, 15, 99}
Output : 3
We need to merge all elements to make a palindrome.
*/

#include<bits/stdc++.h>
using namespace std;

int minOperations(int arr[], int n){
    int ans = 0;
    for(int i = 0, j = n-1; i<=j;){
        if(arr[i] == arr[j]){
            i++;
            j--;
        }

        else if(arr[i] > arr[j]){
            j--;
            arr[j] = arr[j] + arr[j+1];
            ans++;
        }

        else if(arr[i] < arr[j]){
            i++;
            arr[i] = arr[i] + arr[i-1];
            ans++;
        }
    }
    return ans;
}

int main(){
    int arr[] = {23, 14, 23, 45, 14, 34};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout<<minOperations(arr, n);
    return 0;
}