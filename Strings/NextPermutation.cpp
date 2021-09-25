/*
Implement the next permutation, which rearranges the list of numbers into Lexicographically next greater permutation of list of numbers. If such arrangement is not possible, it must be rearranged to the lowest possible order i.e. sorted in an ascending order. You are given an list of numbers arr[ ] of size N.

Example 1:

Input: N = 6
arr = {1, 2, 3, 6, 5, 4}
Output: {1, 2, 4, 3, 5, 6}
Explaination: The next permutation of the 
given array is {1, 2, 4, 3, 5, 6}.
*/

#include<bits/stdc++.h>
using namespace std;

vector<int> nextPermutation(vector<int> &arr){
    int idx1 = -1;
    int idx2;

    for(int i = arr.size() - 1; i > 0; i--){
        if(arr[i-1] < arr[i]){
            idx1 = i-1;
            break;
        }
    }

    if(idx1 == -1){
        reverse(arr.begin(), arr.end());
        return arr;
    }

    for(int i = arr.size() - 1; i > idx1 ; i--){
        if(arr[i] > arr[idx1]){
            idx2 = i;
            break;
        }
    }

    swap(arr[idx1], arr[idx2]);
    reverse(arr.begin() + idx1 + 1, arr.end());
    return arr;
}

int main(){
    vector<int>arr = {1, 2, 4, 3, 5, 6};
    vector<int>ans = nextPermutation(arr);

    for(auto it : ans){
        cout<<it<<" ";
    }
    return 0;
}