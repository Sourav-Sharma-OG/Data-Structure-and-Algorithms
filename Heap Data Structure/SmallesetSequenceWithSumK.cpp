#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, k;
    cin>>n>>k;

    vector<int>vec(n);

    for(int i = 0; i<n; i++){
        cin>>vec[i];
    }

    priority_queue<int, vector<int>>maxHeap;

    for(int i = 0; i<n; i++){
        maxHeap.push(vec[i]);
    }

    int sum = 0;
    int count = 0;

    while(!maxHeap.empty()){
        sum += maxHeap.top();
        maxHeap.pop();
        count++;
        if(sum >= k){
            break;
        }
    }

    if(sum < k){
        cout<<" - 1";
    }else{
        cout<<count<<endl;
    }

    return 0;
}