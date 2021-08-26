#include <bits/stdc++.h>
using namespace std;

void printSorted(vector<vector<int>>mat){
    int r = mat.size();
    int c = mat[0].size();

    vector<vector<int>>vis(r, vector<int>(r, 0));
    queue<pair<int, pair<int, int>>>q;

    vis[0][0] = 1;
    q.push({mat[0][0], {0, 0}});
    while(!q.empty()){
        int curr = q.front().first;
        int i = q.front().second.first;
        int j = q.front().second.first;
        q.pop();

        cout<<curr<<" ";

        if(i < r && j < c){
            if(mat[i+1][j] < mat[i][j+1] && vis[i+1][j] == 0){
                vis[i+1][j] = 1;
                q.push({mat[i+1][j], {i+1, j}});
                vis[i][j+1] = 1;
                q.push({mat[i][j+1], {i, j+1}});
            }
            else if(mat[i][j+1] < mat[i+1][j] && vis[i][j+1] == 0){
                vis[i][j+1] = 1;
                q.push({mat[i][j+1], {i, j+1}});
                vis[i+1][j] = 1;
                q.push({mat[i+1][j], {i+1, j}});
            }
        }
    }
}

int main()
{
    vector<vector<int>> mat = {
        {10, 20, 30, 40},
        {15, 25, 35, 45},
        {27, 29, 37, 48},
        {32, 33, 39, 50},
    };

    printSorted(mat);
    return 0;
}