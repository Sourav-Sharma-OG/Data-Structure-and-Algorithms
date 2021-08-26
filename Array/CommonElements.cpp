/*
Given three arrays sorted in increasing order. Find the elements that are common in all three arrays.
Note: can you take care of the duplicates without using any additional Data Structure?

Example 1:

Input:
n1 = 6; A = {1, 5, 10, 20, 40, 80}
n2 = 5; B = {6, 7, 20, 80, 100}
n3 = 8; C = {3, 4, 15, 20, 30, 70, 80, 120}
Output: 20 80
Explanation: 20 and 80 are the only
common elements in A, B and C.
*/

#include<bits/stdc++.h>
using namespace std;

vector<int>getCommon(int a[], int b[], int c[], int n1, int n2, int n3){
    int i = 0;
    int j = 0;
    int k = 0;
    int last = INT_MIN;
    vector<int>ans;

    while(i < n1 && j < n2 && k < n3){
        if(a[i] == b[j] && b[j] == c[k] && a[i] != last){
            ans.push_back(a[i]);
            last = a[i];
            i++; j++; k++;
        }

        else {
            if(min(a[i], min(b[j], c[k])) == a[i])  i++;
            else if(min(a[i], min(b[j], c[k])) == b[j])  j++;
            else if(min(a[i], min(b[j], c[k])) == c[k])  k++;
        }
    }

    return ans;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n1, n2, n3;
        cin>>n1>>n2>>n3;

        int a[n1];
        int b[n2];
        int c[n3];

        for(int i = 0; i<n1; i++){
            cin>>a[i];
        }

        for(int i = 0; i<n2; i++){
            cin>>b[i];
        }

        for(int i = 0; i<n3; i++){
            cin>>c[i];
        }

        vector<int> ans = getCommon(a, b, c, n1, n2, n3);
        for(auto i : ans){
            cout<<i<<" ";
        }
        cout<<endl;
    }
}