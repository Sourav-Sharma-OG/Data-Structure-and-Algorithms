#include<bits/stdc++.h>
using namespace std;

int minNoOfJumps(vector<int> arr){
    int n = arr.size();
    if(n <= 1){
        return 0;
    }

    if(arr[0] == 0){
        return -1;
    }

    int maxReach = arr[0];
    int steps = arr[0];
    int jumps = 1;

    for(int i = 1; i<n; i++){
        if(i == n-1){
            return jumps;
        }

        maxReach = max(maxReach, arr[i] + i);
        steps--;

        if(steps == 0){
            jumps++;
            if(i >= maxReach){
                return -1;
            }
            steps = maxReach - i;
        }
    }

    return -1;
}

int main(){
    vector<int> arr = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9};
    cout<<minNoOfJumps(arr);

    return 0;
}