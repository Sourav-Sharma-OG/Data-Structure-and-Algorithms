#include<bits/stdc++.h>
using namespace std;

void maxHeapify(int arr[], int n, int idx){
    int left = idx * 2 + 1;
    int right = idx * 2 + 2;
    int largest = idx;

    if(left < n and arr[left] > arr[largest]){
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

void buildHeap(int arr[], int n){
    for(int i = n/2 -1; i>= 0; i--){
        maxHeapify(arr, n, i);
    }
}

void heapSort(int arr[], int n){
    buildHeap(arr, n);

    for(int i = n-1; i>=1; i--){
        swap(arr[i], arr[0]);
        maxHeapify(arr, i, 0);
    }
}

void printArray(int arr[], int n){
    for(int i = 0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int arr[] = {23, 54, 34, 2, 13, 5, 53, 6, 51, 90, 9};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"Original array: ";
    printArray(arr, n);
    cout<<"Sorted array after applying heap sort: "<<endl;
    heapSort(arr, n);
    printArray(arr, n);

    return 0;
}