/*
Given two strings X and Y, print the shortest string that has both X and Y as subsequences. If multiple shortest supersequence exists, print any one of them.
Examples: 
 

Input: X = "AGGTAB",  Y = "GXTXAYB"
Output: "AGXGTXAYB" OR "AGGXTXAYB" 
OR Any string that represents shortest
supersequence of X and Y

Input: X = "HELLO",  Y = "GEEK"
Output: "GEHEKLLO" OR "GHEEKLLO"
OR Any string that represents shortest 
supersequence of X and Y
*/

#include <bits/stdc++.h>
using namespace std;

string printSCS(string x, string y)
{
    int m = x.length();
    int n = y.length();

    int dp[m + 1][n + 1];

    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }

            else if (x[i - 1] == y[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }

            else
            {
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
    }

    int i = m;
    int j = n;
    string ans = "";

    while (i > 0 && j > 0)
    {
        if (x[i - 1] == y[j - 1])
        {
            ans += x[i - 1];
            i--;
            j--;
        }
        else if (dp[i][j - 1] > dp[i - 1][j])
        {
            ans += y[j - 1];
            j--;
        }   
        else
        {
            ans += x[i - 1];
            i--;
        }
    }

    while (i > 0)
    {
        ans += x[i - 1];
        i--;
    }

    while (j > 0)
    {
        ans += y[j - 1];
        j--;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    string x = "AGGTAB";
    string y = "GXTXAYB";
    cout << printSCS(x, y);
    return 0;
}