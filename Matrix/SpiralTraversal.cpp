/*
Given a matrix of size r*c. Traverse the matrix in spiral form.

Example 1:

Input:
r = 4, c = 4
matrix[][] = {{1, 2, 3, 4},
           {5, 6, 7, 8},
           {9, 10, 11, 12},
           {13, 14, 15,16}}
Output: 
1 2 3 4 8 12 16 15 14 13 9 5 6 7 11 10
*/

#include<bits/stdc++.h>
using namespace std;

vector<int> spiralTraversal(vector<vector<int>>mat, int r, int c){
    vector<int>ans;
    int minRow = 0, minCol = 0;
    int maxRow = r - 1, maxCol = c -1;
    int total = r * c;
    int count = 0;

    while(count < total){
        //Top Wall
        for(int i = minCol; i <= maxCol && count < total; i++){
            ans.push_back(mat[minRow][i]);
            count++;
        }
        minRow++;

        //Right Wall
        for(int i = minRow; i <= maxRow && count < total; i++){
            ans.push_back(mat[i][maxCol]);
            count++;
        }
        maxCol--;

        //Bottom Wall
        for(int i = maxCol; i >= minCol && count < total; i--){
            ans.push_back(mat[maxRow][i]);
            count++;
        }
        maxRow--;

        //Left Wall
        for(int i = maxRow; i >= minRow && count < total; i--){
            ans.push_back(mat[i][minCol]);
            count++;
        }
        minCol++;
    }
    return ans;
}

void printMatrix(vector<vector<int>>matrix){
    for(int i = 0; i < matrix.size(); i++){
        for(int j = 0; j < matrix[0].size(); j++){
            cout<<matrix[i][j] <<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

int main(){
    int row, col;
    cin>>row>>col;

    vector<vector<int>> matrix(row, vector<int>(col, 0));

    for(int i = 0; i<row; i++){
        for(int j = 0; j<col; j++){
            int ele;
            cin>>ele;
            matrix[i][j] = ele;
        }
    }

    cout<<endl<<endl;
    printMatrix(matrix);

    cout<<endl;
    cout<<"Sprial Traversal: "<<endl;
    vector<int> spiral = spiralTraversal(matrix, row, col);
    for(auto it: spiral){
        cout<<it<<" ";
    }
    cout<<endl;
}