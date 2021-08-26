/*
Given an array arr[] of size N and an element k. The task is to find all elements in array that appear more than n/k times.

Example 1:

Input:
N = 8
arr[] = {3,1,2,2,1,2,3,3}
k = 4
Output: 2
Explanation: In the given array, 3 and
 2 are the only elements that appears 
more than n/k times.
*/

#include<bits/stdc++.h>
using namespace std;

int countOccurences(int arr[], int n, int k){
    unordered_map<int, int>mp;
    for(int i = 0; i<n; i++){
        mp[arr[i]]++;
    }

    int ans = 0;

    for(auto it = mp.begin(); it != mp.end(); it++){
        if(it->second > n / k){
            ans++;
        }
    }
    return ans;
}


int main(){
    int arr[] = {3, 1, 2, 2, 1, 2, 3, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 4;

    cout<<countOccurences(arr, n, k);

    return 0;
}