/*
Given a sequence of matrices, find the most efficient way to multiply these matrices together. The efficient way is the one that involves the least number of multiplications.

The dimensions of the matrices are given in an array arr[] of size N (such that N = number of matrices + 1) where the ith matrix has the dimensions (arr[i-1] x arr[i]).

Example 1:

Input: N = 5
arr = {40, 20, 30, 10, 30}
Output: 26000
Explaination: There are 4 matrices of dimension 
40x20, 20x30, 30x10, 10x30. Say the matrices are 
named as A, B, C, D. Out of all possible combinations,
the most efficient way is (A*(B*C))*D. 
The number of operations are -
20*30*10 + 40*20*10 + 40*10*30 = 26000.
*/

#include<iostream>
using namespace std;

int minCost(int arr[], int i, int j){
    if(i >= j){
        return 0;
    }

    int ans = INT32_MAX;
    for(int k = i; k<=j-1; k++){
        int tempAns = minCost(arr, i, k) + minCost(arr, k+1, j) + arr[i-1] * arr[k] * arr[j];
        ans = min(tempAns, ans);
    }

    return ans;
}

int main(){
    int arr[] = {40, 20, 30, 10, 30};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout<<minCost(arr, 1, n-1);

    return 0;
}