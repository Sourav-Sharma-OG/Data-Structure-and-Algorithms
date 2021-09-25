/*
Given a 2-Dimensional character array and a string, we need to find the given string in 2-dimensional character array such that individual characters can be present left to right, right to left, top to down or down to top.
Examples: 
Input : a ={
            {D,D,D,G,D,D},
            {B,B,D,E,B,S},
            {B,S,K,E,B,K},
            {D,D,D,D,D,E},
            {D,D,D,D,D,E},
            {D,D,D,D,D,G}
           }
        str= "GEEKS"
Output :2
Input : a = {
            {B,B,M,B,B,B},
            {C,B,A,B,B,B},
            {I,B,G,B,B,B},
            {G,B,I,B,B,B},
            {A,B,C,B,B,B},
            {M,C,I,G,A,M}
            }
        str= "MAGIC"

Output :4
*/

#include <bits/stdc++.h>
using namespace std;

int helper(string s, vector<vector<char>> arr, int row, int col, int idx)
{
    int found = 0;
    if (row >= 0 and col >= 0 and row < arr.size() and col < arr[0].size() and arr[row][col] == s[idx])
    {
        char ch = s[idx];
        arr[row][col] = '0';
        idx++;

        if (idx == s.length())
        {
            found = 1;
        }
        else
        {
            found += helper(s, arr, row - 1, col, idx);
            found += helper(s, arr, row + 1, col, idx);
            found += helper(s, arr, row, col - 1, idx);
            found += helper(s, arr, row, col + 1, idx);
        }

        arr[row][col] = ch;
    }
    return found;
}

int countString(string s, vector<vector<char>> arr)
{
    int ans = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[0].size(); j++)
        {
            ans += helper(s, arr, i, j, 0);
        }
    }
    return ans;
}

int main()
{
    vector<vector<char>> arr = {
        {'B', 'B', 'M', 'B', 'B', 'B'},
        {'C', 'B', 'A', 'B', 'B', 'B'},
        {'I', 'B', 'G', 'B', 'B', 'B'},
        {'G', 'B', 'I', 'B', 'B', 'B'},
        {'A', 'B', 'C', 'B', 'B', 'B'},
        {'M', 'C', 'I', 'G', 'A', 'M'}};

    string s = "MAGIC";
    int ans = 0;
    cout<<countString(s, arr);
    return 0;
}