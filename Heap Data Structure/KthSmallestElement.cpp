#include<bits/stdc++.h>
using namespace std;

int kthSmallest(int arr[], int n, int k){
    priority_queue<int, vector<int>>maxHeap;
    for(int i = 0; i<n; i++){
        if(maxHeap.size() < k){
            maxHeap.push(arr[i]);
        }
        else{
            if(arr[i] < maxHeap.top())
            {
                maxHeap.pop();
                maxHeap.push(arr[i]);
            }
        }
    }

    return maxHeap.top();
}

int main(){
    int arr[] = {7, 10 , 4, 20, 15};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<kthSmallest(arr, n, 4);
    return 0;
}