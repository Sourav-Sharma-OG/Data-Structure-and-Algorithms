/*
Given an array of N integers, and an integer K, find the number of pairs of elements in the array whose sum is equal to K.
Example 1:
Input:
N = 4, K = 6
arr[] = {1, 5, 7, 1}
Output: 2
Explanation: 
arr[0] + arr[1] = 1 + 5 = 6 
and arr[1] + arr[3] = 5 + 1 = 6.
*/

#include<bits/stdc++.h>
using namespace std;

//Time Complexity: O(N^2)   ||   Space Complexity: 0(1)
int countPairsBruteForce(int arr[], int n, int k){
    int count = 0;
    for(int i = 0; i< n; i++){
        for(int j = i+1; j < n; j++){
            if(arr[i] + arr[j] == k){
                count++;
            }
        }
    }
    return count;
}

//Time Complexity = O(N)    ||   Space Complexity = 0(1)
int countPairsOptimal(int arr[], int n, int k){
    int count = 0;
    unordered_map<int, int> mp;

    for(int i = 0; i<n; i++){
        count += mp[k - arr[i]];
        mp[arr[i]]++;
    }

    return count;
}

int main(){
    int arr[] = {1, 5, 7, 1};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 6;

    cout<<countPairsBruteForce(arr, n, k);
    cout<<endl;
    cout<<countPairsOptimal(arr, n, k);

    return 0;
}