/*
Given an array of size n and a range [a, b]. The task is to partition the array around the range such that array is divided into three parts.
1) All elements smaller than a come first.
2) All elements in range a to b come next.
3) All elements greater than b appear in the end.
The individual elements of three sets can appear in any order. You are required to return the modified array.


Example 1:

Input: 
n = 5
A[] = {1, 2, 3, 3, 4}
[a, b] = [1, 2]
Output: 1
Explanation: One possible arrangement is:
{1, 2, 3, 3, 4}. If you return a valid
arrangement, output will be 1.
*/

#include<bits/stdc++.h>
using namespace std;

void rearrange(int arr[], int a, int b, int n){
    int start = 0;
    int end = n-1;

    int i = 0;
    while(i <= end){
        if(arr[i] < a){
            swap(arr[i++], arr[start++]);
        }
        else if(arr[i] > b){
            swap(arr[i], arr[end--]);
        }
        else{
            i++;
        }
    }
}

int main(){
    int arr[] = {12, 34, 8, 9, 3, 189, 3, 0, 32, 53, 88, 3423, 890, 55, 6};
    int n = sizeof(arr)/sizeof(arr[0]);
    int a = 32, b = 100;
    rearrange(arr, a, b, n);
    for(auto i : arr){
        cout<<i<<" ";
    }
    return 0;
}