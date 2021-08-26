/*
There are 2 sorted arrays A and B of size n each. Write an algorithm to find the median of the array obtained after merging the above 2 arrays(i.e. array of length 2n). The complexity should be O(log(n)). 
-->O(N) solution
*/

#include<bits/stdc++.h>
using namespace std;

int median(int arr1[], int arr2[], int n){
    int check = 0;
    int i = 0, j = 0;
    int first, second;
    while(check <= n-1){
        if(arr1[i] < arr2[j]){
            i++;
            check++;
            if(check == n-2){
                first = arr1[i];
            }
            if(check == n-1){
                second = arr1[i];
            }
        }
        else if(arr1[i] > arr2[j]){
            j++;
            check++;
            if(check == n-2){
                first = arr2[j];
            }
            if(check == n-1){
                second = arr2[j];
            }
        }
    }

    return (first + second) / 2;
}

int main(){
    int arr1[] = {1, 12, 15, 26, 38};
    int arr2[] = {2, 13, 17, 30, 45};
    int n = sizeof(arr1) / sizeof(arr1[0]);

    cout<<median(arr1, arr2, n);
    return 0;
}
