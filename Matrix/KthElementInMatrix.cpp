/*
Given a N x N matrix, where every row and column is sorted in non-decreasing order. Find the kth smallest element in the matrix.

Example 1:
Input:
N = 4
mat[][] =     {{16, 28, 60, 64},
                   {22, 41, 63, 91},
                   {27, 50, 87, 93},
                   {36, 78, 87, 94 }}
K = 3
Output: 27
Explanation: 27 is the 3rd smallest element.
*/

#include <bits/stdc++.h>
using namespace std;

int kthSmallest(vector<vector<int>>& mat, int n, int k){
    priority_queue<int>maxHeap;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            if(maxHeap.size() == k){
                if(mat[i][j] < maxHeap.top()){
                    maxHeap.pop();
                    maxHeap.push(mat[i][j]);
                }
            }
            else{
                maxHeap.push(mat[i][j]);
            }
        }
    }

    return maxHeap.top();
}

int main()
{
    vector<vector<int>> mat = {{16, 28, 60, 64},
                               {22, 41, 63, 91},
                               {27, 50, 87, 93},
                               {36, 78, 87, 94}};

    int k = 3;
    cout<<kthSmallest(mat, mat.size(), k);
    return 0;
}