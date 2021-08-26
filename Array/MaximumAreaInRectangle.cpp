/*
Given a binary matrix. Find the maximum area of a rectangle formed only of 1s in the given matrix.

Example 1:

Input:
n = 4, m = 4
M[][] = {{0 1 1 0},
         {1 1 1 1},
         {1 1 1 1},
         {1 1 0 0}}
Output: 8
Explanation: For the above test case the
matrix will look like
0 1 1 0
1 1 1 1
1 1 1 1
1 1 0 0
the max size rectangle is 
1 1 1 1
1 1 1 1
and area is 4 *2 = 8.
*/

#include <bits/stdc++.h>
using namespace std;

//Same as Max Area in Histogram.
int calArea(vector<int> &arr)
{
    int n = arr.size();
    vector<int> left(n, 0), right(n, 0);
    stack<int> st;

    for (int i = 0; i < n; i++)
    {
        if (st.empty())
        {
            left[i] = 0;
            st.push(i);
        }
        else
        {
            while (!st.empty() and arr[st.top()] >= arr[i])
            {
                st.pop();
            }

            left[i] = st.empty() ? 0 : st.top() + 1;
            st.push(i);
        }
    }

    while (!st.empty())
    {
        st.pop();
    }

    for (int i = n - 1; i >= 0; i--)
    {
        if (st.empty())
        {
            right[i] = n - 1;
            st.push(i);
        }
        else
        {
            while (!st.empty() and arr[st.top()] >= arr[i])
            {
                st.pop();
            }

            right[i] = st.empty() ? n - 1 : st.top() - 1;
            st.push(i);
        }
    }

    int maxArea = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        int tempArea = arr[i] * (right[i] - left[i] + 1);
        maxArea = max(maxArea, tempArea);
    }
    return maxArea;
}

int maxArea(vector<vector<int>>M)
{
    int r = M.size();
    int c = M[0].size();

    vector<vector<int>> helper;
    //Filling the histogram Matrix.
    for (int i = 0; i < r; i++)
    {
        vector<int> temp;
        for (int j = 0; j < c; j++)
        {
            if (i == 0)
            {
                temp.push_back(M[i][j]);
            }
            else if (M[i][j] == 0)
            {
                temp.push_back(0);
            }
            else
            {
                int curr = M[i][j] + helper[i - 1][j];
                temp.push_back(curr);
            }
        }
        helper.push_back(temp);
    }

    int maxArea = INT_MIN;

    for (int i = 0; i < r; i++)
    {
        int tempArea = calArea(helper[i]);
        maxArea = max(maxArea, tempArea);
    }
    return maxArea;
}
int main()
{
    vector<vector<int>> M = {{0, 1, 1, 0},
                             {1, 1, 1, 1},
                             {1, 1, 1, 1},
                             {1, 1, 0, 0}};

    cout << maxArea(M);
    return 0;
}