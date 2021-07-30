/*
Given an array arr[] consisting of N positive integers and a positive integer K, the task is to find the maximum sum of the subarray of size K such that it contains K consecutive elements in any combination.

Examples:

Input: arr[] = {10, 12, 9, 8, 10, 15, 1, 3, 2}, K = 3
Output: 27
Explanation:
The subarray having K (= 3) consecutive elements is {9, 8, 10} whose sum of elements is 9 + 8 + 10 = 27, which is maximum.

Input: arr[] = {7, 20, 2, 3, 4}, K = 2
Output: 7
*/

#include <bits/stdc++.h>
using namespace std;

int calSum(vector<int> arr, int k)
{
    int maxSum = INT_MIN;
    for (int i = 0; i < arr.size() - k; i++)
    {
        vector<int> duplicate(arr.begin() + i, arr.begin() + i + k);
        sort(duplicate.begin(), duplicate.end());

        bool flag = true;
        for (int j = 1; j < k; j++)
        {
            if (duplicate[j] - duplicate[j - 1] != 1)
            {
                flag = false;
                break;
            }
        }

        if (flag)
        {
            int currSum = 0;
            for (int j = 0; j < k; j++)
            {
                currSum += duplicate[j];
            }

            maxSum = max(currSum, maxSum);
        }
    }
    return maxSum;
}

int main()
{
    vector<int> arr = {10, 12, 9, 8, 10, 15, 1, 3, 2};
    int k = 3;

    int ans = calSum(arr, k);
    cout << ans;
}