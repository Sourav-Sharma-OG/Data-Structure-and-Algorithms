#include<iostream>
using namespace std;

void maxHeapify(int arr[], int& n, int idx){
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
        maxHeapify(arr, n, largest);
    }
}

//We are the array size by reference because we need to change the array size after extracting the max element from the array..

int extractMax(int arr[], int* n){
    if(*n < 1){
        return -1;
    }

    int max = arr[0];
    arr[0] = arr[*n-1];
    *n = *n-1;
    maxHeapify(arr, *n, 0);

    return max;
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

    cout<<"Max Heap: ";
    printHeap(arr, n);

    cout<<"Max element: "<<extractMax(arr, &n)<<endl;

    cout<<"After extracting max, Heap: ";
    printHeap(arr, n);
    

    return 0;
}