/*
1. You are given a number n, representing the number of rows.
2. You are given a number m, representing the number of columns.
3. You are given n*m numbers, representing elements of 2d array a. The numbers can be 1 or 0 only.
4. You are standing in the top-left corner and have to reach the bottom-right corner. 
Only four moves are allowed 't' (1-step up), 'l' (1-step left), 'd' (1-step down) 'r' (1-step right). You can only move to cells which have 0 value in them. You can't move out of the boundaries or in the cells which have value 1 in them (1 means obstacle)
5. Complete the body of floodfill function - without changing signature - to print all paths that can be used to move from top-left to bottom-right.

Note1 -> Please check the sample input and output for details
Note2 -> If all four moves are available make moves in the order 't', 'l', 'd' and 'r'
Input Format
A number n
A number m
e11
e12..
e21
e22..
.. n * m number of elements
Output Format
trrrdlt
tlldrt
.. and so on
*/

#include<bits/stdc++.h>
using namespace std;

void floodFill(vector<vector<int>>&maze, int row, int col, string output, vector<vector<bool>>& vis){
    if(row < 0 || col < 0 || row == maze.size() || col == maze[0].size() ||
        maze[row][col] == 1 || vis[row][col] == true){
        return;
    }

    if(row == maze.size() - 1  and col == maze[0].size() - 1){
        cout<<output<<" ";
        return;
    }

    vis[row][col] = true;
    floodFill(maze, row - 1, col, output + "t", vis);
    floodFill(maze, row, col - 1, output + "l", vis);
    floodFill(maze, row + 1, col, output + "d", vis);
    floodFill(maze, row, col + 1, output + "r", vis);
    vis[row][col] = false;
}

void printPaths(vector<vector<int>>&maze){
    vector<vector<bool>>vis(maze.size(), vector<bool>(maze[0].size(), false));
    floodFill(maze, 0, 0, "", vis);
}

int main(){
    int row, col;
    cin>>row>>col;

    vector<vector<int>>maze(row, vector<int>(col, 0));
    for(int i = 0; i<row; i++){
        for(int j = 0; j<col; j++){
            int ele;
            cin>>ele;
            maze[i][j] = ele;
        }
    }

    printPaths(maze);
    return 0;
}