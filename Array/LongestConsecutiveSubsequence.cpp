/*
Given an array of positive integers. Find the length of the longest sub-sequence such that elements in the subsequence are consecutive integers, the consecutive numbers can be in any order.
Example 1:
Input:
N = 7
a[] = {2,6,1,9,4,5,3}
Output:
6
Explanation:
The consecutive numbers here are 1, 2, 3, 4, 5, 6. These 6 numbers form the longest consecutive subsquence.
*/

#include<bits/stdc++.h>
using namespace std;

int length_bruteForce(int arr[], int n){
    sort(arr, arr+n);
    int len = 1;
    int ans = 0;

    for(int i = 0; i<n; i++){
        if(arr[i] == arr[i+1]){
            continue;
        }

        if(arr[i] == arr[i+1] - 1){
            len++;
        }
        else{
            len = 1;
        }
        ans = max(len, ans);
    }
    return ans;
}

int length_optimal(int arr[], int n){
    unordered_set<int>st;
    for(int i = 0; i<n; i++)
        st.insert(arr[i]);

    int ans = 0;
    for(int i = 0; i<n; i++){
        //If arr[i] is the first element of the sub sequence i.e arr[i] - 1 is not present in the set.
        if(st.find(arr[i] - 1) == st.end()){
            int j = arr[i];
            //Check for the cons elemnts.-->Give it a dry run you will understand the logic.
            while(st.find(j) != st.end()){
                j++;
            }

            ans = max(ans, j - arr[i]);
        }
    }
    return ans;
}

int main(){
    int arr[] = {2, 6, 1, 9, 4, 5, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout<<length_bruteForce(arr, n);
    cout<<endl;
    cout<<length_optimal(arr, n);

    return 0;
}