/*
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:
-->Integers in each row are sorted from left to right.
-->The first integer of each row is greater than the last integer of the previous row.
Example 1:
Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
Output: true
*/

#include<bits/stdc++.h>
using namespace std;

bool searchMatrix(vector<vector<int>>arr, int r, int c, int target){
    int i = 0;
    int j = c - 1;

    while(i < r && c >= 0){
        if(arr[i][j] == target){
            return true;
        }
        else if(arr[i][j] > target){
            j--;
        }
        else if(arr[i][j] < target){
            i++;
        }
    }
    return false;
}

bool searchMatrixOptimised(vector<vector<int>>arr, int r, int c, int target){
    int low = 0;
    int high = r * c - 1;

    while(low <= high){
        int mid = (low + high) / 2;
        int midVal = arr[mid / c][mid % c];

        if(midVal == target){
            return true;
        }
        else if(midVal > target){
            high = mid - 1;
        }
        else if(midVal < target){
            low = mid + 1;
        }
    }
    return false;
}

int main(){
    int row, col;
    cin>>row>>col;

    vector<vector<int>>arr(row, vector<int>(col, 0));
    for(int i = 0; i<row; i++){
        for(int j = 0; j<col; j++){
            int ele;
            cin>>ele;
            arr[i][j] = ele;
        }
    }
    int target;
    cin>>target;
    cout<<"\n\nUsing Two Pointer: ";
    cout<<searchMatrix(arr, row, col, target);
    cout<<"\n\nUsing Binary Search: ";
    cout<<searchMatrixOptimised(arr, row, col, target);

    return 0;
}