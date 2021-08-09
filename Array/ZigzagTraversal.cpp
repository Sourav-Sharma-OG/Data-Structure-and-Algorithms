/*
Given a matrix of 2D array of n rows and m coloumns. Print this matrix in ZIG-ZAG fashion as shown in figure.
matrix_zag-zag

Example:

Input: 
1 2 3
4 5 6
7 8 9
Output: 
1 2 4 7 5 3 6 8 9
*/

#include<bits/stdc++.h>
using namespace std;

vector<int> zigzagTraversal(vector<vector<int>>arr){
    if(arr.size() == 0 || arr[0].size() == 0){
        vector<int>arr(0,0);
        return arr;
    }
    int m = arr.size();
    int n = arr[0].size();

    int i  = 0;
    int row = 0;
    int col = 0;
    bool up = true;

    vector<int>ans(m*n, 0);

    //Traversing the matrix
    while(row < m && col < n){
        //Bottomn - Up
        if(up){
            while (row > 0 && col < n-1)
            {
                ans[i++] = arr[row][col];
                row--;
                col++;
            }
            ans[i++] = arr[row][col];

            if(col == n-1){
                row++;
            }
            else{
                col++;
            } 
        }

        //Top - Down
        else{
            while(col > 0 && row < m-1){
                ans[i++] = arr[row][col];
                row++;
                col--;
            }
            ans[i++] = arr[row][col];

            if(row == m-1){
                col++;
            }
            else{
                row++;
            }
        }

        //Change the direction
        up = !up;
    }

    return ans;

}

int main(){
    vector<vector<int>> arr = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<int> ans = zigzagTraversal(arr);

    for(auto i: ans){
        cout<<i<<" ";
    }

    return 0;
}