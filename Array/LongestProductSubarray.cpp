/*
Given an array Arr that contains N integers (may be positive, negative or zero). Find the product of the maximum product subarray.

Example 1:

Input:
N = 5
Arr[] = {6, -3, -10, 0, 2}
Output: 180
Explanation: Subarray with maximum product
is 6, -3, -10 which gives product as 180.
*/

#include <bits/stdc++.h>
using namespace std;

long long maxProduct(int arr[], int n)
{
    long long maxi = 1;
    long long mini = 1;
    long long ans = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > 0)
        {
            maxi = maxi * arr[i];
            mini = min(mini * arr[i], (long long)1);
        }
        else if (arr[i] < 0)
        {
            long long tempMin = mini;
            long long tempMax = maxi;

            maxi = max(tempMin * arr[i], (long long)1);
            mini = arr[i] * tempMax;
        }
        else
        {
            maxi = mini = 1;
            continue;
        }

        ans = max(ans, maxi);
    }
    return ans;
}

int main()
{
    int arr[] = {6, -3, -10, 0, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << maxProduct(arr, n);

    return 0;
}

/*
Explaination:
-->We will keep 2 variables, one that will store maximum positive value - MAXI and one with minimum negative value - MINI.
-->We will keep sure that MAXI, is always greater than equal to 1 and MINI is always less than equal to 1
-->Now there are 3 cases:
    ==>if arr[i] > 0, then MAXI is MAXI*arr[i], and MINI is min(MIN*arr[i], 1)
    ==>if arr[i] == 0, then we need to see for another subarray, and make MAXI = MINI = 1
    ==>if arr[i]<0, then MAXI becomes max(MINI*arr[i],1) and MINI becomes MAXI* arr[i]
-->For every iteration MAXI stores the maximum value so far, so keep another variable OVERALLMAX to store max of all MAXIs.
-->Print OVERALLMAX.
*/