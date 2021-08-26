/*
You are given an array prices where prices[i] is the price of a given stock on the ith day.
You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.
Example 1:

Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.
*/

#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> &prices)
{
    int profit = 0;
    int minCost = INT_MAX;

    for (int i = 0; i < prices.size(); i++)
    {
        if (prices[i] > minCost)
        {
            profit = max(profit, prices[i] - minCost);
        }
        minCost = min(minCost, prices[i]);
    }
    return profit;
}

int main()
{
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    cout << maxProfit(prices);

    return 0;
}

/*
Explaination:
/*
profit = 0
minCost = 1e9

        !
arr[] = 7, 1, 5, 3, 6, 4

7 > minCost --> NO
minCost = 7

           !
arr[] = 7, 1, 5, 3, 6, 4

1 > minCost --> NO
minCost = 1

              !
arr[] = 7, 1, 5, 3, 6, 4

5 > minCost -->Yes
--> profit = max(5 - minCost = 5 - 1 = 4, profit = 0) = 4
minCost = 1

                 !
arr[] = 7, 1, 5, 3, 6, 4

3 > minCost --> Yes
--> --> profit = max(3 - minCost = 3 - 1 = 2, profit = 4) = 4
minCost = 1
                    !
arr[] = 7, 1, 5, 3, 6, 4

6 > minCost --> Yes
--> profit = max(6 - minCost = 6 - 1 = 5, profit = 4) = 5
minCost = 1

                       !
arr[] = 7, 1, 5, 3, 6, 4
4 > minCost -->Yes
-->Profit = max(4 - minCost = 4 -1  = 3, profit = 5) = 5;
minCost = 1

                          !
arr[] = 7, 1, 5, 3, 6, 4

loop ends---> Profit = 5
------------------------------------------------*/