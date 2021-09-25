/*
Given an n x n matrix mat[n][n] of integers, find the maximum value of mat(c, d) – mat(a, b) over all choices of indexes such that both c > a and d > b.
Example: 

Input:
mat[N][N] = {{ 1, 2, -1, -4, -20 },
             { -8, -3, 4, 2, 1 }, 
             { 3, 8, 6, 1, 3 },
             { -4, -1, 1, 7, -6 },
             { 0, -4, 10, -5, 1 }};
Output: 18
The maximum value is 18 as mat[4][2] 
- mat[1][0] = 18 has maximum difference. 
*/

#include <bits/stdc++.h>
using namespace std;

int maxValueOfPair(vector<vector<int>>& mat){
    int row = mat.size();
    int col = mat[0].size();

    int ans = INT_MIN;

    for(int a = 0; a<row-1; a++){
        for(int b = 0; b<col-1; b++){
            for(int c = a + 1; c<row; c++){
                for(int d = b + 1; d<col; d++){
                    int tempAns = mat[c][d] - mat[a][b];
                    ans = max(tempAns, ans);
                }
            }
        }
    }
    return ans;
}

int maxValuePair(vector<vector<int>>& mat){
    int n = mat.size();
    int maxValue = INT_MIN;

    vector<vector<int>>maxArr(n, vector<int>(n, 0));
    maxArr[n-1][n-1] = mat[n-1][n-1];

    int maxV = mat[n-1][n-1];

    //Perprocessing last row.
    for(int j = n-2; j>=0; j--){
        if(mat[n-1][j] > maxV)
            maxV = mat[n-1][j];
        maxArr[n-1][j] = maxV;
    }

    maxV = mat[n-1][n-1];
    //Preprocessing last Column.
    for(int i = n-2; i>=0; i--){
        if(mat[i][n-1] > maxV)
            maxV = mat[i][n-1];
        maxArr[i][n-1] = maxV;
    }

    for(int i = n-2; i>=0; i--){
        for(int j = n-2; j>=0; j--){
            if(maxArr[i+1][j+1] - mat[i][j] > maxValue)
                maxValue = maxArr[i+1][j+1] - mat[i][j];

            maxArr[i][j] = max(mat[i][j], max(maxArr[i+1][j], maxArr[i][j+1]));
        }
    }
    return maxValue;
}

int main()
{
    vector<vector<int>> mat = {{1, 2, -1, -4, -20},
                               {-8, -3, 4, 2, 1},
                               {3, 8, 6, 1, 3},
                               {-4, -1, 1, 7, -6},
                               {0, -4, 10, -5, 1}};
    cout<<maxValueOfPair(mat);
    cout<<endl;
    cout<<maxValuePair(mat);
    return 0;
}