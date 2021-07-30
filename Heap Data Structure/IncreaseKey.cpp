#include<bits/stdc++.h>
using namespace std;

void  increaseKey(int arr[], int n, int idx, int value){
    if(arr[idx] > value){
        cout<<"Wrong operation..";
        return;
    }

    arr[idx] = value;
    while(idx > 0 and arr[idx / 2 - 1] < arr[idx]){
        swap(arr[idx / 2 - 1], arr[idx]);
        idx = idx / 2 - 1;
    }
}

void printHeap(int arr[], int n){
    cout<<"Array representation of heap: "<<endl;
    for(int i = 0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int arr[] = { 50, 46, 20, 15, 12, 8, 6, 4, 2 ,1 };
    int n = sizeof(arr) / sizeof(arr[0]);

    printHeap(arr, n);

    increaseKey(arr, n, 2, 100);

    printHeap(arr, n);

    return 0;
}