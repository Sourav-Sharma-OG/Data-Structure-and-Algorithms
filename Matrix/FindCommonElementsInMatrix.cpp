/*
Given an m x n matrix, find all common elements present in all rows in O(mn) time and one traversal of matrix.
Example: 

Input:
mat[4][5] = {{1, 2, 1, 4, 8},
             {3, 7, 8, 5, 1},
             {8, 7, 7, 3, 1},
             {8, 1, 2, 7, 9},
            };

Output: 
1 8 or 8 1
8 and 1 are present in all rows.
*/

#include <bits/stdc++.h>
using namespace std;

void printCommonElements(vector<vector<int>>& mat, int r, int c){
    unordered_map<int, int>mp;
    for(int i = 0; i<c; i++){
        mp[mat[0][i]] = 1;
    }

    for(int i = 1; i<r; i++){
        for(int j = 0; j<c; j++){
            if(mp[mat[i][j]] == i){
                mp[mat[i][j]]++;

                if(i == r-1 and mp[mat[i][j]] == r){
                    cout<<mat[i][j]<<" ";
                }
            }
        }
    }
}

int main()
{
    vector<vector<int>> mat = {
        {1, 2, 1, 4, 8},
        {3, 7, 8, 5, 1},
        {8, 7, 7, 3, 1},
        {8, 1, 2, 7, 9},
    };

    printCommonElements(mat, mat.size(), mat[0].size());
    return 0;
}