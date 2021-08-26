/*
Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.
Example 1:
Input: heights = [2,1,5,6,2,3]
Output: 10
Explanation: The above is a histogram where width of each bar is 1.
The largest rectangle is shown in the red area, which has an area = 10 units.
*/

#include <bits/stdc++.h>
using namespace std;

int calAreaUtil(vector<int> heights, int curr)
{
    int i = curr;
    int j = curr;
    int n = heights.size() - 1;

    while (i > 0)
    {
        if (heights[i - 1] >= heights[curr])
        {
            i--;
        }
        else
        {
            break;
        }
    }
    while (j < n)
    {
        if (heights[j + 1] >= heights[curr])
        {
            j++;
        }
        else
        {
            break;
        }
    }

    return heights[curr] * (j - i + 1);
}

int maxAreaBruteForce(vector<int> &heights)
{
    int area = INT_MIN;
    for (int i = 0; i < heights.size(); i++)
    {
        int tempArea = calAreaUtil(heights, i);
        area = max(area, tempArea);
    }
    return area;
}

int maxArea(vector<int> &heights)
{
    int n = heights.size();
    vector<int> leftIdx(n, 0);
    vector<int> rightIdx(n, 0);
    stack<int> st;

    //Calculating left limit i.e left most idx having height >= curr height.
    for (int i = 0; i < n; i++)
    {
        if (st.empty())
        {
            leftIdx[i] = 0;
            st.push(i);
        }
        else
        {
            while (!st.empty() and heights[st.top()] >= heights[i])
            {
                st.pop();
            }
            leftIdx[i] = st.empty() ? 0 : st.top() + 1;
            st.push(i);
        }
    }

    while (!st.empty())
        st.pop();

    //Calculating right limit i.e right most idx having height >= curr height.
    for (int i = n - 1; i >= 0; i--)
    {
        if (st.empty())
        {
            st.push(i);
            rightIdx[i] = n - 1;
        }
        else
        {
            while (!st.empty() and heights[st.top()] >= heights[i])
            {
                st.pop();
            }
            rightIdx[i] = st.empty() ? n - 1 : st.top() - 1;
            st.push(i);
        }
    }

    int maxArea = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        int currArea = heights[i] * (rightIdx[i] - leftIdx[i] + 1);
        maxArea = max(maxArea, currArea);
    }
    return maxArea;
}

int main()
{
    vector<int> heights = {2, 1, 5, 6, 2, 3};
    cout << maxAreaBruteForce(heights);
    cout<<endl;
    cout<<maxArea(heights);
    return 0;
}