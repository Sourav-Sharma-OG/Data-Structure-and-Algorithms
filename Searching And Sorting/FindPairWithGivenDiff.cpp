/*
Given an array Arr[] of size L and a number N, you need to write a program to find if there exists a pair of elements in the array whose difference is N.

Example 1:

Input:
L = 6, N = 78
arr[] = {5, 20, 3, 2, 5, 80}
Output: 1
Explanation: (2, 80) have difference of 78.
Example 2:

Input:
L = 5, N = 45
arr[] = {90, 70, 20, 80, 50}
Output: -1
Explanation: There is no pair with difference of 45.
*/

#include <bits/stdc++.h>
using namespace std;

bool findPair(int arr[], int size, int n){
    sort(arr, arr+size);
    int i = 0, j = 1;

    while(i < size and j < size){
        if(i != j and arr[j] - arr[i] == n){
            return true;
        }
        else if(arr[j] - arr[i] > n){
            i++;
        }
        else{
            j++;
        }
    }
    return false;
}

int main()
{
    int n, no;
    cin >> n >> no;

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << findPair(arr, n, no);
    return 0;
}