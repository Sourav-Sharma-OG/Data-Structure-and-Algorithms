/*
Given an array of integers arr[] of size N and a number K, the task is to find the Kth most occurring element in this array.
Note: If there are more than one numbers in the array with the same frequency, then both are considered to be at the same level of occurrence. Therefore print both the numbers. 

Examples: 

Input: arr[] = {1, 2, 2, 2, 4, 4, 4, 5, 5, 5, 5, 5, 7, 7, 8, 8, 8, 8}, K = 1 
Output: 5 
Explanation: 
The occurrence of the elements are as follows: 
1 – 1 
2 – 3 
4 – 3 
5 – 5 
7 – 2 
8 – 4 
Clearly, 5 is the most occurring element in the array. 

Input: arr[] = {1, 2, 2, 2, 4, 4, 4, 4, 5, 5, 5, 5, 5, 7, 7, 8, 8, 8, 8}, K = 3 
Output: 2 4

*/

#include<bits/stdc++.h>
using namespace std;

void kthMostFrequent(vector<int>arr, int k){
    map<int, int>mp1;
    map<int, vector<int>>mp2;
    
    for(int i = 0; i<arr.size(); i++){
        mp1[arr[i]]++;
    }
    
    
    for(auto it = mp1.begin(); it!= mp1.end(); it++){
        mp2[it->second].push_back(it->first);
    }
    
    int tempK = 1;
    for(auto it = mp2.begin(); it != mp2.end(); it++){
        if(tempK == k){
            for(int i = 0; i<it->second.size(); i++){
                cout<<it->second[i]<<" ";
            }
            return;
        }
        tempK++;
    }
}


int main(){
    vector<int>arr = {1,2,2,2,4,4,4,5,5,5,5,5,7,7,8,8,8,8};
    int k = 3;
    
    kthMostFrequent(arr, k);
    
    return 0;
}