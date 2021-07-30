#include<bits/stdc++.h>
using namespace std;

void maxHeapify(int arr[], int n, int idx){
    int left = idx * 2 + 1;
    int right = idx * 2 + 2;
    int largest = idx;

    if(left < n and  arr[left] > arr[idx]){
        largest = left;
    }

    if(right < n and arr[right] > arr[largest]){
        largest = right;
    }

    if(largest != idx){
        swap(arr[idx], arr[largest]);
        maxHeapify(arr, n, largest);
    }
}

void decreaseKey(int arr[], int n, int idx, int value){
    if(value > arr[idx]){
        cout<<"Wrong operation...";
        return;
    }
    arr[idx] = value;
    maxHeapify(arr, n, idx);
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

    decreaseKey(arr, n, 1, 0);
    cout<<endl;

    printHeap(arr, n);
    return 0;
}