/*
A step array is an array of integers where each element has a difference of at most k with its neighbor. Given a key x, we need to find the index value of x if multiple-element exist to return the first occurrence of the key.
Examples: 
 

Input : arr[] = {4, 5, 6, 7, 6}
           k = 1
           x = 6
Output : 2
The first index of 6 is 2.

Input : arr[] = {20, 40, 50, 70, 70, 60}  
          k = 20
          x = 60
Output : 5
The index of 60 is 5
*/

#include<bits/stdc++.h>
using namespace std;

int searchIdx(int arr[], int k, int x, int n){
    if(n == 1){
        if(arr[0] == x){
            return 0;
        }
        else{
            return -1;
        }
    }

    int i = 0;
    while(i < n){
        if(arr[i] == x){
            return i;
        }

        i += max(1, (abs(arr[i] - x) / k));
    }
    return -1;
}

int main(){
    int arr[] = {4, 5, 6, 7, 6};
    int k = 1;
    int x = 6;
    int n = sizeof(arr) / sizeof(arr[0]);

    cout<<searchIdx(arr, k , x, n);
    return 0;
}