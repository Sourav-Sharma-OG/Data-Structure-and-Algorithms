/*
Given two arrays: a1[0..n-1] of size n and a2[0..m-1] of size m. Task is to check whether a2[] is a subset of a1[] or not. Both the arrays can be sorted or unsorted. It may be assumed that elements in both array are distinct.
 

Example 1:

Input:
a1[] = {11, 1, 13, 21, 3, 7}
a2[] = {11, 3, 7, 1}
Output:
Yes
Explanation:
a2[] is a subset of a1[]
*/

#include<bits/stdc++.h>
using namespace std;

string isSubset(vector<int>a1, vector<int>a2){
    unordered_set<int>set;
    for(auto i : a1){
        set.insert(i);
    }
    for(auto i : a2){
        if(set.find(i) == set.end()){
            return "No";
        }
    }
    return "Yes";  
}

int main(){
    vector<int>a1 = {11, 1, 13, 21, 3, 7};
    vector<int>a2 = {11, 3, 7, 1};
    cout<<isSubset(a1, a2);

    return 0;
}