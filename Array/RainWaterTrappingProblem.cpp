/*
Given an array arr[] of N non-negative integers representing the height of blocks. If width of each block is 1, compute how much water can be trapped between the blocks during the rainy season. 
 

Example 1:

Input:
N = 6
arr[] = {3,0,0,2,0,4}
Output:
10
*/

#include<bits/stdc++.h>
using namespace std;

int findMax(int start, int end, int arr[]){
    int maxi = INT_MIN;
    for(int i = start; i<=end; i++){
        maxi = max(maxi, arr[i]);
    }
    return maxi;
}

int waterTrapped_BruteForce(int arr[], int n){
    int ans = 0;
    for(int i = 0; i<n; i++){
        int leftMax = findMax(0, i, arr);
        int rightMax = findMax(i, n-1, arr);
        ans += min(leftMax, rightMax) - arr[i];
    }
    return ans;
}

int waterTrapped_Optimal(int arr[], int n){
    int ans = 0;
    int prefixMax[n], suffixMax[n];
    prefixMax[0] = arr[0];
    suffixMax[n-1] = arr[n-1];

    for(int i = 1; i<n; i++){
        prefixMax[i] = max(arr[i], prefixMax[i-1]);
    }

    for(int i = n-2; i>=0; i--){
        suffixMax[i] = max(arr[i], suffixMax[i+1]);
    }

    for(int i = 0; i<n; i++){
        ans += min(prefixMax[i], suffixMax[i]) - arr[i];
    }
    return ans;
}

int waterTrapped_MostOptimal(int arr[], int n){
    int leftMax = 0;
    int rightMax = 0;
    int ans = 0;

    int start = 0;
    int end = n-1;

    while(start <= end){
        if(arr[start] <= arr[end]){
            leftMax = max(leftMax, arr[start]);
            ans += leftMax - arr[start++];
        }
        else{
            rightMax = max(rightMax, arr[end]);
            ans += rightMax - arr[end--];
        }
    }
    return ans;
}

int main(){
    int arr[] = {3, 0, 0, 2, 0, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout<<"Using Brute Force-->T=O(N^2), S=O(N):     "<<waterTrapped_BruteForce(arr, n);
    cout<<endl;
    cout<<"Using Time Optimisation-->T=O(N), S=O(N): "<<waterTrapped_Optimal(arr, n);
    cout<<endl;
    cout<<"Using Time Optimisation-->T=O(N), S=O(1): "<<waterTrapped_MostOptimal(arr, n);
}