#include<bits/stdc++.h>
using namespace std;

void printTargetSumSubsets(vector<int>&arr, int target, int idx, string set, int sum){
    if(idx == arr.size()){
        if(sum == target){
            cout<<set<<endl;
        }
        return;
    }

    printTargetSumSubsets(arr, target, idx + 1, set + to_string(arr[idx]) + " ", sum + arr[idx]);
    printTargetSumSubsets(arr, target, idx + 1, set, sum);
}

int main(){
    vector<int>arr  = {10, 20, 30, 40, 50, 60, 70, 80};
    int target = 80;
    printTargetSumSubsets(arr, target, 0, "", 0);
    return 0;
}