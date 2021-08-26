/*
Given an array of positive and negative numbers, arrange them in an alternate fashion such that every positive number is followed by negative and vice-versa. 
Number of positive and negative numbers need not be equal. If there are more positive numbers they appear at the end of the array. If there are more negative numbers, they too appear in the end of the array.

<-----Here we are not maintaining the appearance of +ve and -ve numbers as given in the example.--->

Examples : 

Input:  arr[] = {1, 2, 3, -4, -1, 4}
Output: arr[] = {-4, 1, -1, 2, 3, 4}

Input:  arr[] = {-5, -2, 5, 2, 4, 7, 1, 8, 0, -8}
output: arr[] = {-5, 5, -2, 2, -8, 4, 7, 1, 8, 0}
*/

#include<bits/stdc++.h>
using namespace std;

void rearrangeArray(int arr[], int n){
    int i = 0;
    int pos = n-1;
    int neg = n-1;

    while(i < pos && i < neg){
        if(i % 2 == 0){
            if(arr[i] < 0){
                i++;
                continue;
            }
            else{
                while(arr[neg] > 0){
                    neg--;
                }
                if(neg <= i){
                    return;
                }
                else{
                    swap(arr[neg], arr[i++]);
                }
            }
        }

        else {
            if(arr[i] > 0){
                i++;
                continue;
            }
            else{
                while(arr[pos] < 0){
                    pos--;
                }
                if(pos <= i){
                    return;
                }
                else{
                    swap(arr[pos], arr[i++]);
                }
            }
        }
    }
}

int main(){
    int arr[] = {-5, -2, -5, 2, -4, -7, 1, -8, 0, -8};
    int n = sizeof(arr)/sizeof(arr[0]);

    rearrangeArray(arr, n);
    for(auto i : arr){
        cout<<i<<" ";
    }
    return 0;
}