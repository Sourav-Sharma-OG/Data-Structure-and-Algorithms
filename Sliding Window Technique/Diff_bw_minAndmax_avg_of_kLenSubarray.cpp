#include<bits/stdc++.h>
using namespace std;

float calDiffBwAvg(vector<int>arr, int k){
    float sum = 0;
    for(int i = 0; i<k; i++){
        sum += arr[i];
    }

    float minimum = sum;
    float maximum = sum;

    for(int i = k; i<arr.size(); i++){
        sum += arr[i] - arr[i-k];

        minimum = min(sum, minimum);
        maximum = max(sum, maximum);
    }

    minimum /= k;
    maximum /= k;
    return maximum - minimum;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, k;
        cin>>n>>k;
        vector<int>arr;
        for(int i = 0; i<n; i++){
            int element;
            cin>>element;
            arr.push_back(element);
        }

        float ans = calDiffBwAvg(arr, k);
        cout<<ans<<endl;
    }


    return 0;
}