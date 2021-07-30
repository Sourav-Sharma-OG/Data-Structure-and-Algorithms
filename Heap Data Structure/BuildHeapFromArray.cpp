#include<bits/stdc++.h>
using namespace std;

void MAX_heapify(int arr[], int idx, int n){
    int left = idx * 2 + 1;
    int right = idx * 2 + 2;

    int largest = idx;

    if(left < n and arr[left] > arr[idx]){
        largest = left;
    }

    if(right < n and arr[right] > arr[largest]){
        largest = right;
    }

    if(largest != idx){
        swap(arr[idx], arr[largest]);
        MAX_heapify(arr, largest, n);
    }
}


void MIN_heapify(int arr[], int idx, int n){
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;
    int smallest = idx;

    if(left < n and arr[left] < arr[idx]){
        smallest = left;
    }

    if(right < n and arr[right] < arr[smallest]){
        smallest = right;
    }

    if(smallest != idx){
        swap(arr[idx], arr[smallest]);
        MIN_heapify(arr, smallest, n);
    }
}

void buildMaxHeap(int arr[], int n){
    int startIdx = (n / 2) - 1;

    for(int i = startIdx; i>= 0; i--){
        MAX_heapify(arr, i, n);
    }
}

void buildMinHeap(int arr[], int n){
    int startIdx = (n / 2) - 1;

    for(int i = startIdx; i>=0; i--){
        MIN_heapify(arr, i, n);
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
    int arr[] = { 1, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17 };
    int n = sizeof(arr) / sizeof(arr[0]);

    cout<<"Max Heap: ";

    buildMaxHeap(arr, n);
    printHeap(arr, n);

    cout<<endl<<"Min Heap: ";

    buildMinHeap(arr, n);
    printHeap(arr, n);

    return 0;
}