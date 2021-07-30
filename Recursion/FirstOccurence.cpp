#include <iostream>
#include<vector>
using namespace std;

int firstOccurence(int arr[], int n, int k, int idx)
{
    if (idx == n)
    {
        return -1;
    }

    if (arr[idx] == k)
    {
        return idx;
    }
    return firstOccurence(arr, n, k, idx + 1);
}

int lastOccurence(int arr[], int n, int k, int idx)
{
    if (idx == n)
    {
        return -1;
    }

    int ans = lastOccurence(arr, n, k, idx + 1);
    if(ans == -1){
        if(arr[idx] == k){
            return idx;
        }
        else{
            return -1;
        }
    }
    return ans;
}

vector<int> allIndices(int arr[], int n, int k, int idx){
    static vector<int>ans;
    if(idx == n){
        return ans;
    }

    if(arr[idx] == k){
        ans.push_back(idx);
    }
    return allIndices(arr, n, k, idx + 1);
}

int main()
{
    int arr[] = {2, 3, 4, 5, 6, 73, 3, 2, 6, 7, 3, 6, 7, 8, 8, 3, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int ans = firstOccurence(arr, n, 600, 0);
    int ans1 = lastOccurence(arr, n, 6, 0);
    cout <<"ans: "<< ans << " ans1: " << ans1;

    cout<<endl;

    vector<int>ans2 = allIndices(arr, n, 2, 0);
    for(int i = 0; i<ans2.size(); i++){
        cout<<ans2[i]<<" ";
    }
    return 0;
}