#include<bits/stdc++.h>
using namespace std;

int getMedian(int arr[], int n){
    if(n % 2 == 0){
        return (arr[n/2 - 1] + arr[n/2]) / 2;
    }
    return arr[n/2];
}

int median(int arr1[], int arr2[], int n){
    if(n <= 0){
        return -1;
    }

    if(n == 1){
        return (arr1[0] + arr2[0]) / 2;
    }

    if(n == 2){
        return (max(arr1[0], arr2[0]) + min(arr1[1], arr2[1])) / 2;
    }

    int m1 = getMedian(arr1, n);
    int m2 = getMedian(arr2, n);

    if(m1 == m2){
        return m1;
    }

    if(m2 > m1){
        if(n % 2 == 0){
            return median(arr1 + n / 2 - 1, arr2, n - (n / 2) + 1);
        }
        else{
            return median(arr1 + n / 2, arr2, n - (n / 2));
        }
    }
    else{
        if(n % 2 == 0){
            return median(arr2 + n / 2 - 1, arr1, n - n / 2 + 1);
        }
        else{
            return median(arr2 + n / 2, arr1, n - n / 2);
        }
    }
}

int main(){
    int arr1[] = {1, 12, 15, 26, 38};
    int arr2[] = {2, 13, 17, 30, 45};
    int n = sizeof(arr1) / sizeof(arr1[0]);

    cout<<median(arr1, arr2, n);
    return 0;
}