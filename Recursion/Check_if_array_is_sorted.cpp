/*
WAP to check whether an array is sorted or not.
*/

#include<iostream>
using namespace std;

bool isSorted(int arr[], int n){
    //Base Condition
    if(n == 1){
        //If there is only one element in the array, then array is already sorted.
        return true;
    }

    bool remArray = isSorted(arr+1, n-1);
    return (arr[0] < arr[1] && remArray);
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }

    if(isSorted(arr, n)){
        cout<<"Entered array is sorted.";
    }
    else{
        cout<<"Entered array is not sorted.";
    }
    return 0;
}