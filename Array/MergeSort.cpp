/*
Given an array arr[], its starting position l and its ending position r. Sort the array using merge sort algorithm.
Example 1:

Input:
N = 5
arr[] = {4 1 3 9 7}
Output:
1 3 4 7 9
*/

#include<bits/stdc++.h>
using namespace std;

void merge(int arr[], int l, int m, int r){
    int n1 = m - l + 1;
    int n2 = r - m;

    int arr1[n1];
    int arr2[n2];

    for(int i = 0; i<n1; i++){
        arr1[i] = arr[l + i];
    }

    for(int j = 0; j<n2; j++){
        arr2[j] = arr[m + 1 + j];
    }

    int i = 0, j = 0, k = l;
    while(i < n1 && j < n2){
        if(arr1[i] < arr2[j]){
            arr[k++] = arr1[i++];
        }
        else{
            arr[k++] = arr2[j++];
        }
    }

    while(i < n1){
        arr[k++] = arr1[i++];
    }

    while(j < n2){
        arr[k++] = arr2[j++];
    }
}

void mergeSort(int arr[], int l, int r){
    if(l < r){
        int mid = (l + r) / 2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);
        merge(arr, l, mid, r);
    }
}

int main(){
    int arr[] = {4, 1, 3, 9, 7};
    int l = 0;
    int r = sizeof(arr)/sizeof(arr[0]) - 1;
    mergeSort(arr, l, r);

    for(auto i : arr){
        cout<<i<<" ";
    }
}