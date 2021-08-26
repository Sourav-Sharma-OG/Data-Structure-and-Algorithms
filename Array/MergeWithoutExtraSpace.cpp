/*
Given two sorted arrays arr1[] of size N and arr2[] of size M. Each array is sorted in non-decreasing order. Merge the two arrays into one sorted array in non-decreasing order without using any extra space.


Example 1:

Input:
N = 4, M = 5
arr1[] = {1, 3, 5, 7}
arr2[] = {0, 2, 6, 8, 9}
Output: 0 1 2 3 5 6 7 8 9
Explanation: Since you can't use any 
extra space, modify the given arrays
to form 
arr1[] = {0, 1, 2, 3}
arr2[] = {5, 6, 7, 8, 9}

Approach=>Simple solution: if(arr1[i] > arr2[j]), then simply swap the arr2[j] with the last element of the arr1 because if arr1[i] is greater than arr2[j] then it is obvious that last element of arr1 is also greater than arr2[j](because arrays are sorted)..Simultaneously decrease or increase the pointers..
*/

#include<bits/stdc++.h>
using namespace std;

void mergeInPlace(int arr1[], int arr2[], int n, int m){
    int i = 0;
    int j = 0;
    int t = n-1;

    while(i < n && j < m){
        if(arr1[i] > arr2[j]){
            swap(arr2[j++], arr1[t--]);
        }
        else{
            i++;
        }
    }

    sort(arr1, arr1 + n);
    sort(arr2, arr2 + m);
}

int main(){
    int arr1[] = {1, 3, 5, 7};
    int arr2[] = {0, 2, 6, 8, 9};

    int n = sizeof(arr1)/sizeof(arr1[0]);
    int m = sizeof(arr2)/sizeof(arr2[0]);

    mergeInPlace(arr1, arr2, n, m);

    for(auto i: arr1){
        cout<<i<<" ";
    }

    for(auto i: arr2){
        cout<<i<<" ";
    }

    return 0;
}