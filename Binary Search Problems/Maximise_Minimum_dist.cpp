#include<iostream>
#include<algorithm>
using namespace std;

bool isFeasible(int mid, int arr[], int n, int k){
    int pos = arr[0], elements = 1;

    for(int i = 1; i<n; i++){
        if(arr[i] - pos >=  mid ){
            pos = arr[i];
            elements++;
            if(elements == k){
                return true;
            }
        }
    }
    return false;
}

int Max_minDist(int arr[], int n, int k){
    sort(arr, arr+n);

    int left = 1, right = arr[n-1];
    int result = -1;

    while(left < right){
        int mid = (left + right) / 2;

        if(isFeasible(mid, arr, n, k)){
            result = max(result, mid);
            left = mid+1;
        }
        else{
            right = mid;
        }
    }

    return result;
}

int main(){
    int arr[] = {11,2,7,5,1,12};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout<<"Largest minimum distance: "<<Max_minDist(arr, n, 3);
    return 0;
}