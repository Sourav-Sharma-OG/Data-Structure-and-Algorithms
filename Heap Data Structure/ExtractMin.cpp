#include<bits/stdc++.h>
using namespace std;

void MIN_heapify(int arr[], int idx, int &n){
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

int extractMin(int arr[], int* n){
    if(*n < 1){
        return -1;
    }

    int min = arr[0];
    arr[0] = arr[*n-1];
    *n = *n - 1;
    MIN_heapify(arr, 0, *n);

    return min;    
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

    cout<<"Min Heap: ";
    printHeap(arr, n);

    cout<<"\nMin element: "<<extractMin(arr, &n)<<endl;

    cout<<"After extracting min element, Heap: ";
    printHeap(arr, n);

    return 0;
}