/*
Given a 2D grid of n*m of characters and a word, find all occurrences of given word in grid. A word can be matched in all 8 directions at any point. Word is said be found in a direction if all characters match in this direction (not in zig-zag form). The 8 directions are, horizontally left, horizontally right, vertically up, vertically down and 4 diagonal directions.
 

Example 1:

Input: grid = {{a,b,c},{d,r,f},{g,h,i}},
word = "abc"
Output: {{0,0}}
Expalnation: From (0,0) one can find "abc"
in horizontally right direction.
*/

#include<bits/stdc++.h>
using namespace std;

void helper(vector<vector<char>>grid, string word, int row, int col, int idx, int dir, vector<int>&temp){
    if(row < 0 || col < 0 || row >= grid.size() || col >= grid[0].size() || grid[row][col] != word[idx]){
        temp.clear();
        return;
    }
    
    temp.push_back(row);
    temp.push_back(col);
    
    char ch = grid[row][col];
    grid[row][col] = '0';
    idx++;
    
    if(idx == word.size()){
        while(temp.size() > 2){
            temp.pop_back();
        }
        return;
    }
    
    switch(dir){
        case 1 : helper(grid, word, row - 1, col - 1, idx, 1, temp);
        break;
        
        case 2 : helper(grid, word, row - 1, col, idx, 2, temp);
        break;
        
        case 3 : helper(grid, word, row - 1, col + 1, idx, 3, temp);
        break;
        
        case 4 : helper(grid, word, row, col + 1, idx, 4, temp);
        break;
        
        case 5 : helper(grid, word, row + 1, col + 1, idx, 5, temp);
        break;
        
        case 6 : helper(grid, word, row + 1, col, idx, 6, temp);
        break;
        
        case 7 : helper(grid, word, row + 1, col - 1, idx, 7, temp);
        break;
        
        case 8 : helper(grid, word, row, col - 1, idx, 8, temp);
        break;
    }
    grid[row][col] = ch;
}

vector<vector<int>>searchWord(vector<vector<char>>grid, string word){
    // Code here
    vector<vector<int>>ans;
    for(int i = 0; i < grid.size(); i++){
        for(int j = 0; j < grid[0].size(); j++){
            vector<int>temp;
            helper(grid, word, i, j, 0, 1, temp);
            if(temp.size() > 0){
                ans.push_back(temp);
            }
            
            helper(grid, word, i, j, 0, 2, temp);
            if(temp.size() > 0){
                ans.push_back(temp);
            }
            
            helper(grid, word, i, j, 0, 3, temp);
            if(temp.size() > 0){
                ans.push_back(temp);
            }
            
            helper(grid, word, i, j, 0, 4, temp);
            if(temp.size() > 0){
                ans.push_back(temp);
            }
            
            helper(grid, word, i, j, 0, 5, temp);
            if(temp.size() > 0){
                ans.push_back(temp);
            }
            
            helper(grid, word, i, j, 0, 6, temp);
            if(temp.size() > 0){
                ans.push_back(temp);
            }
            
            helper(grid, word, i, j, 0, 7, temp);
            if(temp.size() > 0){
                ans.push_back(temp);
            }
            
            helper(grid, word, i, j, 0, 8, temp);
            if(temp.size() > 0){
                ans.push_back(temp);
            }
        }
    }
    
    return ans;
}

int main(){
    vector<vector<char>>grid = {
        {'a', 'b', 'a', 'e', 'b', 'e', 'e', 'e', 'c', 'c'},
        {'a', 'b', 'e', 'c', 'b', 'd', 'e', 'c', 'a', 'd'},
        {'e', 'c', 'c', 'c', 'c', 'a', 'd', 'a', 'c', 'b'},
        {'e', 'e', 'a', 'd', 'd', 'd', 'c', 'b', 'b', 'b'},
        {'b', 'd', 'b', 'a', 'c', 'a', 'b', 'b', 'd', 'd'},
        {'c', 'c', 'c', 'd', 'a', 'e', 'a', 'c', 'e', 'b'}
    };

    string word = "bed";
    vector<vector<int>>ans = searchWord(grid, word);
    
    if(ans.size() == 0){
        cout<<"-1"<<endl;
    }
    else{
        for(auto i : grid){
            for(auto j : i){
                cout<<j<<" ";
            }
            cout<<endl;
        }
    }
}
