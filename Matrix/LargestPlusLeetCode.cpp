/*
You are given an integer n. You have an n x n binary grid grid with all values initially 1's except for some indices given in the array mines. The ith element of the array mines is defined as mines[i] = [xi, yi] where grid[xi][yi] == 0.
Return the order of the largest axis-aligned plus sign of 1's contained in grid. If there is none, return 0.
An axis-aligned plus sign of 1's of order k has some center grid[r][c] == 1 along with four arms of length k - 1 going up, down, left, and right, and made of 1's. Note that there could be 0's or 1's beyond the arms of the plus sign, only the relevant area of the plus sign is checked for 1's.

Example 1:
Input: n = 5, mines = [[4,2]]
Output: 2
Explanation: In the above grid, the largest plus sign can only be of order 2. One of them is shown.
Example 2:

Input: n = 1, mines = [[0,0]]
Output: 0
Explanation: There is no plus sign, so return 0.
*/

#include<bits/stdc++.h>
using namespace std;

 int callLeft(int row, int col, vector<vector<int>>grid){
        int left = 0;
        for(int i = col; i >= 0; i--){
            if(grid[row][i] == 0){
                break;
            }
            left++;
        }
        return left;
    }
    
    int callRight(int row, int col, vector<vector<int>>grid){
        int right = 0;
        for(int i = col; i < grid.size(); i++){
            if(grid[row][i] == 0){
                break;
            }
            right++;
        }
        return right;
    }
    
    int callTop(int row, int col, vector<vector<int>>grid){
        int top = 0;
        for(int i = row; i >= 0; i--){
            if(grid[i][col] == 0){
                break;
            }
            top++;
        }
        return top;
    }
    
    int callBottom(int row, int col, vector<vector<int>>grid){
        int bottom = 0;
        for(int i = row; i < grid.size(); i++){
            if(grid[i][col] == 0){
                break;
            }
            bottom++;
        }
        return bottom;
    }


int largestPlusBruteForce(int n, vector<vector<int>>mines){
    vector<vector<int>>grid(n, vector<int>(n, 1));
    int ans = 0;

    for(auto it : mines){
        int i = it[0];
        int j = it[1];
        grid[i][j] = 0;
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int left = callLeft(i, j, grid);
            int right = callRight(i, j, grid);
            int top = callTop(i, j, grid);
            int bottom = callBottom(i, j, grid);
            ans = max(ans, min(left, min(right, min(top, bottom))));
        }
    }
    return ans;
}

int largestPlusOptimal(int n, vector<vector<int>>mines){
    vector<vector<int>>grid(n, vector<int>(n, 1));
    vector<vector<int>>left(n, vector<int>(n, 1));
    vector<vector<int>>right(n, vector<int>(n, 1));
    vector<vector<int>>up(n, vector<int>(n, 1));
    vector<vector<int>>down(n, vector<int>(n, 1));
    for(auto it : mines){
        int i = it[0];
        int j = it[1];
        grid[i][j] = left[i][j] = right[i][j] = up[i][j] = down[i][j] = 0;
    }
    int ans = 0;
    
    for(int i = 0; i < n; i++){
        for(int j = 1; j < n; j++){
            left[i][j] = grid[i][j] > 0 ? left[i][j-1] + 1 : 0;
            down[j][i] = grid[j][i] > 0 ? down[j-1][i] + 1 : 0;
        }
        
            for(int j = n-2; j >= 0; j--){
            right[i][j] = grid[i][j] > 0 ? right[i][j+1] + 1 : 0;
            up[j][i] = grid[j][i] > 0 ? up[j+1][i] + 1 : 0;
        }
    }
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            ans = max(ans, min(left[i][j], min(right[i][j], min(up[i][j], down[i][j]))));
        }
    }
    return ans;
}

int main(){
    vector<vector<int>>mines = {{4, 2}};
    int n = 5;
    cout<<largestPlusBruteForce(n, mines);
    cout<<endl;
    cout<<largestPlusOptimal(n, mines);
    return 0;
}