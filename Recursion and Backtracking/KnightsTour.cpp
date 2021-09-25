#include<bits/stdc++.h>
using namespace std;

void printBoard(vector<vector<int>>arr){
    for(int i = 0; i<arr.size(); i++){
        for(int j = 0; j<arr[0].size(); j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl<<endl;
}

void printNightTours(vector<vector<int>>board, int r, int c , int move){
    if(r < 0 || c < 0 || r >= board.size() || c >= board.size() || board[r][c] > 0){
        return;
    }
    else if(move == board.size() * board.size()){
        board[r][c] = move;
        printBoard(board);
        board[r][c] = 0;
        return;
    }

    board[r][c] = move;
    printNightTours(board, r-2, c+1, move+1);
    printNightTours(board, r-1, c+2, move+1);
    printNightTours(board, r+1, c+2, move+1);
    printNightTours(board, r+2, c+1, move+1);
    printNightTours(board, r+2, c-1, move+1);
    printNightTours(board, r+1, c-2, move+1);
    printNightTours(board, r-1, c-2, move+1);
    printNightTours(board, r-2, c-1, move+1);
    board[r][c] = 0;
}

int main(){
    int n = 5;
    int row = 2;
    int col = 2;
    vector<vector<int>>board(n, vector<int>(n, 0));
    printNightTours(board, row, col, 1);
    return 0;
}