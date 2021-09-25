#include<bits/stdc++.h>
using namespace std;

bool isRightPlaceForQueen(vector<string>board, int row, int col){
    for(int i = row - 1, j = col; i >= 0; i--){
        if(board[i][j] == 'Q'){
            return false;
        }
    }

    for(int i = row - 1, j = col - 1; i >= 0 and j >= 0; i--, j--){
        if(board[i][j] == 'Q'){
            return false;
        }
    }

    for(int i = row - 1, j = col + 1; i >= 0 and j < board.size(); i--, j++){
        if(board[i][j] == 'Q'){
            return false;
        }
    }
    return true;
}

void NQueenHelper(vector<string>&board, int row, vector<vector<string>>&ans){
    if(row == board.size()){
        ans.push_back(board);
        return;
    }

    for(int col = 0; col <board.size(); col++){
        if(isRightPlaceForQueen(board, row, col)){
            board[row][col] = 'Q';
            NQueenHelper(board, row + 1, ans);
            board[row][col] = '.';
        }
    }
}

vector<vector<string>>NQueen(int n){
    if(n <= 0){
        return {{}};
    }

    vector<vector<string>>ans;
    vector<string>board(n, string(n, '.'));
    NQueenHelper(board, 0, ans);
    return ans;
}

int main(){
    int n = 4;
    vector<vector<string>>ans = NQueen(n);

    for(auto it : ans){
        cout<<"[ ";
        for(auto i : it){
            cout<<"["<<i<<"] ";
        }
        cout<<"]";
        cout<<endl;
    }
}