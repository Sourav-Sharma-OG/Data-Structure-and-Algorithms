#include<bits/stdc++.h>
using namespace std;

void insert(int arr[], int* n, int val){
    *n = *n + 1;
    arr[*n - 1] = val;
    int idx = *n - 1;
    while(idx > 0 and arr[((idx - 1) / 2)] < arr[idx]){
        swap(arr[(idx-1) / 2], arr[idx]);
        idx = (idx - 1) / 2;
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
    int arr[] = {20, 9, 8, 7, 6, 5, 4, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    printHeap(arr, n);

    insert(arr, &n, 12);

    printHeap(arr, n);

    cout<<endl;


    return 0;
}