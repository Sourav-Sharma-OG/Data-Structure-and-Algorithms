#include<iostream>
using namespace std;

void displayArray(int arr[], int n, int idx){
    if(idx == n){
        return;
    }
    cout<<arr[idx]<<" ";
    displayArray(arr, n, idx+1);
}

void displayReverse(int arr[], int n, int idx){
    if(idx == n){
        return ;
    }

    displayReverse(arr, n, idx + 1);
    cout<<arr[idx]<<" ";
}

int main(){
    int arr[] = {2,3,45,5,6,7,8};
    int n = sizeof(arr)/sizeof(arr[0]);
    displayArray(arr, n, 0);

    cout<<"\nArray in reverse order is: ";
    displayReverse(arr, n, 0);
}