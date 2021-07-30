#include<iostream>
using namespace std;

int maxOfArray(int arr[], int n, int idx){
    if(idx == n - 1){
        return arr[idx];
    }
    int restOfArray = maxOfArray(arr, n, idx + 1);
    return arr[idx] > restOfArray ? arr[idx] : restOfArray;
}

int main(){
    int arr[] = {2,34,54,65,7,6,76,354,2};
    int n = sizeof(arr)/sizeof(arr[0]);
    int ans = maxOfArray(arr, n, 0);
    cout<<ans;
    return 0;
}