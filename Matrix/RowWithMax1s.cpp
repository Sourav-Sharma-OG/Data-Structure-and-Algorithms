/*
Given a boolean 2D array of n x m dimensions where each row is sorted. Find the 0-based index of the first row that has the maximum number of 1's.

Example 1:

Input: 
N = 4 , M = 4
Arr[][] = {{0, 1, 1, 1},
           {0, 0, 1, 1},
           {1, 1, 1, 1},
           {0, 0, 0, 0}}
Output: 2
Explanation: Row 2 contains 4 1's (0-based
indexing).
*/

#include<bits/stdc++.h>
using namespace std;

int rowWithMax1s(vector<vector<int>>arr){
    int r = arr.size();
    int c = arr[0].size();

    int i = 0;
    int j = c - 1;

    int max1sRow = -1;
    while((i < r && j >= 0)){
        if(arr[i][j] == 1){
            max1sRow = i;
            j--;
        }
        else{
            i++;
        }
    }
    return max1sRow;
}

int main(){
    vector<vector<int>> arr = {{0, 1, 1, 1},
                              {0, 0, 1, 1},
                              {1, 1, 1, 1},
                              {0, 0, 0, 0}};
    cout<<rowWithMax1s(arr);
    return 0;
}